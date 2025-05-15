#pragma once
#include "ecs.hpp"
#include "mechanical/space_3d/transformation.hpp"
#include <memory>

namespace me {

struct TransformationComponent {
    TagInfo tag;
    std::shared_ptr<ITransformation> trans;
};

} // namespace me
