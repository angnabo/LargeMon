//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include "Largemon.h"
#include "../observer/Observer.h"

Largemon::Largemon(const int *hp, const int *damage, const int *size, const string *name) {
    this->name = *name;
    this->maxHp = *hp;
    this->currentHp = *hp;
    this->damage = *damage;
    this->size = *size;
    this->isLmPlayer = false;
}

string Largemon::getName() const {
    return name;
}

void Largemon::takeDamage(int damage) {
    currentHp -= damage;
    if (currentHp < 0) {
        currentHp = 0;
    }
    notify();
}

int Largemon::attack() {
    lastAction = "Attack";
    return damage;
}

void Largemon::defend() {
    currentHp += 40;
    if (currentHp > maxHp) {
        currentHp = maxHp;
    }
    lastAction = "Defend";
    notify();
}

float Largemon::getCurrentHpPercent() {
    float hpPercent = (float) getCurrentHp() / (float) getHp();
    return hpPercent;
}

int Largemon::specialAttack(){
    lastAction = "Special Attack";
    return static_cast<int>(damage * 1.40);//damage against antagonist types is 40% more effective
}

void Largemon::notify() {
    for (int i = 0; i < views.size(); i++) {
        views[i]->update();
    }
}

void Largemon::stun(int count) {
    stunCount = count;
    notify();
}

void Largemon::decrementStun() {
    if (stunCount > 0) {
        stunCount--;
    }
}

bool Largemon::isStunned() {
    return (stunCount != 0);
}

void Largemon::attach(Observer *obs) {
    views.push_back(obs);
}

void Largemon::setAsPlayer() {
    isLmPlayer = true;
}

bool Largemon::isPlayer() {
    return isLmPlayer;
}

// start taking tick damage per turn
void Largemon::takeTickDamage(int count) {
    tickDmgCount = count;
    notify();
}

// actually apply the damage as lost health
void Largemon::applyTickDamage(int damage) {
    if (tickDmgCount > 0) {
        takeDamage(damage);
        decrementTickCount();
    }
}

// to be used when changing the largemon's colour when it takes tick damage
bool Largemon::isTakingTickDamage() {
    return (tickDmgCount != 0);
}

void Largemon::decrementTickCount() {
    if (tickDmgCount > 0) {
        tickDmgCount--;
    }
}

Largemon::~Largemon() = default;