#pragma once
#include <SDL2/SDL.h>

namespace me {

/// @brief Events
const int32_t EVENT_TOGGLE_FULL_SCREEN = 0x0001; // FullScreem
const int32_t EVENT_FLOW_PAUSE = 0x0002;         // set to pause game
const int32_t EVENT_FLOW_RESUME = 0x0003;        // set to resume game
const int32_t EVENT_FLOW_STOP = 0x0004;          // run finalize game
const int32_t EVENT_NEW_FPS = 0x0005;            // OFF_COLLIDE
const int32_t EVENT_COLLIDE_IS_ALLOW = 0x1000;   // IS_ALLOW_COLLIDE
const int32_t EVENT_COLLIDE_START = 0x1001;      // START_COLLIDE
const int32_t EVENT_COLLIDE_ON = 0x1002;         // ON_COLLIDE
const int32_t EVENT_COLLIDE_OFF = 0x1003;        // OFF_COLLIDE

// // FIXME: usar smartpointers aqui no lugar de void*
// void utilSendEvent(const int32_t& user_event, void* _paramA, void* _paramB) {
//     SDL_Event event;
//     SDL_zero(event);
//     event.type = SDL_USEREVENT;
//     event.user.code = user_event;
//     event.user.data1 = _paramA;
//     event.user.data2 = _paramB;
//     if (SDL_PushEvent(&event) == -1) {
//         SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Critical PushEvent fail: %s", SDL_GetError());
//     }
// }

class Event : public ServiceBase<IEvent> {
  public:
    Event() noexcept = default;
    virtual ~Event() noexcept override = default;

    virtual void send(const int32_t& user_event, void* _paramA, void* _paramB) override {
        SDL_Event event;
        SDL_zero(event);
        event.type = SDL_USEREVENT;
        event.user.code = user_event;
        event.user.data1 = _paramA;
        event.user.data2 = _paramB;
        if (SDL_PushEvent(&event) == -1) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Critical PushEvent fail: %s", SDL_GetError());
        }
    }
};

} // namespace me
