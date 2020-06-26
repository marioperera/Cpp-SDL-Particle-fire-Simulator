#include <iostream>
#include <SDL.h>
#include "./config/Screen.h"

using namespace std;

int main(int argc, char* argv []) {

    configs::Screen screen;
    if(!screen.init()){
        cout<<"Error initializing SDL"<<endl;
    }

    bool quit = false;
    SDL_Event event;
    while (!quit){
        if (!screen.processEvents()) {
            break;
        }

    }
    screen.close();

    return 0;
}