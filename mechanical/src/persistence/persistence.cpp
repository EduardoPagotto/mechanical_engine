#include "mechanical/persistence/persistence.hpp"
#include "mechanical/ecs/material_component.hpp"
#include "mechanical/ecs/mesh_component.hpp"
#include "mechanical/ecs/texture_component.hpp"
#include "mechanical/gl/file_utils.hpp"
#include "mechanical/gl/texture_manager.hpp"
#include <SDL3/SDL.h>
#include <fstream>

namespace me {

    static glm::vec3 tokensToVec3(unsigned start, unsigned total, std::vector<std::string>& textData) {

        std::vector<float> arrayFloat;
        for (int indice = start; arrayFloat.size() < total; indice++) {
            if (textData[indice].size() > 0)
                arrayFloat.push_back(std::stod(textData[indice]));
        }

        return glm::vec3(arrayFloat[0], arrayFloat[1], arrayFloat[2]);
    }

    static glm::vec2 tokensToVec2(unsigned start, unsigned total, std::vector<std::string>& textData) {

        std::vector<float> arrayFloat;
        for (int indice = start; arrayFloat.size() < total; indice++) {
            if (textData[indice].size() > 0)
                arrayFloat.push_back(std::stod(textData[indice]));
        }

        return glm::vec2(arrayFloat[0], arrayFloat[1]);
    }

    static glm::vec4 tokensToVec4(std::vector<std::string>& textData) {
        std::vector<float> arrayFloat;
        for (int indice = 1; indice < textData.size(); indice++) {
            if (textData[indice].size() > 0)
                arrayFloat.push_back(std::stod(textData[indice]));
        }

        if (arrayFloat.size() < 4)
            return glm::vec4(arrayFloat[0], arrayFloat[1], arrayFloat[2], 1.0f);

        return glm::vec4(arrayFloat[0], arrayFloat[1], arrayFloat[2], arrayFloat[3]);
    }

    bool Persistence::loadObj(const std::string& pathfile, Entity entity) {

        Mesh& mesh = entity.addComponent<Mesh>();
        // mesh.tag.name = name; //TODO: recupersr nome da entidade e adicoinar -mesh com name
        // mesh.tag.id = id;

        std::ifstream file(pathfile);

        if (!file.is_open()) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "persistence could not open file: %s", pathfile.c_str());
            return false;
        }

        std::vector<int> indicesComp;
        std::string lineBuffer;
        std::vector<glm::vec3> point;
        std::vector<glm::vec3> normal;
        std::vector<glm::vec2> uv;

        std::string fileMath = ""; //  FIXME: nome do material ????

        while (std::getline(file, lineBuffer)) {
            std::string first = lineBuffer.substr(0, 1);
            if (first == "#")
                continue;

            std::vector<std::string> textData;
            textToStringArray(lineBuffer, textData, ' ');

            if (textData.size() == 0)
                continue;

            if (textData[0] == "mtllib") {
                fileMath = textData[1];
            } else if (textData[0] == "v")
                point.push_back(tokensToVec3(1, 3, textData));
            else if (textData[0] == "vt")
                uv.push_back(tokensToVec2(1, 2, textData));
            else if (textData[0] == "vn")
                normal.push_back(tokensToVec3(1, 3, textData));
            else if (textData[0] == "f") {
                int face = 0;
                for (int indice = 1; indice < textData.size(); indice++) {
                    if (textData[indice].size() > 0) {
                        std::vector<std::string> ss;
                        if (face > 8)
                            break;

                        textToStringArray(textData[indice], ss, '/');
                        for (std::string cc : ss) {
                            if (cc.size() > 0) {
                                indicesComp.push_back(std::stod(cc) - 1);
                                face++;
                            }
                        }
                    }
                }
            }
        }

        std::vector<std::string> semantics;
        semantics.push_back("VERTEX"); // 0

        if (uv.size() > 0)
            semantics.push_back("TEXCOORD"); // 1

        if (normal.size() > 0)
            semantics.push_back("NORMAL"); // 2

        std::vector<uint32_t> iPoint;
        std::vector<uint32_t> iNormal;
        std::vector<uint32_t> iUv;

        for (uint32_t l_contador = 0; l_contador < indicesComp.size(); l_contador++) {

            uint32_t index = l_contador % semantics.size();
            const std::string& semantic = semantics[index];

            if (semantic == "VERTEX")
                iPoint.push_back(indicesComp[l_contador]);
            else if (semantic == "NORMAL")
                iNormal.push_back(indicesComp[l_contador]);
            else if (semantic == "TEXCOORD")
                iUv.push_back(indicesComp[l_contador]);
        }

        for (uint32_t face = 0; face < iPoint.size(); face++) {
            mesh.vVertex.push_back({point[iPoint[face]],                                     // point
                                    normal[iNormal[face]],                                   // normal
                                    (uv.size() > 0) ? uv[iUv[face]] : glm::vec2(0.0, 0.0)}); // UV se nao existir zeros
        }

        mesh.vFaces.push_back(std::vector<glm::uvec3>());
        for (uint32_t i = 0; i < iPoint.size(); i += 3)
            mesh.vFaces[0].push_back({i, i + 1, i + 2});

        file.close();

        if (fileMath.size() > 0) {
            return this->loadMtl(fileMath, entity);
        }

        return true;
    }

    bool Persistence::loadMtl(const std::string& pathfile, Entity entity) {

        // //void wavefrontMtlLoad(const std::string& path, Material* material) {
        std::ifstream file(pathfile);

        if (!file.is_open()) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "persistence could not open file: %s", pathfile.c_str());
            return false;
        }

        MaterialComponent& material = entity.addComponent<MaterialComponent>();
        // material.tag.name = "mat01";
        // material.tag.id = "mat01-id";

        TextureComponent& tex = entity.addComponent<TextureComponent>();
        // tex.tag.name = "texname";
        // tex.tag.id = "texid";

        std::string lineBuffer;
        while (std::getline(file, lineBuffer)) {
            std::string first = lineBuffer.substr(0, 1);
            if (first == "#")
                continue;

            std::vector<std::string> textData;
            textToStringArray(lineBuffer, textData, ' ');

            if (textData.size() == 0)
                continue;

            if (textData[0] == "Ka") {
                material.vMaterial["material.ambient"] = Uniform(tokensToVec4(textData)); // AMBIENT
            } else if (textData[0] == "Kd") {
                material.vMaterial["material.diffuse"] = Uniform(tokensToVec4(textData)); // DIFFUSE
            } else if (textData[0] == "Ks") {
                material.vMaterial["material.specular"] = Uniform(tokensToVec4(textData)); // SPECULAR
            } else if (textData[0] == "map_Kd") {
                auto texMng = g_service_locator.getService<TextureMng>();

                tex.vTex["SHADE_TEXTURE_DIFFUSE"] = texMng->loadFromFile(textData[1], textData[1], TexParam());

            } else if (textData[0] == "sharpness") {
                material.vMaterial["material.shininess"] = Uniform(static_cast<float>(std::stod(textData[1])));
            }
        }

        return true;
    }
} // namespace me
