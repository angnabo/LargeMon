//
// Created by angelica on 05/01/18.
//

#include <SDL_events.h>
#include "main.h"
#include "LargeMonMainView.h"
int handleUP(int* selected){
    if (*selected == 0 || *selected == 1){

    } else if (*selected == 2){
        *selected = 0;
    } else {
        *selected = 1;
    }
    return *selected;
}

int handleDOWN(int* selected){
    if (*selected == 0){
        *selected = 2;
    } else if( *selected == 1){
        *selected = 3;
    }
    return *selected;
}


int handleRight(int* selected){
    if (*selected == 0){
        *selected = 1;

    } else if (*selected == 2){
        *selected = 3;
    }
    return *selected;
}

int handleLeft(int* selected){
    if (*selected == 1){
        *selected = 0;
    } else if (*selected == 3){
        *selected = 2;
    }
    return *selected;
}
int main( int argc, char* args[] ) {

    ControllerBattleInstance battleInstance;
    vector <string> arguments;
    arguments.push_back(battleInstance.getEnemyLargeMonName());
    arguments.push_back(to_string(battleInstance.getPlayerCurrentHp()));
    arguments.push_back(to_string(battleInstance.getEnemyCurrentHp()));

    LargeMonMainView view;
    view.run(arguments);

    int resetButton;
    int pressedButton;

    bool quit = false;


    //Event handler
    SDL_Event e;

            int selectedButton = 0;

            //While application is running
            while (!quit) {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0) {
                    //User requests quit
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                        //On keypress change rgb values
                    else if (e.type == SDL_KEYDOWN) {
                        switch (e.key.keysym.sym) {

                            //Handle LEFT key press
                            case SDLK_UP:
                                cout <<"up pressed ";
                                resetButton = selectedButton;
                                cout <<"to reset: " << resetButton;
                                pressedButton = handleUP(&selectedButton);
                                cout <<"pressed: " << pressedButton;
                                view.updateButtons(resetButton, pressedButton);
                                break;

                                //Handle RIGHT key press
                            case SDLK_RIGHT:
                                resetButton = selectedButton;
                                cout <<"to reset: " << resetButton;
                                pressedButton = handleRight(&selectedButton);
                                cout <<"pressed: " << pressedButton;
                                view.updateButtons(resetButton, pressedButton);
                                break;
                                //Handle UP key press
                            case SDLK_LEFT:
                                resetButton = selectedButton;
                                pressedButton = handleLeft(&selectedButton);
                                view.updateButtons(resetButton, pressedButton);
                                break;

                                //Handle DOWN key press
                            case SDLK_DOWN:
                                resetButton = selectedButton;
                                pressedButton = handleDOWN(&selectedButton);
                                view.updateButtons(resetButton, pressedButton);
                                break;

                        }
                        if(e.key.keysym.sym == SDLK_RETURN){

                            string textUpdate = "";
                            if(!battleInstance.isGameOver()) {
                                textUpdate = battleInstance.action(&selectedButton);
                                view.updateText(textUpdate);
                                view.updatePlayerHealthBar(battleInstance.getPlayerLargeMonCurrentHpPercent(),
                                                              to_string(battleInstance.getPlayerCurrentHp()));


                                view.updateEnemyHealthBar(battleInstance.getEnemyLargeMonCurrentHpPercent(),
                                                             to_string(battleInstance.getEnemyCurrentHp()));
                            } else {
                                //gBottomPanelFull.render(gRenderer, 10,0);
                                view.updateText(battleInstance.getWinner());
                                //gBottomTextPanel.free();
                                //SDL_RenderPresent(gRenderer);
                                //close();
                            }
                        }
                    }
                }
            }
    view.close();

    return 0;
}