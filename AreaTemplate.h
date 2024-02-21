//
// Created by Benjamin Quackenbush on 2/16/2024.
//

#ifndef TXT_GAME_BQUACKEN_AREATEMPLATE_H
#define TXT_GAME_BQUACKEN_AREATEMPLATE_H

#include <iostream>
#include <vector>
#include "string.h"
#include "Enemy.h"
using std::string,std::cout,std::endl,std::vector;

class AreaTemplate{
private:
    string mainText;
    vector<SubAreaTemplate> subAreas;
    vector<string> options;

public:
    AreaTemplate(string mainTxt, vector<SubAreaTemplate> subAreas,
                 vector<string> options);

    void init();

    vector<SubAreaTemplate> getSubAreas();

    vector<string> getOptions();

};

#endif //TXT_GAME_BQUACKEN_AREATEMPLATE_H
