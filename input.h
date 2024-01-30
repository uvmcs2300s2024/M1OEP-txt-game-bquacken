//
// Created by Benjamin Quackenbush on 1/30/2024.
//

#ifndef M1OEP_TXT_GAME_BQUACKEN_INPUT_H
#define M1OEP_TXT_GAME_BQUACKEN_INPUT_H

#include <iostream>
#include <vector>

#include "inventory.h"
#include "player.h"
#include "item.h"

class input{
public:
    /**
     * the action menu that will include all actions
     * possible in the area the player is in
     * @param pLoc the players location
     * @return the choice inputted
     */
    char actionMenu(locations pLoc);

    /**
     * will include inventory operations
     * @return the choice inputted
     */
    char inventoryMenu();
};
#endif //M1OEP_TXT_GAME_BQUACKEN_INPUT_H
