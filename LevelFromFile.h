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
    AreaTemplate buildArea(string file);

};

#endif //TXT_GAME_BQUACKEN_LEVELFROMFILE_H
