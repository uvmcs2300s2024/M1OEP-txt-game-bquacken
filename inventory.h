#ifndef M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H
#define M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H

#include <vector>
#include <ostream>
#include <iostream>
#include "item.h"

using namespace std;

class inventory{
private:

    vector<item> storedItems;

public:
    inventory();

    item pickUpItem(item pItem);

    bool dropItem(int pItemID,int pAmount);

    friend ostream& operator<<(ostream& out, inventory& i){
        out << "Your Inventory:\n"
            << i.storedItems[0]
            << i.storedItems[1]
            << i.storedItems[2]
            << i.storedItems[3]
            << i.storedItems[4]
            << i.storedItems[5]
            << i.storedItems[6]
            << i.storedItems[7];

        return out;
    }

};

#endif //M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H
