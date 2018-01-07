//
// Created by angelica on 05/01/18.
//

#include <SDL_events.h>
#include "main.h"
#include "view/LargeMonMainView.h"
#include "controller/Controller.h"

int main( int argc, char* args[] ) {

    Controller controller;
    controller.run();


    return 0;
}