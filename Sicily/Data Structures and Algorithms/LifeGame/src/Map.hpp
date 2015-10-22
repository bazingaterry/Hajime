//
//  Map.hpp
//  LifeGame
//
//  Created by terrychan on 15/10/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <map>
#include <string>
#include "Coordinate.hpp"
#include "Cell.hpp"

/********************************************************************
	in each Map Class, the size of map is stored in 
	"upperBound, lowerBound, leftBound, rightBound"
	and the function creatCoordinate() will update the size automatically.
*********************************************************************/

class Map
{
public:
	Map();
	~Map();
//	Load and Save APIs
	void virtual save(const std::string fileAddress) const = 0;

//	Print APIs
	void virtual printMap() const = 0;

//	get size API, 0 1 2 3 means upperBound, lowerBound, leftBound, rightBound.
	int getSize(const int index) const;

//  all operation of map must use creatCoordinate function
    Coordinate creatCoordinate(const int x, const int y);
    Coordinate creatCoordinate(const int x, const int y) const;
    
protected:
	int upperBound, lowerBound, leftBound, rightBound;
};

#endif /* Map_hpp */
