//
//  Cell.cpp
//  LifeGame
//
//  Created by terrychan on 15/10/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "Cell.hpp"

Cell::Cell()
{
	this->status = dead;
}

void Cell::setStatus(const cellStatus _status)
{
	this->status = _status;
}

cellStatus Cell::getStatus() const
{
	return status;
}
