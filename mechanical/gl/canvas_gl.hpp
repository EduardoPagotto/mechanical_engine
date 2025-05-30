#pragma once
#include "mechanical/core/interfaces.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define GLEW_STATIC

namespace me {
class CanvasGL : public ServiceBase<ICanva> {
  protected:
    std::string title;
    int width, height;
    bool fullScreen{false};
    int posX, posY;

    SDL_Window* window{nullptr};
    SDL_GLContext context;

  public:
    CanvasGL(const std::string& title, int width, int height, bool fullScreen = false);
    virtual ~CanvasGL();

    virtual void before() override;
    virtual void after() override;
    virtual void toggleFullScreen() override;
    virtual void reshape(int _width, int _height) override;
    virtual uint32_t* getPixels() override { return nullptr; }
    virtual const int getWidth() const override { return width; }
    virtual const int getHeight() const override { return height; }

    SDL_PixelFormat getPixelFormat() override { return SDL_PIXELFORMAT_ABGR8888; }
};
} // namespace me
