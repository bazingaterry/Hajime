//
//  CellMap.cpp
//  LifeGame
//
//  Created by terrychan on 15/10/7.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "CellMap.hpp"
#include "fstream"
#include <cstdio>

#define CELL_CHAR '+'
#define CELL_STR "+"

CellMap::CellMap() : Map()
{
    
}

CellMap::~CellMap()
{

}

void CellMap::save(const std::string fileAddress) const
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
            if (getCellStatus(creatCoordinate(col, row)) == alive)
                saveFile << CELL_CHAR;
            else
                saveFile << ' ';
        }
        saveFile << '\n';
    }
    saveFile.close();
}

void CellMap::printMap() const
{
    for (int row = this->getSize(0); row >= this->getSize(1); --row)
    {
        for (int col = this->getSize(2); col <= this->getSize(3); ++col)
        {
            if (getCellStatus(creatCoordinate(col, row)) == alive)
                printf(CELL_STR);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void CellMap::generateNext(const NeighbourMap& neighbourMap)
{
    for (int row = neighbourMap.getSize(0); row >= neighbourMap.getSize(1); --row)
    {
        for (int col = neighbourMap.getSize(2); col <= neighbourMap.getSize(3); ++col)
        {
            int neighbour = neighbourMap.getNeighbour(neighbourMap.creatCoordinate(col, row));
            cellStatus status = cellMapData[creatCoordinate(col, row)].getStatus();
            if (neighbour <= 1 || neighbour >= 4)
            {
                cellMapData[creatCoordinate(col, row)].setStatus(dead);
            }
            else if (status == dead && neighbour == 3)
            {
                cellMapData[creatCoordinate(col, row)].setStatus(alive);
            }
        }
    }
}

void CellMap::initialize(const std::string fileAddress)
{
    std::ifstream openFile(fileAddress);
    if (!openFile)
        return;
    char character;
    int col = 0, row = 0;
    while ((character = openFile.get()) != EOF)
    {
        if (character == CELL_CHAR)
        {
            cellMapData[creatCoordinate(col++, row)].setStatus(alive);
        }
        else if (character == ' ')
        {
            cellMapData[creatCoordinate(col++, row)].setStatus(dead);
        }
        else if (character == '\n')
        {
            row--;
            col = 0;
        }
    }
    openFile.close();
}

cellStatus CellMap::getCellStatus(const Coordinate& coordinate) const
{
    auto iterator = cellMapData.find(coordinate);
    if (iterator == cellMapData.end())
        return dead;
    else
        return iterator->second.getStatus();
}