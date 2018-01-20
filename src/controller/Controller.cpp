//
// Created by angelica on 20/10/17.
//

#include <string>
#include <vector>
#include "Controller.h"

Controller::Controller() {

}


int Controller::handleKeyPress(int* selected, int event){
    switch (event){
        case SDLK_UP:{
            switch (*selected){
                case 2:
                    *selected = 0;
                    break;
                case 3:
                    *selected = 1;
                    break;
                default:break;
            }
            return *selected;
        }
        case SDLK_RIGHT:{
            switch (*selected){
                case 0:
                    *selected = 1;
                    break;
                case 2:
                    *selected = 3;
                    break;
                default:break;
            }
            return *selected;
        }
        case SDLK_DOWN:{
            switch (*selected){
                case 0:
                    *selected = 2;
                    break;
                case 1:
                    *selected = 3;
                    break;
                default:break;
            }
            return *selected;
        }
        case SDLK_LEFT:{
            switch (*selected){
                case 1:
                    *selected = 0;
                    break;
                case 3:
                    *selected = 2;
                    break;
                default:break;
            }
            return *selected;
        }
        default:break;
    }
    return *selected;
}

void Controller::run() {

    FileWriter writer = FileWriter(&battleInstance);
    battleInstance.attach(&writer);

    HealthObserver playerhp = HealthObserver(battleInstance.getPlayerPtr(), &view);
    HealthObserver enemyhp = HealthObserver(battleInstance.getEnemyPtr(), &view);

    setViewArguments();

    view.run(arguments);

    int pressedButton;
    int selectedButton = 0;

    bool quit = false;

    //Event handler
    SDL_Event e{};
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
                        pressedButton = handleKeyPress(&selectedButton, SDLK_UP);
                        view.updateButtons(pressedButton);
                        break;
                        //Handle RIGHT key press
                    case SDLK_RIGHT:
                        pressedButton = handleKeyPress(&selectedButton, SDLK_RIGHT);
                        view.updateButtons(pressedButton);
                        break;
                        //Handle DOWN key press
                    case SDLK_DOWN:
                        pressedButton = handleKeyPress(&selectedButton, SDLK_DOWN);
                        view.updateButtons(pressedButton);
                        break;
                        //Handle UP key press
                    case SDLK_LEFT:
                        pressedButton = handleKeyPress(&selectedButton, SDLK_LEFT);
                        view.updateButtons(pressedButton);
                        break;

                    default:break;
                }
                if(e.key.keysym.sym == SDLK_RETURN){

                    string textUpdate;
                    if(!battleInstance.isGameOver()) {
                        textUpdate = battleInstance.action(&selectedButton);
                        view.updateText(textUpdate);
                        //view.updatePlayerHealthBar(battleInstance.getPlayerLargeMonCurrentHpPercent(),
                                                   //to_string(battleInstance.getPlayerCurrentHp()));


                        //view.updateEnemyHealthBar(battleInstance.getEnemyLargeMonCurrentHpPercent(),
                                                  //to_string(battleInstance.getEnemyCurrentHp()));
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

}

void Controller::setViewArguments() {
    //view.
    arguments.push_back(battleInstance.getEnemyLargeMonName());
    arguments.push_back(to_string(battleInstance.getPlayerCurrentHp()));
    arguments.push_back(to_string(battleInstance.getEnemyCurrentHp()));
    arguments.push_back(getLargemonSpritePath(battleInstance.getPlayerLargeMonName()));
    arguments.push_back(getLargemonSpritePath(battleInstance.getEnemyLargeMonName()));
}

string Controller::getLargemonSpritePath(string type) {
    string path;
    if(type == "Fire Troll"){
        path = "/home/angelica/Development/CLion/LargeMon/resources/sprites/fire_troll_sprite_sheet.png";
    } else if(type == "Water Troll"){
        path = "/home/angelica/Development/CLion/LargeMon/resources/sprites/water_troll_sprite_sheet.png";
    }else{
        path = "/home/angelica/Development/CLion/LargeMon/resources/sprites/wood_troll_sprite_sheet.png";
    }
    return path;
}
