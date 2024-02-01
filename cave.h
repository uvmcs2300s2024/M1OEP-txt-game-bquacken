#ifndef M1OEP_TXT_GAME_BQUACKEN_CAVE_H
#define M1OEP_TXT_GAME_BQUACKEN_CAVE_H
#include <random>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "field.h"
#include "inventory.h"
#include "item.h"
using namespace std;

class cave{
private:
    bool campsiteVisited= false;
    bool darkCubbySearched = false;
    bool caveFortressSeen = false;
};
#endif //M1OEP_TXT_GAME_BQUACKEN_CAVE_H
