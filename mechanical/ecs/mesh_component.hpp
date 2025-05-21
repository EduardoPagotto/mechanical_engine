#pragma once
#include "ecs.hpp"
#include "mechanical/space_3d/mesh.hpp"
#include <memory>

namespace me {

    struct MeshComponent {
        TagInfo tag;
        std::shared_ptr<Mesh> mesh;
    };
} // namespace me
