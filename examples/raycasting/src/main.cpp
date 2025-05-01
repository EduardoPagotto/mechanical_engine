#include "game.hpp"
#include "mechanical/core/canvas_fb.hpp"
#include "mechanical/core/engine.hpp"
#include "mechanical/core/global.hpp"
#include "mechanical/core/keyboard.hpp"
#include <iostream>

int main(int argn, char** argv) {
    using namespace me;
    try {
        SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);
        SDL_Log("Simple ray-casting Iniciado");

        // Registry to entt
        // auto reg = std::make_shared<Registry>();

        // Services shared inside all parts
        // Canvas, Mouse, keyboard, Joystick, gamepad, view's
        g_service_locator.registerService(std::make_shared<Event>());
        g_service_locator.registerService(std::make_shared<Keyboard>());
        g_service_locator.registerService(std::make_shared<CanvasFB>("Raycasting", 1200, 800, false));
        // g_service_locator.registerService(std::make_shared<ViewProjection>()); // not used but necessary

        // Engine
        Engine engine;

        Game* game = new Game;

        engine.getStack().pushState(game);
        engine.run();

        SDL_Log("Loop de Game encerrado!!!!");
        delete game;
        SDL_Log("raycasting finalizado com sucesso");
        return 0;

    } catch (const std::string& ex) { SDL_Log("Falha grave: %s", ex.c_str()); } catch (...) {
        SDL_Log("Falha Desconhecida");
    }

    return -1;
}
