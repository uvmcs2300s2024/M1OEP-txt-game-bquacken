#include "player.h"

player::player() {
    yourStuff = inventory();
    playerLocation = grassLands;
    respawnLocation = grassLands;
    playerHealth = 100;
    isWounded = false;
}

locations player::getPLayerLocation() {
    return playerLocation;
}

locations player::getRespawnLocation() {
    return respawnLocation;
}

vector<locations>& player::getDiscoveredLocations() {
    return discoveredLocations;
}

int player::getPlayerHealth() {
    return playerHealth;
}

void player::damagePlayer(int pDmgAmount) {
    playerHealth -= pDmgAmount;
}

bool player::getIsWounded(){
    return isWounded;
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

void player::setPlayerLocation(locations pLocation){
    for(locations l:discoveredLocations){
        if(l == pLocation){
            playerLocation = pLocation;
        }
    }
}
