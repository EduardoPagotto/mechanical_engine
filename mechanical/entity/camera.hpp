#pragma once
// #include "chimera/core/ViewProjection.hpp"
#include "mechanical/core/types_base.hpp" //"chimera/core/TagComponent.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

namespace me {

// #define FPSCAMERA_MAX_SPEED 40.0f
// #define FPSCAMERA_ROTATION_SENSITIVITY 0.3f
// #define CAMERA_MAX_FOV 45.0f
// enum class CamKind { FPS = 0, ORBIT = 1, STATIC = 3 };

class Camera {
  protected:
    glm::vec3 position{glm::vec3(0, 0, 0)};
    glm::mat4 projection{glm::mat4(1.0f)};
    float near{0.1f}, far{1000.0f};

  public:
    const glm::mat4& getProjection() const { return projection; }
    const glm::vec3& getPosition() const { return position; }
    void setPosition(const glm::vec3& position) { this->position = position; }
    virtual void setViewportSize(const uint32_t& width, const uint32_t& height) = 0;
};

class CameraOrtho : public Camera {
  private:
    float xsize{0.0f}, ysize{0.0f}, xmag{800.0f}, ymag{600.0f};

  public:
    CameraOrtho(const float& xmag, const float& ymag, const float& near, const float& far) : xmag(xmag), ymag(ymag) {
        this->near = near;
        this->far = far;
    }

    virtual ~CameraOrtho() = default;

    virtual void setViewportSize(const uint32_t& width, const uint32_t& height) override {
        const float halfAspectRatio = ((float)width / (float)height) * 0.5f;
        xsize = xmag * halfAspectRatio;
        ysize = ymag * 0.5f;
        projection = glm::ortho(-xsize, xsize, -ysize, ysize, near, far);
    }

    const glm::vec2 getSize() const { return glm::vec2(xsize, ysize); }
};

class CameraPerspective : public Camera {
  private:
    float fov{45.0f};

  public:
    CameraPerspective(const float& fov, const float& near, const float& far) : fov(fov) {
        this->near = near;
        this->far = far;
    }

    virtual ~CameraPerspective() = default;

    virtual void setViewportSize(const uint32_t& width, const uint32_t& height) override {
        projection = glm::perspective(glm::radians(fov), (float)width / (float)height, near, far);
    }
};

struct CameraControllerFPS {
    // TagInfo tag;
    std::shared_ptr<Camera> cam;
    float pitch{0.0f}, yaw{90.0f};
    bool enable{false}; // primary
    bool fixed{false};  // fixedAspectRatio
    glm::vec3 up{glm::vec3(0, 1, 0)};
};

struct CameraComntrollerOrbit {
    std::shared_ptr<Camera> cam;
    float pitch{0.0f}, yaw{90.0f}, min{0.1f}, max{1000.0f};
    bool enable{false}; // primary
    glm::vec3 up{glm::vec3(0, 1, 0)};
};

struct CameraComponent {
    TagInfo tag;
    Camera* camera{nullptr};
    bool primary{true};
    bool fixedAspectRatio{false};
    // CamKind camKind = CamKind::STATIC;
    float pitch{0.0f}, yaw{90.0f}, min{0.5f}, max{1000.0f};
    glm::vec3 up{glm::vec3(0, 1, 0)};

    CameraComponent() = default;
    CameraComponent(const CameraComponent& o) = default;
};

// struct CameraComponent {
//     TagInfo tag;
//     Camera* camera{nullptr};
//     bool primary{true};
//     bool fixedAspectRatio{false};
//     // CamKind camKind = CamKind::STATIC;
//     float pitch{0.0f}, yaw{90.0f}, min{0.5f}, max{1000.0f};
//     glm::vec3 up{glm::vec3(0, 1, 0)};

//     CameraComponent() = default;
//     CameraComponent(const CameraComponent& o) = default;
// };
} // namespace me
