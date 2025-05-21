#include "game.hpp"
#include "mechanical/core/events.hpp"
#include "mechanical/gl/OpenGLDefs.hpp"
#include "mechanical/gl/shader_manager.hpp"
#include <sstream>
#include <unordered_map>

Game::Game() : IStateMachine("Game") {

    using namespace me;
    // init framebuffer
    canvas = g_service_locator.getService<ICanva>();
    // init keyboard
    keyboard = g_service_locator.getService<IKeyboard>();
    evenMng = g_service_locator.getService<IEvent>();
}

Game::~Game() {

    canvas = nullptr;
    keyboard = nullptr;
}

void Game::onAttach() {

    glClearColor(0.f, 0.f, 0.f, 1.f); // Initialize clear color
    // Habilita o depth buffer/culling face
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);
    // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // TODO: implementar
}

void Game::onDeatach() {
    // TODO: implementar
}

bool Game::onEvent(const SDL_Event& event) {

    using namespace me;

    keyboard->getEvent(event);

    switch (event.type) {
        case SDL_EVENT_WINDOW_MOUSE_ENTER:
            evenMng->send(EventME::FLOW_RESUME, nullptr, nullptr); // isPaused = false;
            break;
        case SDL_EVENT_WINDOW_MOUSE_LEAVE:
            evenMng->send(EventME::FLOW_PAUSE, nullptr, nullptr); // isPaused = true;
            break;
    }
    return true;
}

void Game::onUpdate(const double& ts) {

    using namespace me;

    if (keyboard->isPressed(SDLK_ESCAPE)) {
        evenMng->send(EventME::FLOW_STOP, nullptr, nullptr);
        return;
    }

    if (keyboard->isPressed(SDLK_F10)) {
        evenMng->send(EventME::TOGGLE_FULL_SCREEN, nullptr, nullptr);
        return;
    }
}

void Game::onRender() {

    // TODO: Implementar
}
