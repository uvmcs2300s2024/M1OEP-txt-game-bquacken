#include "player.h"
#include "item.cpp"
#include "inventory.cpp"

player::player() {
    playerLocation = field;
    respawnLocation = field;
    playerHealth = 100;
    isWounded = false;

}

player::locations player::getPLayerLocation() {
    return playerLocation;
}

player::locations player::getRespawnLocation() {
    return respawnLocation;
}

int player::getPlayerHealth() {
    return playerHealth;
}

void player::damagePlayer(int pDmgAmount) {
    playerHealth -= pDmgAmount;
}

void player::woundPlayer() {
    isWounded = true;
}

void player::healPlayer(int pHealAmount) {
    if(isWounded){
        pHealAmount = pHealAmount/2;
    }

    playerHealth += pHealAmount;

    if(playerHealth > 100){
        playerHealth = playerHealth - (playerHealth - 100);
    }

}

