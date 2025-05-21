#pragma once
#include "ecs.hpp"
#include "mechanical/core/uniform_value.hpp"
#include <memory>

namespace me {

    struct LightComponent {
        TagInfo tag;
        MapUniform vLight;
    };
} // namespace me
