//
// Created by angelica on 09/11/17.
//

#include "FireLM.h"

FireLM::FireLM(const int *hp, const int *damage, const int *size)
        : LargeMon(hp, damage, size) {

}

int FireLM::specialAttack() const {
    return (int)damage*1.40;
}

string FireLM::getType() const {
    string s = "fire";
    return s;
}
