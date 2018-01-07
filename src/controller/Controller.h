//
// Created by angelica on 20/10/17.
//

#ifndef LARGEMON_CONTROLLER_H
#define LARGEMON_CONTROLLER_H

#include "../model/BattleInstance.h"
#include "../view/LargeMonMainView.h"


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
    BattleInstance battleInstance;
    //view
    LargeMonMainView view;
    vector <string> arguments;

};


#endif //LARGEMON_CONTROLLER_H
