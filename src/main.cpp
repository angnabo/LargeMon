//
// Created by angelica on 05/01/18.
//

#include <SDL_events.h>
#include "main.h"
#include "view/LargemonMainView.h"
#include "controller/Controller.h"

int main( int argc, char* args[] ) {

    Controller controller;
    LargemonMainView view;
    BattleInstance battle;
    int cont = controller.run(&view, &battle);
    while(true){
        BattleInstance battleInstance;
        controller.run(&view, &battleInstance);
    }





    return 0;
}