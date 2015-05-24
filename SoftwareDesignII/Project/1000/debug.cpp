#include "Game.h"

int main(int argc, char const *argv[])
{
    Dice dice;
    dice.setPlane(6);
    while(true)
    	cout << dice.throwDice() << " ";
    return 0;
}
