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
    /**
     * constructor that creates an inventory object with
     * the storedItems vector full of every item with amount 0w
     */
    inventory();

    /**
     * adds an item to the inventory
     * @param pItem The item object you want to add to
     * the inventory will check if it adds up to more than the maxNumItem
     */
    void pickUpItem(item pItem);

    /**
     * a function that will drop a pAmount of whatever item is
     * at storedItems[pItemID]
     * @param pItemID the itemID/index of the item being dropped
     * @param pAmount the amount of the item that is being dropped
     * @return if the inventory has enough to drop pAmount
     */
    bool dropItem(int pItemID,int pAmount);

    friend ostream& operator<<(ostream& out, inventory& i){
        out << "Your Inventory:\n";
            for(item obj:i.storedItems){
                out << obj;
            }

        return out;
    }
};

#endif //M1OEP_TXT_GAME_BQUACKEN_INVENTORY_H
