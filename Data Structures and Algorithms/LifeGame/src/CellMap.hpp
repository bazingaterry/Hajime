//
//  CellMap.hpp
//  LifeGame
//
//  Created by terrychan on 15/10/7.
//  Copyright © 2015年 terrychan. All rights reserved.
//


#ifndef CellMap_hpp
#define CellMap_hpp

#include "Map.hpp"
#include "NeighbourMap.hpp"
#include "Cell.hpp"

class NeighbourMap;

class CellMap : public Map
{
public:
    CellMap();
    ~CellMap();
    void save(const std::string fileAddress) const;
    void printMap() const;
    void generateNext(const NeighbourMap& neighbourMap);
    void initialize(const std::string fileAddress);
    cellStatus getCellStatus(const Coordinate& coordinate) const;
    
private:
    std::map<Coordinate, Cell> cellMapData;
};

#endif /* CellMap_hpp */
