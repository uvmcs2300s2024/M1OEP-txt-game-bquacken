//
// Created by Benjamin Quackenbush on 2/16/2024.
//

#ifndef TXT_GAME_BQUACKEN_AREA_H
#define TXT_GAME_BQUACKEN_AREA_H
#include <iostream>
#include <vector>
#include "SubArea.h"
using std::string,std::cout,std::endl,std::vector;

class Area{
private:
    string mainText;
    vector<SubArea> subAreas;
    vector<string> options;

public:
    /**
     * constructor
     * @param mainText sets the mainText string
     * @param subAreas sets the subAreas vector
     * @param options sets the options vector
     */
    Area(string mainText, vector<SubArea> subAreas,
         vector<string> options);

    /**
     * default constructor;
     */
    Area();

    /**
     * runs the area allowing the player to explore
     * @param p the player
     */
    void run(player& p);

    /**
     * gets the subAreas vector
     * @return subAreas vector
     */
    vector<SubArea> getSubAreas();

    /**
     * gets the options vector
     * @return the options vector
     */
    vector<string> getOptions();

    /**
     * adds a subarea to the subAreas vector
     * @param pSubArea the new subarea
     */
    void addSubArea(SubArea pSubArea);

    void addToOptionsList(string option);

    void addMainText(string text);

    void setOptionsList(vector<string> list);

    string getMainText();


};

#endif //TXT_GAME_BQUACKEN_AREA_H
