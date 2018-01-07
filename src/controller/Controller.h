//
// Created by angelica on 20/10/17.
//

#ifndef LARGEMON_CONTROLLER_H
#define LARGEMON_CONTROLLER_H

#include "ControllerBattleInstance.h"
#include "../LargeMonMainView.h"


using namespace std;
class Controller {
public:
    Controller();
    void run();
    int handleKeyPress(int *, int);
    void setViewArguments();
    string getLargemonSpritePath(string);

private:
    //model
    ControllerBattleInstance battleInstance;
    //view
    LargeMonMainView view;
    vector <string> arguments;

};


#endif //LARGEMON_CONTROLLER_H
