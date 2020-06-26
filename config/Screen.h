//
// Created by mario_p on 6/26/2020.
//

#ifndef SDL_APP_SCREEN_H
#define SDL_APP_SCREEN_H


#include <SDL.h>

namespace configs{
    class Screen {
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
    private:
        SDL_Window *m_window;
        SDL_Renderer * m_renderer;
        SDL_Texture * m_texture;
        uint32_t * m_buffer;

    public:
        Screen();

        Screen(SDL_Window *mWindow, SDL_Renderer *mRenderer, SDL_Texture *mTexture, uint32_t *mBuffer);

        bool init();
        bool processEvents();
        void close();
    };
}


#endif //SDL_APP_SCREEN_H
