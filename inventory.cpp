#include <vector>
#include <iostream>

#include "inventory.h"
#include "item.h"

inventory::inventory() {
    for(int i = 0; i < 8; i++){
        storedItems.emplace_back(i);
    }
    hasMap = false;
}

item inventory::pickUpItem(item pItem) {
    item& yourItem = storedItems[pItem.getItemID()];
    if(yourItem == pItem){//kind of a redundant check but here for now
        int totalNum = yourItem.getNumItem() + pItem.getNumItem();

        if(totalNum > yourItem.getMaxNumItem()){
            yourItem.setNumItem(yourItem.getMaxNumItem());
            pItem.setNumItem((yourItem.getNumItem() + pItem.getNumItem()) -
                             pItem.getMaxNumItem());
            return pItem;
        } else {
            yourItem.setNumItem(yourItem.getNumItem() + pItem.getNumItem());
            pItem.setNumItem(0);
            return pItem;
        }
    }
    return pItem;
}

bool inventory::dropItem(int pItemID, int pAmount) {
    item& yourItem = storedItems[pItemID];
    if(pAmount > yourItem.getNumItem()){
        return false;
    }else{
        yourItem.setNumItem(yourItem.getNumItem() - pAmount);
        return true;
    }
}

bool inventory::getHasMap() {
    return hasMap;
}

void inventory::obtainMap() {
    hasMap = true;
}
