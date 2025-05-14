#include "game.hpp"
#include "mechanical/core/engine.hpp"
#include "mechanical/gl/canvas_gl.hpp"
// #include "mechanical/core/joystick.hpp"
#include "mechanical/core/keyboard.hpp"
// #include "mechanical/core/mouse.hpp"
// #include "mechanical/core/pad.hpp"
#include "mechanical/gl/shader_manager.hpp"
#include "mechanical/gl/texture_manager.hpp"
#include "mechanical/persistence/persistence.hpp"
#include "mechanical/space_3d/transformation.hpp"
#include <config_params.hpp>
#include <iostream>
#include <string>

// ref: https://glusoft.com/sdl3-tutorials/use-opengl-shaders/

int main() {

    using namespace me;
    try {
        SDL_SetAppMetadata(std::string(project_name).c_str(), std::string(project_version).c_str(),
                           "com.mechanical.engine");

        SDL_SetLogPriorities(SDL_LOG_PRIORITY_DEBUG);
        SDL_Log("Simples Teste");

        // Services shared inside all parts
        g_service_locator.registerService(std::make_shared<Event>());
        g_service_locator.registerService(std::make_shared<Keyboard>());
        // g_service_locator.registerService(std::make_shared<Mouse>());
        // g_service_locator.registerService(std::make_shared<Joystick>());
        //  g_service_locator.registerService(std::make_shared<Pad>());
        g_service_locator.registerService(std::make_shared<ShaderMng>());
        g_service_locator.registerService(std::make_shared<TextureMng>());

        g_service_locator.registerService(std::make_shared<CanvasGL>("TESTE GL", 1920 / 2, 1080 / 2, false));

        {
            // cria luz e camera
        }

        { // New Object in 3d space with: transformations; mesh; material; texture; shade;
            // Main object
            Entity entity = Entity("Cubo01", "Cubo_01");

            // space transformations
            TransData& t = entity.addComponent<TransData>();
            t.trans = std::make_shared<Transformation>();

            // load Mesh, material, textura
            Persistence p;
            if (!p.loadObj("./assets/models/cubo2.obj", entity)) { // after register TextureMng
                SDL_Log("Falha na carga do OBJ");
                return -1;
            }

            // shade
            auto mng = me::g_service_locator.getService<me::ShaderMng>();

            std::unordered_map<uint32_t, std::string> shader_files;
            shader_files[GL_VERTEX_SHADER] = "./examples/template_gl/shades/vertex_shader.glsl";
            shader_files[GL_FRAGMENT_SHADER] = "./examples/template_gl/shades/blur_shader.glsl";

            ShaderData& shadeData = entity.addComponent<ShaderData>();
            shadeData.tag.name = "teste";
            shadeData.shader = mng->load("teste", shader_files);
        }

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
