struct Position
{
         int x;
         int y;
};

class Robot
{
public:
    Robot();                           /* default constructor, initialize at (0,0) */
    Robot(Position pos);     /* initialize at pos */
    void Move(char Dir);     /* Dir could be 'N', 'E', 'S', 'W', for other characters, the robot don’t move */
    Position GetPosition();        /* return current position */
private:
    Position currentPos;
};

Robot::Robot()
{
    currentPos.x = 0;
    currentPos.y = 0;
}

Robot::Robot(Position pos)
{
    currentPos.x = pos.x;
    currentPos.y = pos.y;
}

void Robot::Move(char Dir)
{
    if (Dir == 'N')
    {
        currentPos.y++;
    }
    else if (Dir == 'E')
    {
        currentPos.x++;
    }
    else if (Dir == 'S')
    {
        currentPos.y--;
    }
    else if (Dir == 'W')
    {
        currentPos.x--;
    }
}

Position Robot::GetPosition()
{
    return currentPos;
}