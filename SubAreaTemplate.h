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
#include "AreaTemplate.h"

class SubAreaTemplate {
private:
    bool visited;
    vector<vector<item>> items;
    string areaTxt;
    vector<string> options;
    vector<string> optionsTxt;
    vector<bool> isSearched;
    bool hasEncounter;

public:

    /**
     * the default constructor of a SubAreaTemplate
     * @param items a vector of vectors which contains the items obtainable
     * in the subarea
     * @param areaTxt the text displayed in the subarea
     * @param options the options to explore in the sub area
     * @param optionsTxt the text that is displayed when the option is chosen
     * even indexes are first visit text odd are once visited text
     * @param hasEncounter if the subarea has an encounter
     */
    SubAreaTemplate(vector<vector<item>> items, string areaTxt, vector<string> options,
                    vector<string> optionsTxt, bool hasEncounter);

    /**
     * simpler constructor used for subAreas that don't have any options
     * @param items the items the player will receive
     * @param areaTxt the text for the subarea when you first go there
     * @param areaTxtVisited the text for the subarea after you have been there
     */
    SubAreaTemplate(vector<vector<item>> items, string areaTxt, string areaTxtVisited);

    /**
     * empty constructor
     */
    SubAreaTemplate();

    /**
     * runs the subarea
     * @param p the player
     */
    void visit(player& p);

    /**
     * controls the text and item received for each action possible
     * @param p the player
     * @param lowerIndex the lower of the two indexes that indicates
     * the choice chosen
     */
    void search(player& p, int lowerIndex);

    /**
     * does the subarea have an encounter
     * @return the hasEncounter variable
     */
    bool getHasEncounter();

    /**
     * sets if the subarea has an encounter
     * @param hasEncounter if the area has an encounter
     */
    void setHasEncounter(bool hasEncounter);

    bool getOptionsIsEmpty();

    void addItem(int index, item thing);

    void addToOptionsList(string option);

    void setOptionsList(vector<string> list);

    void addToOptionsText(string text);

    void setAreaText(string text);

};
#endif //TXT_GAME_BQUACKEN_SUBAREATEMPLATE_H
