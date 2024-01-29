#ifndef M1OEP_TXT_GAME_BQUACKEN_FIELD_H
#define M1OEP_TXT_GAME_BQUACKEN_FIELD_H

#include <random>

class field{
    private:
        bool carriageSearched;
        bool fortressVisited;
        bool cowsMilked;

    public:

        void visitFortress();

        void milkCows();

        void searchCarriage();

};


#endif //M1OEP_TXT_GAME_BQUACKEN_FIELD_H
