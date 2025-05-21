#pragma once
#include "ecs.hpp"
#include "mechanical/core/uniform_value.hpp"
#include <memory>

namespace me {

    struct MaterialComponent {
        TagInfo tag;
        MapUniform vMaterial; // listMaterial;
    };
} // namespace me
