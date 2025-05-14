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

    // auto mng = me::g_service_locator.getService<me::ShaderMng>();

    // std::unordered_map<uint32_t, std::string> shader_files;
    // shader_files[GL_VERTEX_SHADER] = "./examples/template_gl/shades/vertex_shader.glsl";
    // shader_files[GL_FRAGMENT_SHADER] = "./examples/template_gl/shades/blur_shader.glsl";

    // std::shared_ptr<me::Shader> shade = mng->load("teste", shader_files);

    // uint32_t shader_val = me::load_shader("qqq", mFiles);

    // std::stringstream s;
    // s << "Valor: " << shade->getID() << std::endl;
    // SDL_Log("%s", s.str().c_str());
    //  SDL_LogError(SDL_LOG_CATEGORY_GPU, "%s", s.str().c_str());
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
