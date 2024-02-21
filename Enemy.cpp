#include "Enemy.h"

enemyType Enemy::getType() {
    return type;
}

int Enemy::getAtkDmg() {
    return atkDmg;
}

int Enemy::getHealth() {
    return health;
}

string Enemy::makeNoise() {
    return noise;
}

void Enemy::flee(vector<SubAreaTemplate> options) {

}

int Enemy::takeDmg(int dmg) {
    health -= dmg;
    return health;
}
