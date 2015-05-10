#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
using std::string;

class Player
{
public:
    Player(const string name);
    string getName() const;
    int getPosition() const;
    void setPosition(const int position);
    
private:
    string name;
    int position;
};

Player::Player(const string name)
{
    this->name = name;
    position = 0;
}

string Player::getName() const
{
    return name;
}

int Player::getPosition() const
{
    return position;
}

void Player::setPosition(const int position)
{
    this->position = position;
}

#endif