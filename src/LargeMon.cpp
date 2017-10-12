//
// Created by angelica on 07/10/17.
//

#include "LargeMon.h"

//using namespace std;

LargeMon::LargeMon(const int* hp, const int* damage, const int* size, string type){
    this->hp = *hp;
    this->damage = *damage;
    this->size = *size;
    this->type = type;
}

void LargeMon::recieveDamage(int damage) {
    hp -= damage;
}

int LargeMon::dealDamage() {
    return damage;
}

void LargeMon::defend(){
    hp += 20;
}

//std::string LargeMon::getCounterLM() {
//    return type;
//}

LargeMon::~LargeMon() = default;

