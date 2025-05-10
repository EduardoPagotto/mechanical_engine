#pragma once

namespace me {

/// @brief EventsME
enum class EventME : int32_t {
    TOGGLE_FULL_SCREEN = 0x0001, // FullScreem
    FLOW_PAUSE = 0x0002,         // set to pause game
    FLOW_RESUME = 0x0003,        // set to resume game
    FLOW_STOP = 0x0004,          // run finalize game
    NEW_FPS = 0x0005,            // OFF_COLLIDE
    COLLIDE_IS_ALLOW = 0x1000,   // IS_ALLOW_COLLIDE
    COLLIDE_START = 0x1001,      // START_COLLIDE
    COLLIDE_ON = 0x1002,         // ON_COLLIDE
    COLLIDE_OFF = 0x1003,        // OFF_COLLIDE
};
} // namespace me
