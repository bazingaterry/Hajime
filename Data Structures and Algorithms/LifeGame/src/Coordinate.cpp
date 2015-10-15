//
//  Coordinate.cpp
//  LifeGame
//
//  Created by terrychan on 15/10/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "Coordinate.hpp"

Coordinate::Coordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Coordinate::operator= (const Coordinate& coordinate)
{
    this->x = coordinate.getX();
    this->y = coordinate.getY();
}

bool Coordinate::operator< (const Coordinate& _coordinate) const
{
	if (this->x < _coordinate.getX())
	{
		return true;
	}
	else if (this->x > _coordinate.getX())
	{
		return false;
	}
	else if (this->y < _coordinate.getY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Coordinate::getX() const
{
	return x;	
}

int Coordinate::getY() const
{
	return y;
}

void Coordinate::setX(const int x)
{
	this->x = x;
}

void Coordinate::setY(const int y)
{
	this->y = y;
}