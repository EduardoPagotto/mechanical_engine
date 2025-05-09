#include "game.hpp"
#include "mechanical/core/engine.hpp"
#include "mechanical/gl/canvas_gl.hpp"
// #include "mechanical/core/joystick.hpp"
#include "mechanical/core/keyboard.hpp"
// #include "mechanical/core/mouse.hpp"
// #include "mechanical/core/pad.hpp"
#include <config_params.hpp>
#include <iostream>
#include <string>

int main() {

    using namespace me;
    try {
        SDL_SetAppMetadata(std::string(project_name).c_str(), std::string(project_version).c_str(),
                           "com.mechanical.engine");

        SDL_SetLogPriorities(SDL_LOG_PRIORITY_DEBUG);
        SDL_Log("Simples Teste");

        // Services shared inside all parts
        // Canvas, Mouse, keyboard, Joystick, gamepad, view's
        g_service_locator.registerService(std::make_shared<Event>());
        g_service_locator.registerService(std::make_shared<Keyboard>());
        // g_service_locator.registerService(std::make_shared<Mouse>());
        // g_service_locator.registerService(std::make_shared<Joystick>());
        //  g_service_locator.registerService(std::make_shared<Pad>());
        g_service_locator.registerService(std::make_shared<CanvasGL>("TESTE GL", 1920 / 2, 1080 / 2, false));

        // Engine
        Engine engine;

        Game* game = new Game;

        engine.getStack().pushState(game);
        engine.run();

        // delete game;
        SDL_Log("loop de Game encerrado com sucesso");
        return 0;
    } catch (const std::string& ex) { SDL_Log("%s", ex.c_str()); } catch (...) {
        SDL_Log("Falha Desconhecida");
    }

    return -1;
}
