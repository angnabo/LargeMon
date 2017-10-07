#include <string>
#include <iostream>
#include "FireLM.h"


using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    double size = 10;
    double hp = 10;
    double damage = 10;
    std:string type = "fire";

    FireLM fire(&hp, &damage, &size, &type);
    return 0;
}