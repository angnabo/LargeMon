//
// Created by angelica on 05/01/18.
//
#include "controller/Controller.h"
#include <SDL_mixer.h>

int main(int argc, char *args[]) {


    int cont = 2;
    while (cont == 2) {
        Controller replay;
        cont = replay.run();
        replay.close();
    }
    //Mix_FreeMusic(gMusic);
    return 0;
}