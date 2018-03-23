//
// Created by angelica on 07/10/17.
//

#include "LargemonGenerator.h"

LargemonGenerator::LargemonGenerator() = default;

/**
 * Generate a random largemon
 * @return
 */
Largemon *LargemonGenerator::generateLargemon() {

    // get health points
    int health = RandomNumber::randomInRange(MIN_HEALTH, MAX_HEALTH);

    // get damage based on health
    int damage = getDamage(health);

    // get the size
    int size = RandomNumber::randomInRange(MIN_SIZE, MAX_SIZE);

    // get a type
    Type type = Type(RandomNumber::randomInRange(0, 2));

    switch (type) {
        case Type::fire : {
            string name = generateName(type);
            auto *lm = new FireLM(&health, &damage, &size, &name);
            return lm;
        }
        case Type::water : {
            string name = generateName(type);
            auto *lm = new WaterLM(&health, &damage, &size, &name);
            return lm;
        }
        case Type::wood : {
            string name = generateName(type);
            auto *lm = new WoodLM(&health, &damage, &size, &name);
            return lm;
        }
    }
}

/**
 * Generate a damage value based on a health value
 * @param health
 * @return
 */
int LargemonGenerator::getDamage(int health) {
    int damage;
    if (health < DAMAGE_FACTOR) {
        damage = RandomNumber::randomInRange(MIN_DMG_IF_HEALTH_LOW, MAX_DMG_IF_HEALTH_LOW);
    } else {
        damage = RandomNumber::randomInRange(MIN_DMG_IF_HEALTH_HIGH, MAX_DMG_IF_HEALTH_HIGH);
    }
    return damage;
}

/**
 * Generate a largemon name
 * @param type
 * @return
 */
string LargemonGenerator::generateName(Type type) {
    string name;
    switch (type) {
        case Type::fire :
            name = fireNames[RandomNumber::randomInRange(0, static_cast<int>(fireNames.size() - 1))];
            break;
        case Type::water :
            name = waterNames[RandomNumber::randomInRange(0, static_cast<int>(waterNames.size() - 1))];
            break;
        case Type::wood :
            name = woodNames[RandomNumber::randomInRange(0, static_cast<int>(woodNames.size() - 1))];
            break;
    }
    return name;
}
