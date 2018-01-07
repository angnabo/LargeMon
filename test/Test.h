//
// Created by angelica on 04/01/18.
//

#ifndef LARGEMON_TEST_H
#define LARGEMON_TEST_H
#include "../src/model/BattleInstance.h"
#include "../src/utility/FileWriter.h"
class Test {
public:
    void test();
private:
    BattleInstance battle;
    FileWriter * wr;
};


#endif //LARGEMON_TEST_H
