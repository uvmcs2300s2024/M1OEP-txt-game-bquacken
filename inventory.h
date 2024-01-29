#ifndef M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H
#define M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H

#include <vector>
#include "item.cpp"

using namespace std;

class inventory{
private:

    vector<item> storedItems;

public:
    inventory();

    bool pickUpItem(item pItem);

    void dropItem(item pItem,int pAmount);
};

#endif //M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H
