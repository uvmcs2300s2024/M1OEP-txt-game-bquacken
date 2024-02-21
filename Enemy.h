#ifndef TXT_GAME_BQUACKEN_ENEMY_H
#define TXT_GAME_BQUACKEN_ENEMY_H

#include <vector>
#include "string"
#include "item.h"
#include "SubAreaTemplate.h"



enum enemyType{
    spider, shade, ogre, yourMom
};
class Enemy{
private:
    enemyType type;
    int health;
    int atkDmg;
    string noise;
    bool flees;
    int fleeHealth;

public:

    Enemy(enemyType type,int health, int atkDmg, string noise);

    explicit Enemy(int fleeHealth);

    enemyType getType();

    int getAtkDmg();

    int getHealth();

    string makeNoise();

    void flee(vector<SubAreaTemplate> options);

    int takeDmg(int dmg);



};

#endif //TXT_GAME_BQUACKEN_ENEMY_H
