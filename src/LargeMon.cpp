//
// Created by angelica on 07/10/17.
//

#include "LargeMon.h"

//using namespace std;

//LargeMon::LargeMon(const double* hp, const double* damage, const double* size, const char* type){
//    this->hp = *hp;
//    this->damage = *damage;
//    this->size = *size;
//    this->type = *type;
//}

double LargeMon::attack() {
    return damage;
}

void LargeMon::defend(){
    hp += 20;
}

//std::string LargeMon::getCounterLM() {
//    return type;
//}

LargeMon::~LargeMon(){
    //TODO
}

