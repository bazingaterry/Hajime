#ifndef _DICE_H
#define _DICE_H

#include <cstdio>
#include <cstdlib>
#include <ctime>

class Dice
{
public:
    Dice(const int plane);
    int ThrowDice();		//	return a random dice number
    int getPlane() const;
    bool isValid(const int diceNumber) const;
    
private:
    int plane;					            //	the plane of the dice
};

Dice::Dice(const int plane)
{
    this->plane = plane;
}

int Dice::ThrowDice()
{
    srand((unsigned)time(NULL));	//	use time as seed
    return rand() % plane + 1;
}

int Dice::getPlane() const
{
    return plane;
}

bool Dice::isValid(const int diceNumber) const
{
    return 1 <= diceNumber && diceNumber <= plane;
}

#endif