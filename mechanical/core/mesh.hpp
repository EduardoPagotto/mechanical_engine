#pragma once
#include "types_base.hpp"
#include <glm/glm.hpp>
#include <vector>

namespace me {

using TrisIndex = std::vector<glm::uvec3>;

struct Vertex3d {
    glm::vec3 point;  // 3 * 4 = 12 ( 0 - 11)
    glm::vec3 normal; // 3 * 4 = 12 (12 - 23)
    glm::vec2 uv;     // 2 * 4 = 08 (24 - 31)
};

enum class MeshType { SINGLE = 0, ARRAY = 1, TREE = 2 };

struct Mesh3d {
    TagInfo tag;
    MeshType type{MeshType::SINGLE};
    std::vector<Vertex3d> vVertex; // TrisIndex iFace; antigo!!!
    std::vector<TrisIndex> vFaces;
};

// struct MeshComponent {
//     TagComponent tag;
//     MeshType type = MeshType::SINGLE;
//     Mesh* mesh = new Mesh();
//     std::vector<TrisIndex> vTrisIndex;
//     MeshComponent() = default;
// };

// MeshType getMeshTypeFromString(const std::string& text);
// void meshToTriangle(Mesh& m, std::list<std::shared_ptr<Triangle>>& vTris);
// void meshReindex(Mesh& inData, Mesh& outData);
// void meshDebug(const Mesh& m, bool _showAll);
// void meshSerialize(Mesh& inData, Mesh& outData);
// void idxSimplifieVec3(std::vector<glm::vec3>& in, std::vector<glm::vec3>& out, std::vector<uint32_t>& idxIn,
//                       std::vector<uint32_t>& idxOut);
// void idxSimplifieVec2(std::vector<glm::vec2>& in, std::vector<glm::vec2>& out, std::vector<uint32_t>& idxIn,
//                       std::vector<uint32_t>& idxOut);

// std::tuple<glm::vec3, glm::vec3, glm::vec3> vertexBoundaries(std::vector<VertexData>& vArray);
// std::tuple<glm::vec3, glm::vec3, glm::vec3> vertexIndexedBoundaries(std::vector<VertexData>& vArray, TrisIndex&
// tris);

} // namespace me
