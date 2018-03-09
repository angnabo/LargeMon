//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include "Largemon.h"
#include "../utility/Observer.h"

//using namespace std;

Largemon::Largemon(const int* hp, const int* damage, const int* size, const string * name){
    this->name = *name;
    this->hp = *hp;
    this->currentHp = *hp;
    this->damage = *damage;
    this->size = *size;
    this->isLmPlayer = false;
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
    notify();
}

int Largemon::getDamage() {
    lastAction = "Attack";
    return damage;
}

void Largemon::defend(){
    currentHp += 20;
    if(currentHp > hp){
        currentHp = hp;
    }
    lastAction = "Defend";
    notify();
}

float Largemon::getCurrentHpPercent(){
    float hpPercent = (float)getCurrentHp()/(float)getHp();//25/50*100
    return hpPercent;
}

int Largemon::specialAttack() const {
    return 0;
}

std::string Largemon::getLastAction() {
    return lastAction;
}

void Largemon::notify() {
    for (int i = 0; i < views.size(); i++){
        views[i]->update();
    }
}

void Largemon::stun(int count){
    stunCount = count;
}

void Largemon::decrementStun() {
    if(stunCount > 0){
        stunCount--;
    }
}

bool Largemon::isStunned(){
    return (stunCount != 0);
}

void Largemon::attach(Observer * obs) {
    views.push_back(obs);
}

void Largemon::setAsPlayer() {
    isLmPlayer = true;
}

bool Largemon::isPlayer() {
    return isLmPlayer;
}

void Largemon::takeTickDamage(int count) {
    tickDmgCount = count;
}

void Largemon::applyTickDamage(int damage){
    if(tickDmgCount > 0) {
        takeDamage(damage);
        decrementTickCount();
    }
}

bool Largemon::isTakingTickDamage(){
    return (tickDmgCount != 0);
}

void Largemon::decrementTickCount() {
    if(tickDmgCount > 0) {
        tickDmgCount--;
    }
}


Largemon::~Largemon() = default;

//string Largemon::getType() {
//    return "";
//}

