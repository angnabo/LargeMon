//
// Created by angelica on 05/01/18.
//

#include <SDL_events.h>
#include "main.h"
#include "view/LargemonMainView.h"
#include "controller/Controller.h"

int main(int argc, char *args[]) {

    //Controller controller;
    //Controller * prev = &controller;
    int cont = 2;
    while (cont == 2) {
        //prev->close();
        Controller replay;
        cont = replay.run();
        replay.close();
        //prev = &replay;
    }

    return 0;
}