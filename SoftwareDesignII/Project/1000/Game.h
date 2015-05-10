#ifndef _GAME_H
#define _GAME_H

#include "Dice.h"
#include "Player.h"
#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

const int NUMBER_OF_PLAYER = 2;
const int PLANE_OF_DICE = 6;

class Game : public Dice
{
public:
    Game(int sizeOfMap);
    ~Game();
    void start();
    void goAround();
    void printRound(const int indexOfPlayer) const;
    void printMap() const;
    
private:
    int getWin() const;	//	return the win player's index, if no return -1
    int sizeOfMap;
    int round;
    Player* listOfPlayer[NUMBER_OF_PLAYER];
};

Game::Game(int sizeOfMap):Dice(PLANE_OF_DICE), round(0)
{
    //	initialize map
    if (sizeOfMap < 1)
    {
        do
        {
            printf("Your input is invalid, please try again!\nInput N: ");
        }while(scanf("%d", &sizeOfMap) && sizeOfMap < 1);
    }
    this->sizeOfMap = sizeOfMap;
    
    //	initialize player
    string nameOfPlayer[NUMBER_OF_PLAYER] = {"A", "B"};	//	can modify players' name
    for (int i = 0; i < NUMBER_OF_PLAYER; ++i)
    {
        listOfPlayer[i] = new Player(nameOfPlayer[i]);
    }
}

Game::~Game()
{
    for (int i = 0; i < NUMBER_OF_PLAYER; ++i)
    {
        delete listOfPlayer[i];
        listOfPlayer[i] = NULL;
    }
}

void Game::printRound(const int indexOfPlayer) const
{
    printf("\nRound %d:", round);
    //  it is not first round
    if (round != 0)
    {
        printf("Player ");
        cout << listOfPlayer[indexOfPlayer]->getName();
        printf("'s turn\n");
    }
    printf("\n");
}

void Game::printMap() const
{
    //  nobody win
    if (getWin() == -1)	
    {
        //  print map
        for (int i = 0; i <= sizeOfMap; ++i)
        {
            printf("%-4d", i);
        }
        printf("\n");
        //  print player
        for (int i = 0; i < NUMBER_OF_PLAYER; ++i)	
        {
            for (int j = 0; j <= listOfPlayer[i]->getPosition() - 1; ++j)
            {
                printf("    ");
            }
            cout << listOfPlayer[i]->getName() << endl;
        }
        printf("\n");
    }
    //  print winer information
    else
    {
        cout << listOfPlayer[getWin()]->getName() << " win!\n\n";
    }
}



int Game::getWin() const
{
    for (int i = 0; i < NUMBER_OF_PLAYER; ++i)
    {
        if (listOfPlayer[i]->getPosition() > sizeOfMap)
        {
            return i;
        }
    }
    return -1;	// nobody win
}

void Game::goAround()
{
    //  find the index of player in this round
    int indexOfPlayer = (round - 1) % NUMBER_OF_PLAYER;

    //  print round
    printRound(indexOfPlayer);

    //  if it is not first round
    if (round != 0)
    {
        //  the first player's input is from stdin
        bool isRandom;
        if (indexOfPlayer == 0)
            isRandom = false;
        else
            isRandom = true;

        int diceNumber;
        //  throw dice
        if (isRandom)
        {
            diceNumber = ThrowDice();
            printf("Dice number: %d\n", diceNumber);
        }
        //  read from stdin
        else
        {   
            printf("Dice number: ");
            while(scanf("%d", &diceNumber) && !isValid(diceNumber))
            {
                printf("Your input is invalid, please try again!\nDice number: ");
            }
        }
        printf("\n");
        //  set player's position
        listOfPlayer[indexOfPlayer]->setPosition(listOfPlayer[indexOfPlayer]->getPosition() + diceNumber);
    }

    //  print map
    printMap();

    //  round add 1
    round++;
}

void Game::start()
{
    while(getWin() == -1)
    {
        goAround();
    }
}


#endif