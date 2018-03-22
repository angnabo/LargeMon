//
// Created by angelica on 20/10/17.
//
#include "../model/BattleInstance.h"
#include "../view/MainView.h"
#include "../model/observer/HealthBarObserver.h"
#include <iostream>
#include <string>
#include <vector>

#ifndef LARGEMON_CONTROLLER_H
#define LARGEMON_CONTROLLER_H

using namespace std;

class Controller {
public:
    enum ButtonEnum {
        top_left = 0,
        top_right = 1,
        bottom_left = 2,
        bottom_right = 3
    };

    enum MenuButtonEnum {
        left = 0,
        right = 1,
    };
    Controller();
    void close();
    int run();
    int handleKeyPress(ButtonEnum *, int);
    void setViewArguments();
    int handleMenuKeyPress(MenuButtonEnum *selected, int event);
    string getLargemonSpritePath(string type);
    string getTypeIconPath(string type);
    int menuPanel();

private:
    //model
    BattleInstance battleInstance;
    //view
    LargemonMainView view;
    vector<string> arguments;
};
#endif //LARGEMON_CONTROLLER_H
