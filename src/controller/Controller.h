//
// Created by angelica on 20/10/17.
//

#ifndef LARGEMON_CONTROLLER_H
#define LARGEMON_CONTROLLER_H

#include "../model/BattleInstance.h"
#include "../view/LargemonMainView.h"
#include "../model/utility/HealthBarObserver.h"
#include <iostream>

using namespace std;
class Controller {
public:
    Controller();

    void close();

    enum Button{
        top_left = 0,
        top_right = 1,
        bottom_left = 2,
        bottom_right = 3
    };

    enum MenuButton{
        left = 0,
        right = 1,
    };

    int run(LargemonMainView*);
    int handleKeyPress(Button *, int);
    void setViewArguments();
    string getLargemonPath(string type);

    string getTypePath(string type);

    int menuPanel();


private:
    //model
    BattleInstance battleInstance;
    //view
    LargemonMainView * view;
    vector <string> arguments;


    int handleMenuKeyPress(MenuButton *selected, int event);
};


#endif //LARGEMON_CONTROLLER_H
