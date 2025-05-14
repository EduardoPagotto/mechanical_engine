#pragma once
#include "ecs.hpp"
#include "mechanical/gl/shader.hpp"
#include <memory>

namespace me {

struct ShaderComponent {
    TagInfo tag;
    std::shared_ptr<Shader> shader;
};

} // namespace me
