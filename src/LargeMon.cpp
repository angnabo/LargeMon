//
// Created by angelica on 07/10/17.
//

#include "LargeMon.h"

//using namespace std;

LargeMon::LargeMon(const int* hp, const int* damage, const int* size){
    this->hp = *hp;
    this->damage = *damage;
    this->size = *size;
    //this->type = type;
}

void LargeMon::takeDamage(int damage) {
    hp -= damage;
}

void LargeMon::defend(){
    hp += 20;
}

int LargeMon::specialAttack() const {
    return 0;
}

LargeMon::LargeMon() = default;

//string LargeMon::getType() {
//    return "";
//}

LargeMon::~LargeMon() = default;

