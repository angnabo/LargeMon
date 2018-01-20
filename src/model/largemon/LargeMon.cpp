//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include "LargeMon.h"
#include "../../utility/Observer.h"

//using namespace std;

LargeMon::LargeMon(const int* hp, const int* damage, const int* size, const string * name){
    this->name = *name;
    this->hp = *hp;
    this->currentHp = *hp;
    this->damage = *damage;
    this->size = *size;
    stunned = false;
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
    notify();
}

int LargeMon::getDamage() {
    lastAction = "Attack";
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

float LargeMon::getCurrentHpPercent(){
    float hpPercent = (float)getCurrentHp()/(float)getHp();//25/50*100
    return hpPercent;
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

void LargeMon::stun(){
    stunned = true;
}

void LargeMon::unstun(){
    stunned = false;
}

bool LargeMon::isStunned(){
    return stunned;
}

void LargeMon::attach(Observer * obs) {
    views.push_back(obs);
}

void LargeMon::setAsPlayer() {
    player = true;
}

bool LargeMon::isPlayer() {
    return player;
}

LargeMon::~LargeMon() = default;

//string LargeMon::getType() {
//    return "";
//}

