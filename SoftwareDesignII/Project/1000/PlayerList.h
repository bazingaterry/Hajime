#ifndef _PLAYER_LIST_H
#define _PLAYER_LIST_H 

#include "Player.h"
#include <iostream>
using std::cin;
using std::cerr;

const int MAXSIZE = 100;

class PlayerList
{
public:
    PlayerList();								//	empty list is created by default
    bool create(const int size);				//	creat a player list, if succeed return true, else return false
    ~PlayerList();
    Player& operator[] (const int index) const;		//	use [] to get the player
    int getSize() const;

private:
    Player* listPtr[MAXSIZE];								
    int size;									//	size of the list
};

PlayerList::PlayerList()
{
	this->size = 0;
}

bool PlayerList::create(const int size)
{
    if(this->size != 0 || size > MAXSIZE)	//	the list is not empty or invalid
    {
	    return false;
	}
	else
	{
		this->size = size;
	    for (int i = 0; i < size; ++i)
	    {
	        printf("Please input player%d's name: ", i);
	        string name;
	        cin >> name;
	        listPtr[i] = new Player(name);
	    }
	    return true;
	}
}

PlayerList::~PlayerList()
{
    for (int i = 0; i < size; ++i)
    {
    	delete listPtr[i];
	    listPtr[i] = NULL;
    }
}

Player& PlayerList::operator[] (const int index) const
{
	if (0 <= index && index <= size - 1)
	{
		return *listPtr[index];
	}
	//	out of boundry
	else
	{
		cerr << "Out of boundry!\n";
	}
}

int PlayerList::getSize() const
{
	return size;
}

#endif
