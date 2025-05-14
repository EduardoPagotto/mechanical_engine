#pragma once
#include "mechanical/core/types_base.hpp"
#include "mechanical/core/uniform_value.hpp"

namespace me {

struct Material {
    TagInfo tag;
    MapUniform vMaterial; // listMaterial;
};
} // namespace me
