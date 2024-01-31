#ifndef M1OEP_TXT_GAME_BQUACKEN_PLAYER_H
#define M1OEP_TXT_GAME_BQUACKEN_PLAYER_H

#include <vector>
#include <iostream>
#include "item.h"

using namespace std;

enum locations{
    grassLands, darkCaves
};

vector<string> locationNames ={"Grasslands","Cave","Town","City","Tower"};

class player{
    private:


    locations playerLocation;
    locations respawnLocation;
    vector<locations> discoveredLocations;
    int playerHealth;
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

        vector<locations>& getDiscoveredLocations();

        int getPlayerHealth();

        bool getIsWounded();

        void damagePlayer(int pDmgAmount);

        void woundPlayer();

        void healPlayer(int pHealAmount);

        friend ostream& operator<<(ostream& out, player& you){
            out << "_____________________\n" <<
                   "Health: " << you.getPlayerHealth() << endl;

            return out;
        }


};
#endif //M1OEP_TXT_GAME_BQUACKEN_PLAYER_H
