#pragma once
#include "interfaces.hpp"
#include <SDL3/SDL.h>

namespace me {

class Event : public ServiceBase<IEvent> {
  public:
    Event() noexcept = default;
    virtual ~Event() noexcept override = default;

    virtual void send(const EventME& user_event, void* _paramA, void* _paramB) override {
        SDL_Event event;
        SDL_zero(event);
        event.type = SDL_EVENT_USER;
        event.user.code = static_cast<Sint32>(user_event);
        event.user.data1 = _paramA;
        event.user.data2 = _paramB;
        if (SDL_PushEvent(&event) == false) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Critical PushEvent fail: %s", SDL_GetError());
        }
    }
};
} // namespace me
