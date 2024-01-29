#ifndef M1OEP_TXT_GAME_BQUACKEN_ITEMS_H
#define M1OEP_TXT_GAME_BQUACKEN_ITEMS_H

class item{

    enum itemType{
        bomb, bandage, lantern, cloak, pocketBlackHole,
        knife, coins, milkBucket, potion
    };

private:
    itemType thisItem;

    int numItem;

public:

    /**
     * constructor for an item Object
     * @param pThisItem what type of item it will be
     * @param pNumItem the number of items
     */
    item(itemType pThisItem, int pNumItem);

    /**
     * simple getter for thisItem variable
     * @return the type of item
     */
    itemType getItem();

    /**
     * getter for numItem variable
     * @return the number of items
     */
    int getNumItem();

    /**
     * sets the number of items
     * @param pNumItem the new number of items
     */
    void setNumItem(int pNumItem);

};
#endif //M1OEP_TXT_GAME_BQUACKEN_ITEMS_H
