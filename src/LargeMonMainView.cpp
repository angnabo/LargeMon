//
// Created by angelica on 11/11/17.
//

//#include "include/LargeMonMainView.h"
//Using SDL, SDL_image, standard IO, and strings
#include <ctime>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include "graphics/GTexture.h"
#include "graphics/GProgressBar.h"
#include "graphics/GButtonTexture.h"
#include "controller/ControllerBattleInstance.h"
#include "controller/FileWriter.h"
#include "../test/ControllerTest.cpp"
#include "../test/Test.h"


//Battle Instance Controller
ControllerBattleInstance battleInstance;
FileWriter * writer;



int main( int argc, char* args[] ) {

    Test test;
    test.test();


    return 0;
}