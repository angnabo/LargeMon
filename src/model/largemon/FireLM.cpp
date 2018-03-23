//
// Created by angelica on 09/11/17.
//

#include "FireLM.h"

FireLM::FireLM(const int *hp, const int *damage, const int *size, const string *name)
        : Largemon(hp, damage, size, name) {

}

Type FireLM::getType() const {
    return Type::fire;
}

