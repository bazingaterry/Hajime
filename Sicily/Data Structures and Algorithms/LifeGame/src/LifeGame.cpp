//
//  LifeGame.cpp
//  LifeGame
//
//  Created by terrychan on 15/10/9.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "LifeGame.hpp"

#define DEBUG_ADDRESS "debug"

LifeGame::LifeGame(std::string mapAddress, std::string outPutAddress, bool isDebug)
{
    this->mapAddress = mapAddress;
    this->outPutAddress = outPutAddress;
    this->isDebug = isDebug;
    cellMap.initialize(mapAddress);
    std::ofstream outPutData(outPutAddress);
    outPutData << "Map address:" << mapAddress << std::endl << "\nOriginal Map:" << std::endl;
    cellMap.save(outPutAddress);
    outPutData << std::endl;
    outPutData.close();
    if (isDebug)
    {
        // clear debug file
        std::ofstream debugData(DEBUG_ADDRESS);
        debugData.close();
    }
}

void LifeGame::run(unsigned int times)
{
    for (int i = 1; i <= times; i++)
    {
        neighbourMap.initialize(cellMap);
        cellMap.generateNext(neighbourMap);
        std::ofstream outPutData(outPutAddress, std::ios::app);
        outPutData << "Generation: " << i << std::endl;
        cellMap.save(outPutAddress);
        outPutData << '\n';
        outPutData.close();
        
        if (isDebug)
        {
            std::ofstream debugData(DEBUG_ADDRESS, std::ios::app);
            debugData << "Generation: " << i << std::endl;
            neighbourMap.save(DEBUG_ADDRESS);
            debugData << '\n';
            debugData.close();
        }
        // clear neighbour map
        neighbourMap.reset();
    }
}