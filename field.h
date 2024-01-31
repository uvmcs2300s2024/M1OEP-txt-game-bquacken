#ifndef M1OEP_TXT_GAME_BQUACKEN_FIELD_H
#define M1OEP_TXT_GAME_BQUACKEN_FIELD_H

#include <vector>
#include "inventory.h"

vector<string> fieldOptions = {"Milk cows","search carriage","go to fortress"};

class field{
    private:
        bool carriageSearched = false;
        bool fortressVisited = false;
        bool towerVisited = false;
        bool encampmentVisited = false;
        bool cowsMilked = false;

    public:

        field();

        void visitFortress(inventory& i);

        void milkCows(inventory& i);

        void searchCarriage(inventory& i);

};


#endif //M1OEP_TXT_GAME_BQUACKEN_FIELD_H
