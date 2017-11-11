//
// Created by angelica on 11/11/17.
//

#include <iostream>
#include "../include/ViewObserver.h"

ViewObserver::ViewObserver(LargeMon *lm) : Observer(lm) {
    //largeMon->attach(this);
}

ViewObserver::~ViewObserver() {

}

void ViewObserver::update() const {
    cout << "LagrgeMon health: " << largeMon->getHp() << endl;
}

//ViewObserver::ViewObserver() = default;
