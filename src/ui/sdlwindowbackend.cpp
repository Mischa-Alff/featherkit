#include <fea/ui/sdlwindowbackend.hpp>
#include <cstdlib>
#define NO_SDL_GLEXT
#include <SDL/SDL.h>

namespace fea
{
    SDLWindowBackend::SDLWindowBackend() : mWindow(nullptr)
    {
        SDL_Init(SDL_INIT_VIDEO);
    }

    void SDLWindowBackend::create(VideoMode mode, const std::string& title, uint32_t style, const ContextSettings& settings)
    {
        //todo: fix style and version
        (void) style;
        (void) settings;
        mWindow = SDL_SetVideoMode((int32_t)mode.mWidth, (int32_t)mode.mHeight, (int32_t)mode.mBitDepth, SDL_OPENGL | SDL_RESIZABLE);
        SDL_WM_SetCaption(title.c_str(), nullptr);
    }

    void SDLWindowBackend::close()
    {
        SDL_Quit();
        mWindow = nullptr;
    }

    bool SDLWindowBackend::isOpen() const
    {
        return mWindow != nullptr;
    }

    const ContextSettings SDLWindowBackend::getSettings() const
    {
        //settings not finalized;
        return ContextSettings();
    }

    Vec2I SDLWindowBackend::getPosition() const
    {
        //not sure
        //SDL_getenv("SDL_VIDEO_WINDOW_POS");
        return Vec2I();
    }

    void SDLWindowBackend::setPosition(int32_t x, int32_t y)
    {
        (void)x;
        (void)y;
        //not sure
        //std::stringstream ss;
        //ss << "SDL_VIDEO_WINDOW_POS=" << x << ", " << y;
        //SDL_putenv(ss.str());
    }

    Vec2I SDLWindowBackend::getSize() const
    {
        //not sure
        return Vec2I();
    }

    void SDLWindowBackend::setSize(int32_t w, int32_t h)
    {
        mWindow = SDL_SetVideoMode(w, h, 32, SDL_OPENGL | SDL_RESIZABLE);
    }

    void SDLWindowBackend::setTitle(const std::string& title)
    {
        SDL_WM_SetCaption(title.c_str(), nullptr);
    }

    void SDLWindowBackend::setIcon(uint32_t width, uint32_t height, const uint8_t* pixels)
    {
        //should be fixed
        (void)width;
        (void)height;
        SDL_WM_SetCaption("shouldbetitle", (char*)pixels);
    }

    void SDLWindowBackend::setVisible(bool visible)
    {
        //should be fixed
        (void) visible;
    }

    void SDLWindowBackend::setVSyncEnabled(bool enabled)
    {
        //should be fixed
        (void) enabled;
    }

    void SDLWindowBackend::setMouseCursorVisible(bool visible)
    {
        //should be fixed
        (void)visible;
    }

    void SDLWindowBackend::setFramerateLimit(uint32_t limit)
    {
        //should be fixed
        (void)limit;
    }

    bool SDLWindowBackend::setRenderingActive(bool active) const
    {
        //should be fixed
        (void)active;
        return true;
    }

    void SDLWindowBackend::swapBuffers()
    {
        SDL_GL_SwapBuffers();
    }

    void SDLWindowBackend::lockCursor(bool lock)
    {
        (void)lock;
    }

    SDLWindowBackend::~SDLWindowBackend()
    {
    }
}
