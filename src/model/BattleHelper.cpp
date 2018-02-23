//
// Created by angelica on 23/02/18.
//

#include "BattleHelper.h"

BattleHelper::BattleHelper() = default;

/**
 * Set the largemon arguments for special attack
 * @param lm
 * @return a message to display about the attack
 */
string BattleHelper::setSpecAttackArgs(Largemon * lm, int playrDmg, int enDmg, vector<string> & plyrArg, vector<string> & enArg){
    string action;
    if(lm->isPlayer()){
        action = "You used a powerful attack for " + to_string(playrDmg) + " damage. ";
        plyrArg.at(1) = "Special Attack";
    } else {
        action = "Enemy used a powerful attack for " + to_string(enDmg) + " damage. ";
        enArg.at(1) = "Special Attack";
    }
    return action;
}

