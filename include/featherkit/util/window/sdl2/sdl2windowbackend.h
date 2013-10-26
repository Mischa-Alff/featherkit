#pragma once
#define NO_SDL_GLEXT
#include <featherkit/window/windowbackend.h>
#include <glm/glm.hpp>
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
//#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <memory>

namespace fea
{
    namespace util
    {
        class SDL2WindowBackend : public WindowBackend
        {
            public:
                SDL2WindowBackend();

                void create(VideoMode mode, const std::string& title, uint32_t style = Style::Default, const ContextSettings& settings = ContextSettings()) override;
                void close() override;
                bool isOpen() const override;
                const ContextSettings getSettings() const override;
                Vec2I getPosition() const override;
                void setPosition(int32_t x, int32_t y) override;
                Vec2I getSize() const override;
                void setSize(int32_t w, int32_t h) override;
                void setTitle(const std::string& title) override;
                void setIcon(uint32_t width, uint32_t height, const uint8_t* pixels) override;
                void setVisible(bool visible) override;
                void setVSyncEnabled(bool enabled) override;
                void setMouseCursorVisible(bool visible) override;
                void setFramerateLimit(uint32_t limit) override;

                bool setRenderingActive(bool active = true) const override;
                void swapBuffers() override;
				void lockCursor(bool lock) override;
                ~SDL2WindowBackend();
            private:
                SDL_Window* window;
				SDL_GLContext glContext;

        };
    }
}
