//
//  LifeGame.hpp
//  LifeGame
//
//  Created by terrychan on 15/10/9.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef LifeGame_hpp
#define LifeGame_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include "CellMap.hpp"
#include "NeighbourMap.hpp"

class LifeGame
{
public:
    LifeGame(std::string mapAddress, std::string outPutAddress, bool isDebug);
    void run(unsigned int times);
    
private:
    std::string mapAddress, outPutAddress;
    bool isDebug;
    CellMap cellMap;
    NeighbourMap neighbourMap;
};

#endif /* LifeGame_hpp */
