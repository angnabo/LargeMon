//
// Created by angelica on 09/11/17.
//

#include "WoodLM.h"

WoodLM::WoodLM(const int *hp, const int *damage, const int *size, const string *name)
        : Largemon(hp, damage, size, name) {

}

Type WoodLM::getType() const {
    return Type::wood;
}
