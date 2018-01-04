//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include "../../include/largeMonHeader/LargeMon.h"

//using namespace std;

LargeMon::LargeMon(const int* hp, const int* damage, const int* size, const string * name){
    this->name = *name;
    this->hp = *hp;
    this->currentHp = *hp;
    this->damage = *damage;
    this->size = *size;
    //this->type = type;
}

string LargeMon::getName() const {
    return name;
}

void LargeMon::takeDamage(int damage) {
    currentHp -= damage;
    if(currentHp < 0){
        currentHp = 0;
    }
}

int LargeMon::getDamage() {
    lastAction = "Attack";
    notify();
    return damage;
}

void LargeMon::defend(){
    currentHp += 20;
    if(currentHp > hp){
        currentHp = hp;
    }
    lastAction = "Defend";
    notify();
}

int LargeMon::specialAttack() const {
    return 0;
}

std::string LargeMon::getLastAction() {
    return lastAction;
}

void LargeMon::notify() {
    for (int i = 0; i < views.size(); i++){
        views[i]->update();
    }
}

void LargeMon::attach(Observer * obs) {
    views.push_back(obs);
}

LargeMon::~LargeMon() = default;

//string LargeMon::getType() {
//    return "";
//}

