#include <string>
#include <iostream>
#include "LargeMonGenerator.h"
#include "BattleInstance.h"
#include "DescriptGen.h"

using namespace std;

int main() {

    LargeMonGenerator gen;

    LargeMon * f = gen.generateLargeMon();
    cout << "Health: " <<f->getHp() << ", Damage: " << f->getDamage() << ", Size: " << f->getSize()
         << ", Special Attack: " << f->specialAttack();
    DescriptGen descript(f->getType(), f->getSize());
    cout << "\n" << descript.getDescription() << endl;
    BattleInstance battle;
    //battle.fight();

    return 0;
}