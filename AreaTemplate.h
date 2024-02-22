//
// Created by Benjamin Quackenbush on 2/16/2024.
//

#ifndef TXT_GAME_BQUACKEN_AREATEMPLATE_H
#define TXT_GAME_BQUACKEN_AREATEMPLATE_H

#include <iostream>
#include <vector>
#include "string.h"
#include "input.h"
#include "Enemy.h"
using std::string,std::cout,std::endl,std::vector;

class AreaTemplate{
private:
    string mainText;
    vector<SubAreaTemplate> subAreas;
    vector<string> options;

public:
    /**
     * constructor
     * @param mainText sets the mainText string
     * @param subAreas sets the subAreas vector
     * @param options sets the options vector
     */
    AreaTemplate(string mainText, vector<SubAreaTemplate> subAreas,
                 vector<string> options);

    /**
     * default constructor;
     */
    AreaTemplate();

    /**
     * runs the area allowing the player to explore
     * @param p the player
     */
    void run(player& p);

    /**
     * gets the subAreas vector
     * @return subAreas vector
     */
    vector<SubAreaTemplate> getSubAreas();

    /**
     * gets the options vector
     * @return the options vector
     */
    vector<string> getOptions();

    /**
     * adds a subarea to the subAreas vector
     * @param pSubArea the new subarea
     */
    void addSubArea(SubAreaTemplate pSubArea);

    void addToOptionsList(string option);

    void addMainText(string text);

    void addOption(string optionText, string optionTextVisited, item reward);

    void setOptionsList(vector<string> list);

};

#endif //TXT_GAME_BQUACKEN_AREATEMPLATE_H
