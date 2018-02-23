//
// Created by angelica on 20/10/17.
//

#ifndef LARGEMON_CONTROLLER_H
#define LARGEMON_CONTROLLER_H

#include "../model/BattleInstance.h"
#include "../view/LargemonMainView.h"
#include "../model/utility/HealthBarObserver.h"

using namespace std;
class Controller {
public:
    Controller();

    enum Button{
        top_left = 0,
        top_right = 1,
        bottom_left = 2,
        bottom_right = 3
    };

    void run();
    int handleKeyPress(Button *, int);
    void setViewArguments();
    string getLargemonSpritePath(string);

private:
    //model
    BattleInstance battleInstance;
    //view
    LargemonMainView view;
    vector <string> arguments;

};


#endif //LARGEMON_CONTROLLER_H
