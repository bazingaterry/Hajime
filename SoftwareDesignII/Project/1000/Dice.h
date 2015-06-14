#ifndef _DICE_H
#define _DICE_H

#include <cstdio>
#include <cstdlib>
#include <ctime>

class Dice
{
public:
    Dice(const int plane = 0);
    int throwDice();		                  //	return a random dice number
    int getPlane() const;
    bool isValid(const int diceNumber) const;
    bool setPlane(const int plane);           /*    set the plane, only can be used when the plane has not been set
                                                    if set successfully it will return true, else false
                                              */
private:
    int plane;					            //	the plane of the dice
};

bool Dice::setPlane(const int plane)
{
    if (this->plane != 0 || plane <= 0)
    {
        return false;
    }
    else
    {
        this->plane = plane;
        return true;
    }
}

Dice::Dice(const int plane)
{
    if (plane > 0)
        this->plane = plane;
    else
        this->plane = 0;
    srand((unsigned)time(NULL));
}

int Dice::throwDice()
{
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
