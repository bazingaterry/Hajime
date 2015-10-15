//
//  Coordinate.hpp
//  LifeGame
//
//  Created by terrychan on 15/10/5.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#ifndef Coordinate_hpp
#define Coordinate_hpp

class Coordinate
{
public:
    Coordinate(int x, int y);
    void operator= (const Coordinate& coordinate);
    bool operator< (const Coordinate& _coordinate) const;
    int getX() const;
    int getY() const;
    void setX(const int x);
    void setY(const int y);
private:
    int x, y;
};

#endif /* Coordinate_hpp */
