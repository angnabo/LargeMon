//
// Created by angelica on 05/01/18.
//
#include "controller/Controller.h"

int main(int argc, char *args[]) {

    // run the game until the user exits
    int cont = 2;
    while (cont == 2) {
        Controller replay;
        cont = replay.run();
        replay.close();
    }
    return 0;
}