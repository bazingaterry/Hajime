//
//  Cell.hpp
//  LifeGame
//
//  Created by terrychan on 15/10/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

enum cellStatus
{
	dead = 0,
	alive = 1
};

class Cell
{
public:
	Cell();	//	cell is dead by default when it is created
	void setStatus(const cellStatus _status);
	cellStatus getStatus() const;

private:
	cellStatus status;
};

#endif /* Cell_hpp */
