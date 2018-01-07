//
// Created by angelica on 10/11/17.
//

#include "Observer.h"

Observer::Observer(Largemon *lm) {
    largeMon = lm;
    largeMon->attach(this);
}

Observer::~Observer() {

}

//Observer::Observer() {}