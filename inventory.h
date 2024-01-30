#ifndef M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H
#define M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H

#include <vector>
#include "item.h"

using namespace std;

class inventory{
private:

    vector<item> storedItems;

public:
    inventory();

    item pickUpItem(item& pItem);

    bool dropItem(int pItemID,int pAmount);
};

#endif //M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H
