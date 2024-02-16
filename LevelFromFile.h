#ifndef TXT_GAME_BQUACKEN_LEVELFROMFILE_H
#define TXT_GAME_BQUACKEN_LEVELFROMFILE_H

#include <iostream>
#include <vector>
#include "string"
#include "player.h"
using std::string,std::cout,std::endl;

class LevelFromFile{
private:
    string file;
    locations area;
    vector<string> areaOptions;

public:

    LevelFromFile(string file){
        this -> file = file;
    }


};

#endif //TXT_GAME_BQUACKEN_LEVELFROMFILE_H
