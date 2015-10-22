#ifndef _PLAYER_LIST_H
#define _PLAYER_LIST_H 

#include "Player.h"
#include <stdexcept>
#include <iostream>
using std::cin;
using std::out_of_range;

class PlayerList
{
public:
    PlayerList();								//	empty list is created by default
    bool create(const int size);				//	creat a player list, if succeed return true, else return false
    bool destroy();                              //  destroy the player list
    ~PlayerList();
    Player& operator[] (const int index) const;		//	use [] to reach the player
    int getSize() const;

private:
    Player** listPtr;								
    int size;									//	size of the list
};

PlayerList::PlayerList()
{
    this->size = 0;
    listPtr = NULL;
}

bool PlayerList::create(const int size)
{
    if(this->size != 0) //  the list is not empty or invalid
    {
        return false;
    }
    else
    {
        this->size = size;
        listPtr = new Player*[size];
        for (int i = 0; i < size; ++i)
        {
            printf("\n");
            printf("Please input player%d's name: ", i);
            string name;
            cin >> name;

            printf("Is it a AI?(Yes or No)\n");
            string isAI;
            cin >> isAI;
            while (isAI != "Yes" && isAI != "No")
            {
                printf("Please input again\nIs it a AI?(Yes or No)\n");
                cin >> isAI;
            }
            if (isAI == "Yes")
            {
                listPtr[i] = new AI(name);
            }
            else
            {
                listPtr[i] = new Human(name);
            }
        }
        return true;
    }
}

bool PlayerList::destroy()
{
    if (listPtr == NULL)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            delete listPtr[i];
            listPtr[i] = NULL;
        }
        delete[] listPtr;
        listPtr = NULL;
        return true;
    }
}

PlayerList::~PlayerList()
{
    destroy();
}

Player& PlayerList::operator[] (const int index) const
{
    if (0 <= index && index <= size - 1)
    {
        return *listPtr[index];
    }
    //  out of boundry
    else
    {
        throw out_of_range("Out of boundry exeception");
    }
}

int PlayerList::getSize() const
{
    return size;
}

#endif
