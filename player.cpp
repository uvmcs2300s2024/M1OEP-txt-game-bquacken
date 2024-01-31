#include "player.h"
#include "item.h"
#include "inventory.h"

player::player() {
    playerLocation = starting;
    respawnLocation = starting;
    playerHealth = 100;
    isWounded = false;

}

locations player::getPLayerLocation() {
    return playerLocation;
}

locations player::getRespawnLocation() {
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

