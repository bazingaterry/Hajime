//
//  NeighbourMap.hpp
//  LifeGame
//
//  Created by terrychan on 15/10/7.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef NeighbourMap_hpp
#define NeighbourMap_hpp

#include <fstream>
#include "Map.hpp"
#include "Cell.hpp"
#include "CellMap.hpp"

class CellMap;

class NeighbourMap : public Map
{
public:
    NeighbourMap();
    ~NeighbourMap();
    void printMap() const;
    void save(const std::string fileAddress) const;
    void initialize(const CellMap& cellMap);
    void reset();
    int getNeighbour(const Coordinate& coordinate) const;
    
private:
    std::map<Coordinate, int> neighbourMapData;
};

#endif /* NeighbourMap_hpp */
