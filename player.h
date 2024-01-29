#ifndef M1OEP_TXT_GAME_BQUACKEN_PLAYER_H
#define M1OEP_TXT_GAME_BQUACKEN_PLAYER_H

#include <vector>
#include "item.cpp"
using namespace std;

class player{
    private:
        enum location{
            field, fieldFortress, caveEntrance, caveCavern, riverShore, riverCurrent,
            waterfallShore, waterfallLake,
        };

        location playerLocation;
        location respawnLocation;
        int playerHealth;
        vector<item> inventory;
        bool ishurt;

    public:
        /**
         * default constructor for player
         */
        player();

        /**
         * @return the current location of the player
         */
        location getPLayerLocation();

        location getRespawnLocation();

        void setPlayerLocation();

        void setRespawnLocation();


};
#endif //M1OEP_TXT_GAME_BQUACKEN_PLAYER_H
