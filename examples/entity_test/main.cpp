#include "mechanical/core/entity.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <config_params.hpp>
#include <iostream>
#include <string>

class TesteZ1 {
  public:
    std::string nome;
    uint32_t idade;
};

class TesteZ2 {
  public:
    bool vivo;
    uint32_t idade;
};

int main() {

    using namespace me;
    try {
        SDL_SetAppMetadata(std::string(project_name).c_str(), std::string(project_version).c_str(),
                           "com.mechanical.engine");

        SDL_SetLogPriorities(SDL_LOG_PRIORITY_DEBUG);
        SDL_Log("Simples Teste");

        Entity teste = Entity("nova", "nova_id");
        { // teste
            teste.addComponent<TesteZ1>("edu", 55);
            teste.addComponent<TesteZ2>(true, 100);
            // std::cout << novo_al.nome << std::endl;
        }

        // auto& zz = g_registry.findComponent<TesteZ1>("nova");
        // auto& zx = g_registry.findComponent<TesteZ2>("nova");
        // std::cout << zz.nome << std::endl;

        auto group = g_registry.get().group<TesteZ1, TesteZ2>();
        for (auto entity : group) {
            auto [z1, z2] = group.get<TesteZ1, TesteZ2>(entity);

            std::cout << z1.nome << " " << z2.vivo << std::endl;
        }

        // delete game;
        SDL_Log("loop de Game encerrado com sucesso");
        return 0;
    } catch (const std::string& ex) { SDL_Log("%s", ex.c_str()); } catch (...) {
        SDL_Log("Falha Desconhecida");
    }

    return -1;
}
