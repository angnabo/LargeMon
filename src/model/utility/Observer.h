//
// Created by angelica on 10/11/17.
//

#ifndef LARGEMON_OBSERVER_H
#define LARGEMON_OBSERVER_H


#include "../largemon/Largemon.h"

class Observer {
public:
    Observer(Largemon *);

//    Observer();

    virtual ~Observer();

    virtual void update() const = 0;

    Largemon *largeMon;

};


#endif //LARGEMON_OBSERVER_H
