#pragma once
#include <entt/entt.hpp>
#include <stdexcept>

namespace me {

struct TagInfo {
    std::string name = "";
    std::string id = "";
};

class Registry {

  private:
    entt::registry eRegistry;
    Registry(const Registry& other) = delete;

    Registry& operator=(const Registry& other) = delete;

  public:
    Registry() = default;

    virtual ~Registry() { destroy(); }

    void destroy() { eRegistry.clear(); }

    entt::registry& get() { return eRegistry; }

    // std::type_index getTypeIndex() const { return std::type_index(typeid(Registry)); }

    template <typename T>
    T& findComponent(const std::string& tag, bool isName = true) {
        auto view = eRegistry.view<T>();
        for (auto ent : view) {
            TagInfo& ee = eRegistry.get<TagInfo>(ent);
            if (isName) {
                if (ee.name == tag)
                    return eRegistry.get<T>(ent);
            } else {
                if (ee.id == tag)
                    return eRegistry.get<T>(ent);
            }
        }

        if (isName) {
            throw std::invalid_argument(std::string("name not found: ") + tag);
        } else {
            throw std::invalid_argument(std::string("id not found: ") + tag);
        }
    }
};

/// @brief Global access to Registry
inline Registry g_registry;
} // namespace me
