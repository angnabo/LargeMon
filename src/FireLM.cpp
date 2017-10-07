//
// Created by angelica on 07/10/17.
//
#include "LargeMon.h"
#include "FireLM.h"

FireLM::FireLM(const double* hp, const double* damage, const double* size, std::string* type){
    this->hp = *hp;
    this->damage = *damage;
    this->size = *size;
    this->type = *type;
}

std::string FireLM::getCounterLM() {
    return type;

}