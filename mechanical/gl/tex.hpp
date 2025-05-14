#pragma once
#include "mechanical/core/types_base.hpp"
#include "texture.hpp"
#include <memory>
#include <unordered_map>

namespace me {

using MapTex = std::unordered_map<std::string, std::shared_ptr<Texture>>;

struct Tex {
    TagInfo tag;
    MapTex vTex;
};
} // namespace me
