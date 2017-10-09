//
// Created by angelica on 07/10/17.
//

#include "LargeMon.h"

//using namespace std;

LargeMon::LargeMon(const double* hp, const double* damage, const double* size, string type){
    this->hp = *hp;
    this->damage = *damage;
    this->size = *size;
    this->type = type;
}

void LargeMon::recieveDamage(double damage) {
    hp -= damage;
}

double LargeMon::dealDamage() {
    return damage;
}

void LargeMon::defend(){
    hp += 20;
}

//std::string LargeMon::getCounterLM() {
//    return type;
//}

LargeMon::~LargeMon() = default;

