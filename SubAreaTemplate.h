//
// Created by Benjamin Quackenbush on 2/16/2024.
//

#ifndef TXT_GAME_BQUACKEN_SUBAREATEMPLATE_H
#define TXT_GAME_BQUACKEN_SUBAREATEMPLATE_H

#include <vector>
#include "string"
#include "player.h"
#include "input.h"
#include "inventory.h"
#include "item.h"
#include "EncounterTemplate.h"

class SubAreaTemplate{
private:
    bool visited;
    vector<vector<item>> items;
    string areaTxt;
    vector<string> options;
    vector<string> optionsTxt;
    vector<bool> isSearched;
    bool hasEncounter;

public:

    SubAreaTemplate(vector<vector<item>> items, string areaTxt, vector<string> options,
                    vector<string> optionsTxt,bool hasEncounter);

    void visit(player& p);

    void search(player& p, int lowerIndex);

    bool getHasEncounter();

    void setHasEncounter(bool hasEncounter);

};
#endif //TXT_GAME_BQUACKEN_SUBAREATEMPLATE_H
