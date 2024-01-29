#ifndef M1OEP_TXT_GAME_BQUACKEN_PLAYER_H
#define M1OEP_TXT_GAME_BQUACKEN_PLAYER_H

#include <vector>
#include <iostream>
#include "item.cpp"
#include ""
using namespace std;

class player{
    private:
        enum locations{
            field, fieldFortress, caveEntrance, caveCavern, riverShore, riverCurrent,
            waterfallShore, waterfallLake,
        };

        locations playerLocation;
        locations respawnLocation;
        int playerHealth;
        vector<item> inventory;
        bool isWounded;

    public:
        /**
         * default constructor for player
         */
        player();

        /**
         * @return the current location of the player
         */
        locations getPLayerLocation();

        locations getRespawnLocation();

        void setPlayerLocation(locations pLocation);

        void setRespawnLocation(locations pResLocation);

        int getPlayerHealth();

        void damagePlayer(int pDmgAmount);

        void woundPlayer();

        void healPlayer(int pHealAmount);

        friend ostream& operator<<(ostream& out, const player& you);


};
#endif //M1OEP_TXT_GAME_BQUACKEN_PLAYER_H
