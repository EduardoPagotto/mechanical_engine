#pragma once
#include "mechanical/core/interfaces.hpp"

class Game : public me::IStateMachine {

    std::shared_ptr<me::ICanva> canvas;
    std::shared_ptr<me::IKeyboard> keyboard;
    std::shared_ptr<me::IEvent> evenMng;

  public:
    Game();
    virtual ~Game();

    // Inherited via IEvents
    virtual void onAttach() override;
    virtual void onDeatach() override;
    virtual void onRender() override;
    virtual void onUpdate(const double& ts) override;
    virtual bool onEvent(const SDL_Event& event) override;
};
