#ifndef M1OEP_TXT_GAME_BQUACKEN_ITEMS_H
#define M1OEP_TXT_GAME_BQUACKEN_ITEMS_H

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class item{

public: enum itemType{
        bomb, bandage, lantern, cloak, pocketBlackHole,
        knife, coin, milkBucket, potion
    };

    const vector<string> itemTypeNames = {"Bomb","Bandage","Lantern","Cloak",
                                          "Pocket Black Hole","Knife","coin",
                                          "Milk Bucket","Potion"};

private:
    itemType thisItem;

    int numItem;

    int maxNumItem;



public:

    /**
     * constructor for an item Object
     * @param pThisItem what type of item it will be
     * @param pNumItem the number of items
     * will also assign the value of maxNumItem
     */
    item(itemType pThisItem, int pNumItem);

    /**
     * simple getter for thisItem variable to use in
     * printing the item type
     * @return the type of item as a string
     */
    string getItem();

    /**
     * a getter that returns the enum #
     * @return the number assigned to the itemType
     */
    itemType getItemID();

    /**
     * getter for numItem variable
     * @return the number of items
     */
    int getNumItem();

    /**
     * gets the maximum amount of the item the player
     * is allowed to have
     * @return the max number of items allowed
     */
    int getMaxNumItem();

    /**
     * sets the number of items
     * @param pNumItem the new number of items
     */
    void setNumItem(int pNumItem);


};
#endif //M1OEP_TXT_GAME_BQUACKEN_ITEMS_H
