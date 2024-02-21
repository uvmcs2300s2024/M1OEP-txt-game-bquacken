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

string bar = "_________________________________________\n";


vector<string> optionsKey = {"a)","b)","c)","d)","e)","f)","g)","h)","i)","j)","k)","l)","m)"};

class input{
public:

    /**
     * takes a vector of strings that tell the player
     * what their options are and runs input validation on it
     * @param options the vecotor of options that will be printed
     * @return the option the player chose(is input validated)
     */
    char actionMenu(vector<string> options, player& p,
                    inventory& i,bool showMap,bool showInventory,
                    bool isSubArea);
    /**
     * The input that displays the map options
     * @param p a player object to allow access of discoveredLocations
     * @return the users choice with input validation
     */
    char mapMenu(player& p);
};
#endif //M1OEP_TXT_GAME_BQUACKEN_INPUT_H
