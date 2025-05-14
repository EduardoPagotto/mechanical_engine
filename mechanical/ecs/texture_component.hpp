#pragma once
#include "ecs.hpp"
#include "mechanical/core/uniform_value.hpp"
#include "mechanical/gl/texture.hpp"
#include <memory>

namespace me {

using MapTex = std::unordered_map<std::string, std::shared_ptr<Texture>>;

struct TextureComponent {
    TagInfo tag;
    MapTex vTex;
};
} // namespace me
