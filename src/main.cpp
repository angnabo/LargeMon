#include <string>
#include <iostream>
#include "LargeMonGenerator.h"


using namespace std;

int main() {

    LargeMonGenerator gen;
    LargeMon f = gen.generateLargeMon();
    cout << "Health: " <<f.getHp() << ", Damage: " << f.getDamage() << ", Size: " << f.getSize() << ", Type: " << f.getType();

    return 0;
}