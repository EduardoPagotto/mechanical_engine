#pragma once
#include "ecs.hpp"
#include "mechanical/core/camera.hpp"
#include <memory>

namespace me {

struct CameraComponent {
    TagInfo tag;
    std::shared_ptr<Camera> cam;
    CameraType type{CameraType::PERSPECTIVE};
    float pitch{0.0f}, yaw{90.0f}, min{0.1f}, max{1000.0f};
    bool enable{false}; // primary
    bool fixed{false};  // fixedAspectRatio
    glm::vec3 up{glm::vec3(0, 1, 0)};
};
} // namespace me
