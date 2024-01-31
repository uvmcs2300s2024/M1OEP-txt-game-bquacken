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
    bool hasMap;

public:
    inventory();

    item pickUpItem(item pItem);

    bool dropItem(int pItemID,int pAmount);

    friend ostream& operator<<(ostream& out, inventory& i){
        out << "Your Inventory:\n";
            for(item obj:i.storedItems){
                out << obj;
            }

        return out;
    }

    bool getHasMap();

    void obtainMap();

};

#endif //M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H
