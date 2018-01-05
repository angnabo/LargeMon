//
// Created by angelica on 04/01/18.
//

#ifndef LARGEMON_TEST_H
#define LARGEMON_TEST_H
#include "../src/controller/ControllerBattleInstance.h"
#include "../src/controller/FileWriter.h"
class Test {
public:
    void test();
private:
    ControllerBattleInstance battle;
    FileWriter * wr;
};


#endif //LARGEMON_TEST_H
