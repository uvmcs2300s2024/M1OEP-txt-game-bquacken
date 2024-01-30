#ifndef M1OEP_TXT_GAME_BQUACKEN_FIELD_H
#define M1OEP_TXT_GAME_BQUACKEN_FIELD_H

#include "inventory.h"

class field{
    private:
        bool carriageSearched = false;
        bool fortressVisited = false;
        bool cowsMilked = false;

    public:

        void visitFortress();

        void milkCows(inventory& i);

        void searchCarriage();

};


#endif //M1OEP_TXT_GAME_BQUACKEN_FIELD_H
