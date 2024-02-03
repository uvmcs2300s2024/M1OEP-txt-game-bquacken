#ifndef M1OEP_TXT_GAME_BQUACKEN_FIELD_H
#define M1OEP_TXT_GAME_BQUACKEN_FIELD_H

#include <vector>
#include "inventory.h"

vector<string> fieldOptions = {"Milk cows","search carriage","go to fortress"};

class field{
    private:
        bool isActive = true;
        bool carriageSearched = false;
        bool fortressVisited = false;
        bool towerVisited = false;
        bool encampmentVisited = false;
        bool cowsMilked = false;

    public:

        /**
         * just a text function that prints out the scene
         * description
         */
        void init();


        /**
         * controls the fortress sub-area that contains a
         * tower and some tents each with a few scraps of loot
         * @param i an inventory object to allow the the addition of found item
         * to the inventory
         * @param p needed to edit the discoveredLocations vector
         */
        void visitFortress(inventory& i,player& p);

        /**
         * milks the cows
         * @param i an inventory object to pick up stuff
         */
        void milkCows(inventory& i);

        /**
         * searches the overturned carriage
         * @param i an inventory object to pick up stuff
         */
        void searchCarriage(inventory& i);

};


#endif //M1OEP_TXT_GAME_BQUACKEN_FIELD_H
