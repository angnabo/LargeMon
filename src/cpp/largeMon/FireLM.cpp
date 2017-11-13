//
// Created by angelica on 09/11/17.
//

#include "../../include/largeMonHeader/FireLM.h"

FireLM::FireLM(const int *hp, const int *damage, const int *size, const string * name)
        : LargeMon(hp, damage, size, name) {

}

int FireLM::specialAttack() const {
    return (int)damage*1.40;
}

string FireLM::getType() const {
    string s = "fire";
    return s;
}
