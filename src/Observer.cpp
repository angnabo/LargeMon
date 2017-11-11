//
// Created by angelica on 10/11/17.
//

#include "Observer.h"

Observer::Observer(LargeMon *lm) {
    largeMon = lm;
    largeMon->attach(this);
}

Observer::~Observer() {

}

//Observer::Observer() {}