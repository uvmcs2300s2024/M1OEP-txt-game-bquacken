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

    /**
     * returns if the optionsList is empty
     * @return if the option list is empty
     */
    bool getOptionsIsEmpty();

    /**
     * adds an item using the inputted choice index which is
     * the index in optionsList of the chosen option that will
     * give the player the item
     * @param choiceIndex the optionsList index that the items
     * go in
     * @param thing the item added to the list
     */
    void addItem(int choiceIndex, item thing);

    /**
     * adds a string to optionsList
     * @param option the string added to the end of
     * the list
     */
    void addToOptionsList(string option);

    /**
     * sets optionsList to list
     * @param list what options List becomes
     */
    void setOptionsList(vector<string> list);

    /**
     * sets the options text to list
     * @param list the new optionText
     * @return if the list was accepted
     */
    bool setOptionsText(vector<string> list);

    /**
     * adds a string to the end of optionsText
     * @param text the string added to the end
     * of the vector
     */
    void addToOptionsText(string text);

    /**
     * sets the main text of the area
     * @param text the new areaText
     */
    void setAreaText(string text);

    /**
     * returns the areaText
     * @return areaText
     */
    string getAreaText();

    /**
     * returns the vector of items
     * @return all items for the subarea
     */
    vector<item> getItems();

    /**
     * returns optionsList
     * @return optionsList
     */
    vector<string> getOptionsList();

    /**
     * returns optionsText
     * @return optionsText
     */
    vector<string> getOptionsText();

    /**
     * returns the isSearched vector
     * @return isSearched
     */
    vector<bool> getIsSearched();

    /**
     * set if the subarea needs a lamp
     * to see and interact
     * @param dark if the area is dark
     */
    void setDark(bool dark);

    /**
     * returns if the area is dark or not
     * @return isDark
     */
    bool getIsDark();

};
#endif //TXT_GAME_BQUACKEN_SUBAREA_H
