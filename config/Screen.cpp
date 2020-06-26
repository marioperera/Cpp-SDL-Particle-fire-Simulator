//
// Created by mario_p on 6/26/2020.
//

#include "Screen.h"
#include <iostream>

using namespace std;
bool configs::Screen::init() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return false;
    }

    m_window = SDL_CreateWindow("Particle Fire Explosion",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                          SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (m_window == NULL) {
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1,
                                                SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                                             SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if(m_renderer == NULL) {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    if(m_texture == NULL) {
        cout << "Could not create texture" << endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

//    RED 0xFF0000FF
//    GREEN 0x00FF0000
//    BLUE 0x0000FFFF
//    YELLOW 0xFFFF00FF

    for (int i = 0; i <SCREEN_HEIGHT*SCREEN_WIDTH ; ++i) {
        m_buffer[i] =0xFFFFFFFF;
    }

    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);



    return true;
}

bool configs::Screen::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            return false;
        }
    }

    return true;
}


configs::Screen::Screen(): m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr) {

}

void configs::Screen::close() {
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
}
