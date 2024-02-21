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

    inventory yourStuff;
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
         * gets the players location
         * @return the current location of the player
         */
        locations getPLayerLocation();

        /**
         * does at the moment
         * @return the players respawn location
         */
        locations getRespawnLocation();

        /**
         * changes the players location
         * @param pLocation the new location
         */
        void setPlayerLocation(locations pLocation);

        /**
         * changes the players respawn location
         * @param pResLocation the new respawn location
         */
        void setRespawnLocation(locations pResLocation);

        /**
         * gets a pointer to discoveredLocations used to unlock
         * new areas on the map
         * @return a pointer of discoveredLocations
         */
        vector<locations>& getDiscoveredLocations();

        /**
         * gets the players health
         * @return playerHealth var
         */
        int getPlayerHealth();

        /**
         *
         * @return a pointer to the players inventory
         */
        inventory& getStuff(){
            return yourStuff;
        }

        /**
         * @return if the player is wounded or not
         */
        bool getIsWounded();

        /**
         * hurts the player
         * @param pDmgAmount amount subtracted from playerHealth
         */
        void damagePlayer(int pDmgAmount);

        /**
         * set isWounded to true;
         */
        void woundPlayer();

        /**
         * heals the player pHealAmount or pHealAmount/2 if wounded
         * @param pHealAmount the healing amount
         */
        void healPlayer(int pHealAmount);

        friend ostream& operator<<(ostream& out, player& you){
            out << "_____________________\n" <<
                   "Health: " << you.getPlayerHealth() << endl;

            return out;
        }


};
#endif //M1OEP_TXT_GAME_BQUACKEN_PLAYER_H
