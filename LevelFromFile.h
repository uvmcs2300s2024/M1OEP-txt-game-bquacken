#ifndef TXT_GAME_BQUACKEN_LEVELFROMFILE_H
#define TXT_GAME_BQUACKEN_LEVELFROMFILE_H

#include <iostream>
#include <vector>
#include "AreaTemplate.h"
#include "string"
#include "player.h"
using std::string,std::cout,std::endl;

class LevelFromFile{
public:
    /**
     * takes a file with specific formatting and
     * creates a level of the text game
     * @param file the file that is read from
     */
    AreaTemplate buildArea(string file);

    SubAreaTemplate buildSubArea(ifstream& inFile);

    SubAreaTemplate buildOption(ifstream& inFile);

    string readText(ifstream& inFile);

    vector<string> readOptions(ifstream& inFile);

    item readItem(ifstream& inFile);

};

#endif //TXT_GAME_BQUACKEN_LEVELFROMFILE_H
