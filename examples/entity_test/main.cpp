#include "mechanical/ecs/camera_component.hpp"
#include "mechanical/ecs/entity.hpp"
#include "mechanical/ecs/mesh_component.hpp"
#include "mechanical/entity/material.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <config_params.hpp>
#include <iostream>
#include <string>

int main() {

    using namespace me;
    try {
        SDL_SetAppMetadata(std::string(project_name).c_str(), std::string(project_version).c_str(),
                           "com.mechanical.engine");

        SDL_SetLogPriorities(SDL_LOG_PRIORITY_DEBUG);
        SDL_Log("Simples Teste");

        Entity eObj2 = Entity("Obj_02", "Obj_02");
        CameraComponent& crt1 = eObj2.addComponent<CameraComponent>();
        crt1.cam = std::make_shared<CameraOrtho>(100.0f, 100.0f, 0.1f, 100.0f);
        crt1.type = CameraType::ORTHO;
        crt1.up = glm::vec3(0, -1, 0);
        crt1.yaw = 90.0f;
        crt1.pitch = 0.0f;
        crt1.enable = true; // primary
        crt1.fixed = false;

        Entity eObj = Entity("Obj_01", "Obj_01");
        CameraComponent& crt2 = eObj.addComponent<CameraComponent>();
        crt2.cam = std::make_shared<CameraPerspective>(45.0f, 0.1f, 100.0f);
        crt2.type = CameraType::PERSPECTIVE;
        crt2.up = glm::vec3(0, -1, 0);
        crt2.yaw = 90.0f;
        crt2.pitch = 0.0f;
        crt2.enable = true; // primary
        crt2.min = 0.1f;
        crt2.max = 1000.0f;

        Entity eObj3 = Entity("Obj_03", "Obj_03");
        { // teste
            Mesh& mesh = eObj.addComponent<Mesh>();
            mesh.tag.name = "Zoltan";
            mesh.tag.id = "Zoltan-id-01";

            Material& mat = eObj.addComponent<Material>();
            mat.tag.name = "mat01";
            mat.tag.id = "mat01-id";
            mat.vMaterial["material.difuse"] = Uniform(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
            mat.vMaterial["material.emission"] = Uniform(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
            mat.vMaterial["material.ambient"] = Uniform(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
            mat.vMaterial["material.specular"] = Uniform(glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
            mat.vMaterial["material.shine"] = Uniform(10);

            // Tex& tex = eObj.addComponent<Tex>();
            // tex.tag.name = "texture_01";
            // tex.tag.id = "texture_id_0";
            // tex.width = 200;
            // tex.height = 200;
            // tex.idTexture = 1;
            // tex.texParam = TexParam();
        }

        // auto group = g_registry.get().group<Mesh3d, Material>();
        // for (auto entity : group) {
        //     const auto [z1, z2] = group.get<Mesh3d, Material>(entity);
        //     std::cout << z1.tag.name << " " << z2.tag.name < < < < std::endl;
        // }

        auto entityID = g_registry.findEntity("Obj_01");
        Entity eObjteste(entityID);
        {
            auto hhh = eObjteste.getComponent<Material>();
            std::cout << hhh.tag.name << std::endl;
        }

        for (auto entityz1 : g_registry.get().view<entt::entity>()) {
            Entity entity(entityz1);
            auto& tc = entity.getComponent<TagInfo>();
            SDL_Log("Tag: %s Id: %s", tc.name.c_str(), tc.id.c_str());

            if (entity.hasComponent<Material>()) {
                auto& hhh = entity.getComponent<Material>();
                std::cout << hhh.tag.name << std::endl;
            }
        }

        // delete game;
        SDL_Log("loop de Game encerrado com sucesso");
        return 0;
    } catch (const std::string& ex) { SDL_Log("%s", ex.c_str()); } catch (...) {
        SDL_Log("Falha Desconhecida");
    }

    return -1;
}
