//
//  Map.cpp
//  LifeGame
//
//  Created by terrychan on 15/10/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "Map.hpp"

Map::Map()
{
	upperBound = 0;
	lowerBound = 0;
	leftBound = 0;
	rightBound = 0;
}

Map::~Map()
{

}

int Map::getSize(int index) const
{
	switch (index)
	{
		case 0 : return upperBound;
		case 1 : return lowerBound;
		case 2 : return leftBound;
		case 3 : return rightBound;
		default : return 0;
	}
}

Coordinate Map::creatCoordinate(const int x, const int y)
{
//	change boundary
	if (x < leftBound)
	{
		leftBound = x;
	}
	else if (x > rightBound)
	{
		rightBound = x;
	}
	if (y < lowerBound)
	{
		lowerBound = y;
	}
	else if (y > upperBound)
	{
		upperBound = y;
	}

//	return coordinate
	Coordinate coordinate(x, y);
	return coordinate;
}

Coordinate Map::creatCoordinate(const int x, const int y) const
{
	Coordinate coordinate(x, y);
	return coordinate;
}


