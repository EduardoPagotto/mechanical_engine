#pragma once
#include <glm/glm.hpp>

namespace me {

    struct Triangle {
        bool splitter{false};
        glm::uvec3 idx{0};
        glm::vec3 normal{0.0};

        explicit Triangle(const Triangle& t) noexcept = default;

        explicit Triangle(const glm::uvec3& i, const glm::vec3& n, const bool& s) noexcept
            : idx(i), normal(n), splitter(s) {}
    };
} // namespace me
