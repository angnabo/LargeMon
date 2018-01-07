//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include "Largemon.h"

//using namespace std;

Largemon::Largemon(const int* hp, const int* damage, const int* size, const string * name){
    this->name = *name;
    this->hp = *hp;
    this->currentHp = *hp;
    this->damage = *damage;
    this->size = *size;
    stunned = false;
    //this->type = type;
}

string Largemon::getName() const {
    return name;
}

void Largemon::takeDamage(int damage) {
    currentHp -= damage;
    if(currentHp < 0){
        currentHp = 0;
    }
}

int Largemon::getDamage() {
    lastAction = "Attack";
//    notify();
    return damage;
}

void Largemon::defend(){
    currentHp += 20;
    if(currentHp > hp){
        currentHp = hp;
    }
    lastAction = "Defend";
    //notify();
}

int Largemon::specialAttack() const {
    return 0;
}

std::string Largemon::getLastAction() {
    return lastAction;
}

//void Largemon::notify() {
//    for (int i = 0; i < views.size(); i++){
//        views[i]->update();
//    }
//}

void Largemon::stun(){
    stunned = true;
}

void Largemon::unstun(){
    stunned = false;
}

bool Largemon::isStunned(){
    return stunned;
}

void Largemon::attach(Observer * obs) {
    views.push_back(obs);
}

Largemon::~Largemon() = default;

//string Largemon::getType() {
//    return "";
//}

