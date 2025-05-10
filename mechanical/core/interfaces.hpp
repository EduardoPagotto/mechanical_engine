#pragma once
#include "service_locator.hpp"
#include "types_base.hpp"
#include <SDL3/SDL.h>
#include <glm/glm.hpp>

namespace me {

/// @brief Canva Interface
/// @author <a href="mailto:edupagotto@gmail.com.com">Eduardo Pagotto</a>
/// @since 20130925
/// @date 20250401
class ICanva : public IService {
  public:
    virtual ~ICanva() = default;
    virtual void before() = 0;
    virtual void after() = 0;
    virtual void toggleFullScreen() = 0;
    virtual void reshape(int _width, int _height) = 0;
    virtual uint32_t* getPixels() = 0;
    virtual SDL_PixelFormat getPixelFormat() = 0;
    virtual const int getWidth() const = 0;
    virtual const int getHeight() const = 0;
};

/// @brief Mouse Interface
/// @author <a href="mailto:edupagotto@gmail.com.com">Eduardo Pagotto</a>
/// @since 20130925
/// @date 20250401
class IMouse : public IService {
  public:
    virtual ~IMouse() noexcept = default;
    virtual const bool getButtonState(const uint8_t& indice) noexcept = 0;
    virtual const glm::ivec2 getMove() const noexcept = 0;
    virtual const glm::ivec2 getMoveRel() noexcept = 0;
    virtual const bool getEvent(const SDL_Event& event) noexcept = 0;
    virtual void updateBt(const SDL_MouseButtonEvent& bt) noexcept = 0;
    virtual void updateMv(const SDL_MouseMotionEvent& mv) noexcept = 0;
    virtual void updateWl(const SDL_MouseWheelEvent& mwe) noexcept = 0;
};

/// @brief Keyboard Interface
/// @author <a href="mailto:edupagotto@gmail.com.com">Eduardo Pagotto</a>
/// @since 20130925
/// @date 20250401
class IKeyboard : public IService {
  public:
    virtual ~IKeyboard() noexcept = default;
    virtual void setDown(const SDL_KeyboardEvent& event) noexcept = 0;
    virtual void setUp(const SDL_KeyboardEvent& event) noexcept = 0;
    virtual const bool isPressed(const SDL_Keycode& key) noexcept = 0;
    virtual const bool isModPressed(const SDL_Keymod& keyMod) const noexcept = 0;
    virtual const bool getEvent(const SDL_Event& event) noexcept = 0;
};

/// @brief Joystic Interface
/// @author <a href="mailto:edupagotto@gmail.com.com">Eduardo Pagotto</a>
/// @since 20130925
/// @date 20250401
class IJoystick : public IService {
  public:
    virtual ~IJoystick() noexcept = default;
    virtual const bool getEvent(const SDL_Event& event) noexcept = 0;
    virtual SDL_Joystick* get(const SDL_JoystickID& joystick_id) noexcept = 0;
};

/// @brief Pad Interface
/// @author <a href="mailto:edupagotto@gmail.com.com">Eduardo Pagotto</a>
/// @since 20130925
/// @date 20250401
class IPad : public IService {
  public:
    virtual ~IPad() noexcept = default;
    virtual const bool getEvent(const SDL_Event& event) noexcept = 0;
    virtual SDL_Gamepad* get(const SDL_JoystickID& joystick_id) noexcept = 0;
};

class IEvent : public IService {
  public:
    virtual ~IEvent() noexcept = default;
    virtual void send(const EventME& user_event, void* _paramA, void* _paramB) = 0;
};

/// @brief State Machine Interface
/// @author <a href="mailto:edupagotto@gmail.com.com">Eduardo Pagotto</a>
/// @since 20130925
/// @date 20250401
class IStateMachine {
  public:
    IStateMachine(const std::string& name) : name(name) {}
    virtual ~IStateMachine() = default;
    virtual void onAttach() = 0;
    virtual void onDeatach() = 0;
    virtual void onRender() = 0;
    virtual void onUpdate(const double& ts) = 0;
    virtual bool onEvent(const SDL_Event& event) = 0;
    inline const std::string getName() const { return name; }

  private:
    std::string name;
};

} // namespace me
