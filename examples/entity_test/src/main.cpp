#include "game.hpp"
#include "mechanical/core/engine.hpp"
#include "mechanical/gl/canvas_gl.hpp"
// #include "mechanical/core/joystick.hpp"
#include "mechanical/core/keyboard.hpp"
// #include "mechanical/core/mouse.hpp"
// #include "mechanical/core/pad.hpp"
#include "mechanical/ecs/camera_component.hpp"
#include "mechanical/ecs/light_component.hpp"
#include "mechanical/ecs/shader_component.hpp"
#include "mechanical/ecs/transformation_component.hpp"
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
        SDL_Log("entity teste");

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
            // New camera and light
            Entity entity = Entity("scene", "scene_01");

            // camera
            CameraComponent& c = entity.addComponent<CameraComponent>();
            c.cam = std::make_shared<CameraPerspective>(45.0f, 0.1, 1000.0f);
            c.cam->setPosition(glm::vec3(5.0f, 5.0f, 2.0f));
            c.type = CameraType::PERSPECTIVE;
            c.tag.name = "cam01";
            c.tag.id = "cam_01";
            c.up = glm::vec3(0.0f, 1.0f, 0.0f);
            c.min = 1.0f;
            c.max = 1500.0f;
            c.yaw = 0.0f;
            c.pitch = 0.0f;

            // light
            LightComponent l = entity.addComponent<LightComponent>();
            l.tag.name = "light1";
            l.tag.id = "light_01";
            l.vLight["light.diffuse"] = Uniform(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
            l.vLight["light.position"] = Uniform(glm::vec3(10.0f, 10.0f, 10.0f)); // FIXME: matrix ??
            l.vLight["light.ambient"] = Uniform(glm::vec4(0.9f, 0.9f, 0.9f, 1.0f));
        }

        { // New Object in 3d space with: transformations; mesh; material; texture; shade;
            // Main object
            Entity entity = Entity("Cubo01", "Cubo_01");

            // space transformations
            TransformationComponent& t = entity.addComponent<TransformationComponent>();
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

            ShaderComponent& shadeData = entity.addComponent<ShaderComponent>();
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
