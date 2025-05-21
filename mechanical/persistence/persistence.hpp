#pragma once
#include "mechanical/ecs/entity.hpp"
#include <string>
// #include "chimera/core/gl/Material.hpp"
// #include "chimera/core/visible/Mesh.hpp"

namespace me {

    class Persistence {

      public:
        Persistence() = default;
        virtual ~Persistence() = default;
        bool loadObj(const std::string& pathfile, Entity entity);
        bool loadMtl(const std::string& pathfile, Entity entity);
    };

    // void wavefrontObjLoad(const std::string& path, Mesh* mesh, std::string& fileMath);
    // void wavefrontMtlLoad(const std::string& path, Material* material);
} // namespace me
