//
// Created by Benjamin Quackenbush on 2/16/2024.
//

#ifndef TXT_GAME_BQUACKEN_SUBAREA_H
#define TXT_GAME_BQUACKEN_SUBAREA_H

#include <vector>
#include "string"
#include "input.h"

class SubArea {
private:
    bool visited;
    vector<item> items;
    string areaTxt;
    vector<string> options;
    vector<string> optionsTxt;
    vector<bool> isSearched;
    bool hasEncounter;
    bool isDark;
public:

    /**
     * the default constructor of a SubArea
     * @param areaTxt the text displayed in the subarea
     * @param options the options to explore in the sub area
     * @param optionsTxt the text that is displayed when the option is chosen
     * even indexes are first visit text odd are once visited text
     */
    SubArea(string areaTxt, vector<string> options,
            vector<string> optionsTxt);

    /**
     * simpler constructor used for subAreas that don't have any options
     * @param areaTxt the text for the subarea when you first go there
     * @param areaTxtVisited the text for the subarea after you have been there
     */
    SubArea(string areaTxt, string areaTxtVisited);

    /**
     * empty constructor
     */
    SubArea();

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
    //void setHasEncounter(bool hasEncounter);

    bool getOptionsIsEmpty();

    void addItem(int choiceIndex, item thing);

    void addToOptionsList(string option);

    void setOptionsList(vector<string> list);

    bool setOptionsText(vector<string> list);

    void addToOptionsText(string text);

    void setAreaText(string text);

    string getAreaText();

    vector<item> getItems();

    vector<string> getOptionsList();

    vector<string> getOptionsText();

    vector<bool> getIsSearched();

    void setDark(bool dark);

    bool getIsDark();

};
#endif //TXT_GAME_BQUACKEN_SUBAREA_H
