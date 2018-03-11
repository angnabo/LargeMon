//
// Created by angelica on 20/10/17.
//

#include <string>
#include <vector>
#include "Controller.h"
#include "../model/utility/DescriptGen.h"

Controller::Controller() {

    battleInstance = BattleInstance();

}

/**
 * Changes the colour of selected button, and unselects the no longer selected button
 * @param selected
 * @param event
 * @return
 */
int Controller::handleMenuKeyPress(MenuButton * selected, int event){
    switch (event){
        case SDLK_RIGHT:
            switch (*selected){
                case left:
                    *selected = right;
                    break;
                default:break;
            }
            return *selected;
        case SDLK_LEFT:
            switch (*selected){
                case right:
                    *selected = left;
                    break;
                default:break;
            }
            return *selected;
        default:break;
    }
}

/**
 * Changes the colour of selected button, and unselects the no longer selected button
 * @param selected
 * @param event
 * @return
 */
int Controller::handleKeyPress(Button * selected, int event){
    switch (event){
        case SDLK_UP:
            switch (*selected){
                case bottom_left :
                    *selected = top_left;
                    break;
                case bottom_right :
                    *selected = top_right;
                    break;
                default:break;
            }
            return *selected;
        case SDLK_RIGHT:
            switch (*selected){
                case top_left:
                    *selected = top_right;
                    break;
                case bottom_left:
                    *selected = bottom_right;
                    break;
                default:break;
            }
            return *selected;
        case SDLK_DOWN:
            switch (*selected){
                case top_left:
                    *selected = bottom_left;
                    break;
                case top_right:
                    *selected = bottom_right;
                    break;
                default:break;
            }
            return *selected;
        case SDLK_LEFT:
            switch (*selected){
                case top_right:
                    *selected = top_left;
                    break;
                case bottom_right:
                    *selected = bottom_left;
                    break;
                default:break;
            }
            return *selected;
        default:break;
    }
    return *selected;
}

int Controller::run() {

    int exitCode = 0;

    FileWriter writer = FileWriter(&battleInstance);
    battleInstance.attach(&writer);

    HealthObserver playerhp = HealthObserver(battleInstance.getPlayerPtr(), &view);
    HealthObserver enemyhp = HealthObserver(battleInstance.getEnemyPtr(), &view);

    setViewArguments();

    view.run(arguments);

    int pressedButton;
    Button selected = Button::top_left;

    bool quit = false;

    SDL_Event e{};
    while(!quit) {
        while (SDL_PollEvent(&e) != 0)  {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
                // handle key presses
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {

                    //Handle LEFT key press
                    case SDLK_UP:
                        pressedButton = handleKeyPress(&selected, SDLK_UP);
                        view.updateButtons(pressedButton);
                        break;
                        //Handle RIGHT key press
                    case SDLK_RIGHT:
                        pressedButton = handleKeyPress(&selected, SDLK_RIGHT);
                        view.updateButtons(pressedButton);
                        break;
                        //Handle DOWN key press
                    case SDLK_DOWN:
                        pressedButton = handleKeyPress(&selected, SDLK_DOWN);
                        view.updateButtons(pressedButton);
                        break;
                        //Handle UP key press
                    case SDLK_LEFT:
                        pressedButton = handleKeyPress(&selected, SDLK_LEFT);
                        view.updateButtons(pressedButton);
                        break;
                    default:
                        break;
                }
                if (e.key.keysym.sym == SDLK_RETURN) {
                    string textUpdate;
                    if (!battleInstance.isGameOver()) {
                        textUpdate = battleInstance.action(selected);
                        view.updateText(textUpdate);
                    }
                }
                if (battleInstance.isGameOver()) {
                    exitCode = menuPanel();
                    return exitCode;
                }
            }
        }
    }
    view.close();
}

int Controller::menuPanel(){

    view.menuPanel(battleInstance.getWinner());

    int pressedMenuButton;
    MenuButton selectedMenu = MenuButton::left;

    bool quit = false;

    //Event handler
    SDL_Event e{};
    while (!quit) {
        while (SDL_WaitEvent(&e) >= 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
                // handle key presses
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {

                    //Handle RIGHT key press
                    case SDLK_RIGHT:
                        pressedMenuButton = handleMenuKeyPress(&selectedMenu, SDLK_RIGHT);
                        view.updateMenuButtons(pressedMenuButton);
                        break;
                        //Handle LEFT key press
                    case SDLK_LEFT:
                        pressedMenuButton = handleMenuKeyPress(&selectedMenu, SDLK_LEFT);
                        view.updateMenuButtons(pressedMenuButton);
                        break;
                    default:
                        break;
                }
                if (e.key.keysym.sym == SDLK_RETURN) {
                    if (selectedMenu == MenuButton::left) {
                        return 2;
                    } else {
                        view.close();
                        return 0;
                    }
                }
                if (battleInstance.isGameOver()) {
                    view.menuPanel(battleInstance.getWinner());
                }
            }
        }
    }
}



void Controller::setViewArguments() {
    //view.

    DescriptGen descriptGen = DescriptGen();
    arguments.push_back(descriptGen.getDescription(battleInstance.getEnemyPtr()));
    arguments.push_back(to_string(battleInstance.getPlayerCurrentHp()));
    arguments.push_back(to_string(battleInstance.getEnemyCurrentHp()));
    arguments.push_back(getLargemonPath(battleInstance.getPlayerLargemonName()));
    arguments.push_back(getLargemonPath(battleInstance.getEnemyLargemonName()));
    arguments.push_back(getTypePath(battleInstance.getPlayerLargemonName()));
    arguments.push_back(getTypePath(battleInstance.getEnemyLargemonName()));
    arguments.push_back(descriptGen.getAttack(battleInstance.getPlayerPtr()->getType()));
    arguments.push_back(descriptGen.getAbility(battleInstance.getPlayerPtr()->getType()));

}

string Controller::getLargemonPath(string type) {
    string path;
    if(type == "fire troll"){
        path = "../resources/sprites/fire_troll_sprite_sheet.png";
    } else if(type == "water troll"){
        path = "../resources/sprites/water_troll_sprite_sheet.png";
    }else{
        path = "../resources/sprites/wood_troll_sprite_sheet.png";
    }
    return path;
}

string Controller::getTypePath(string type) {
    string path;
    if(type == "fire troll"){
        path = "../resources/ui/fire_type_icon.png";
    } else if(type == "water troll"){
        path = "../resources/ui/water_type_icon.png";
    }else{


        path = "../resources/ui/wood_type_icon.png";
    }
    return path;
}

void Controller::close() {
    view.close();
//    delete &battleInstance;
//    delete &view;
//    delete &arguments;
}

