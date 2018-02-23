//
// Created by angelica on 23/02/18.
//

#ifndef LARGEMON_BATTLEHELPER_H
#define LARGEMON_BATTLEHELPER_H

#include "largemon/Largemon.h"

class BattleHelper {
public:
    BattleHelper();


    string setSpecAttackArgs(Largemon *lm, int playrDmg, int enDmg, vector<string> &plyrArg, vector<string> &enArg);


private:
};


#endif //LARGEMON_BATTLEHELPER_H
