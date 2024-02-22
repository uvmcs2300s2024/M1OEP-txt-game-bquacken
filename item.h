#ifndef M1OEP_TXT_GAME_BQUACKEN_ITEMS_H
#define M1OEP_TXT_GAME_BQUACKEN_ITEMS_H

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

static const vector<string> itemTypeNames = {"coin", "bandage", "potion", "bomb",
                                             "knife","lantern", "cloak",
                                             "Milk Bucket","map,""Pocket Black Hole"};

enum itemType{
    coin, bandage, potion, bomb, knife,
    lantern, cloak, milkBucket, map, pocketBlackHole
};

class item{
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
     * constructor for an Item object using the itemID
     * @param pItemId the ID of the enumerated type
     * @param pNumItem the number of items
     */
    item(int pItemId, int pNumItem);

    /**
     * constructor that takes an integer and applys that
     * to the enumerated type itemType and has the amount of
     * the item set to 0 idk what explicit does but
     * clang-tidy was yelling at me
     * @param pItemId the ID of the type of item
     */
    explicit item(int pItemId);

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
    int getItemID();

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

    friend ostream& operator<<(ostream& out, item& i){
        out << i.getItem() << "(" << i.getNumItem() << ")" << endl;

        return out;
    }

    friend bool operator==(item& lhs, item& rhs){
        return lhs.getItemID() == rhs.getItemID();
    }

};
#endif //M1OEP_TXT_GAME_BQUACKEN_ITEMS_H
