#pragma once
#include "ecs.hpp"
#include "mechanical/gl/texture.hpp"
#include <vector>

namespace me {

    struct FBSpec {
        TagInfo tag;
        uint32_t width = 800, height = 600;
        std::vector<TexParam> attachments;
    };
} // namespace me
