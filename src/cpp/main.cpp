#include <string>
#include <iostream>
#include "../include/LargeMonGenerator.h"
#include "../include/BattleInstance.h"
#include "../include/DescriptGen.h"

using namespace std;

int main() {

    //2 observers, one for the view and one for saving, updated by the subject notifying the observer

    LargeMonGenerator gen;

    LargeMon * f = gen.generateLargeMon();
    cout << "Health: " <<f->getHp() << ", Damage: " << f->getDamage() << ", Size: " << f->getSize()
         << ", Special Attack: " << f->specialAttack() << ", type: " << f->getType();
    DescriptGen descript(f->getType(), f->getSize());
    cout << "\n" << descript.getDescription() << endl;
    BattleInstance battle;
    battle.fight();

    return 0;
}