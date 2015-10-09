#ifndef _GAME_H
#define _GAME_H

#include "Dice.h"
#include "PlayerList.h"
#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

class Game
{
public:
    Game();
    ~Game();
    void start();

private:
    int getWin() const;	//	return the win player's index, if no return -1
    void goARound();
    void printRound(const int indexOfPlayer) const;
    void printMap() const;
    int mapSize;
    int round;
    PlayerList playerList;
    Dice dice;
};

Game::Game() : round(0)
{
    //  initialize map
    int mapSize;
    printf("Please input map size: ");
    scanf("%d", &mapSize);
    while(mapSize < 1)
    {
        printf("Your input is invalid, please try again!\nPlease input map size: ");
        scanf("%d", &mapSize);
    }
    this->mapSize = mapSize;

    //  initialize plane of dice
    int plane;
    printf("Please input plane of dice: ");
    scanf("%d", &plane);
    while(plane < 1)
    {
        printf("Your input is invalid, please try again!\nPlease input plane of dice: ");
        scanf("%d", &plane);
    }
    dice.setPlane(plane);

    //  initialize player
    int player;
    printf("How many players?\n");
    scanf("%d", &player);
    while(player < 2)
    {
        printf("Your input is invalid, please try again!\nHow many players?\n");
        scanf("%d", &player);
    }
    playerList.create(player);
}

Game::~Game()
{
    printf("Dice Game Exit\nSee you next time!\n");
}

void Game::printRound(const int indexOfPlayer) const
{
    printf("\nRound %d:", round);
    //  it is not first round
    if (round != 0)
    {
        printf("Player ");
        cout << playerList[indexOfPlayer].getName();
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
        for (int i = 0; i <= mapSize; ++i)
        {
            printf("%-6d", i);
        }
        printf("\n");
        //  print player
        for (int i = 0; i < playerList.getSize(); ++i)  
        {
            for (int j = 0; j <= playerList[i].getPosition() - 1; ++j)
            {
                printf("      ");
            }
            cout << playerList[i].getName() << endl;
        }
        printf("\n");
    }
    //  print winer information
    else
    {
        cout << playerList[getWin()].getName() << " win!\n\n";
    }
}



int Game::getWin() const
{
    for (int i = 0; i < playerList.getSize(); ++i)
    {
        if (playerList[i].getPosition() > mapSize)
        {
            return i;
        }
    }
    return -1;  // nobody win
}

void Game::goARound()
{
    //  find the index of player in this round
    int indexOfPlayer = (round - 1) % playerList.getSize();

    //  print round
    printRound(indexOfPlayer);

    //  if it is not first round
    if (round != 0)
    {
        //  throw dice
        playerList[indexOfPlayer].throwDice(dice);
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
        goARound();
    }
}

#endif
