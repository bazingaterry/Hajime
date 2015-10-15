//
//  NeighbourMap.cpp
//  LifeGame
//
//  Created by terrychan on 15/10/7.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "NeighbourMap.hpp"

NeighbourMap::NeighbourMap() : Map()
{
    
}

NeighbourMap::~NeighbourMap()
{
    
}

void NeighbourMap::printMap() const
{
    for (int row = this->getSize(0); row >= this->getSize(1); --row)
    {
        for (int col = this->getSize(2); col <= this->getSize(3); ++col)
        {
            printf("%d", getNeighbour(creatCoordinate(col, row)));
        }
        printf("\n");
    }
}

void NeighbourMap::save(const std::string fileAddress) const
{
    std::ofstream saveFile(fileAddress, std::ios::app);
    if (!saveFile)  //  if openfile fail
    {
        return;
    }
    for (int row = this->getSize(0); row >= this->getSize(1); --row)
    {
        for (int col = this->getSize(2); col <= this->getSize(3); ++col)
        {
            saveFile << getNeighbour(creatCoordinate(col, row));
        }
        saveFile << '\n';
    }
    saveFile.close();
}

void NeighbourMap::initialize(const CellMap& cellMap)
{
    for (int row = cellMap.getSize(0); row >= cellMap.getSize(1); --row)
    {
        for (int col = cellMap.getSize(2); col <= cellMap.getSize(3); ++col)
        {
            if (cellMap.getCellStatus(cellMap.creatCoordinate(col, row)) == alive)
            {
                neighbourMapData[creatCoordinate(col - 1, row - 1)]++;
                neighbourMapData[creatCoordinate(col - 1, row)]++;
                neighbourMapData[creatCoordinate(col - 1, row + 1)]++;
                neighbourMapData[creatCoordinate(col, row - 1)]++;
                neighbourMapData[creatCoordinate(col, row + 1)]++;
                neighbourMapData[creatCoordinate(col + 1, row - 1)]++;
                neighbourMapData[creatCoordinate(col + 1, row)]++;
                neighbourMapData[creatCoordinate(col + 1, row + 1)]++;
            }
        }
    }
}

void NeighbourMap::reset()
{
    upperBound = 0;
    lowerBound = 0;
    leftBound = 0;
    rightBound = 0;
    neighbourMapData.clear();
}

int NeighbourMap::getNeighbour(const Coordinate& coordinate) const
{
    auto iterator = neighbourMapData.find(coordinate);
    if (iterator == neighbourMapData.end())
        return 0;
    else
        return iterator->second;
}