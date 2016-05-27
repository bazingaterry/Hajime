#include "iostream"
#include "queue"
using namespace std;

#define WHITE 1
#define BLACK 0

int t;
string s;

class Grid
{
public:
    bool fields[9];
    string op;
    Grid(const string& s)
    {
        for(int i = 0; i < 9; i++)
        {
            if(s[i] == 'b')
                fields[i] = BLACK;
            else
                fields[i] = WHITE;
        }
    }
    bool isFinish()
    {
        for (int i = 0; i < 9; ++i)
            if (fields[i] == BLACK) return false;
        return true;
    }
    void set(int array[], int size)
    {
        for(int i = 0; i < size; i++)
            fields[array[i]] ^= 1;
    }
};

void click(Grid &g, int index)
{
    switch(index)
    {
        case 1:
        {
            int change[4] = {0, 1, 3, 4};
            g.set(change, 4);
            break;
        }
        case 2:
        {
            int change[6] = {0, 1, 2, 3, 4, 5};
            g.set(change, 6);
            break;
        }
        case 3:
        {
            int change[4] = {1, 2, 4, 5};
            g.set(change, 4);
            break;
        }
        case 4:
        {
            int change[6] = {0, 1, 3, 4, 6, 7};
            g.set(change, 6);
            break;
        }
        case 5:
        {
            int change[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
            g.set(change, 9);
            break;
        }
        case 6:
        {
            int change[6] = {1, 2, 4, 5, 7, 8};
            g.set(change, 6);
            break;
        }
        case 7:
        {
            int change[4] = {3, 4, 6, 7};
            g.set(change, 4);
            break;
        }
        case 8:
        {
            int change[6] = {3, 4, 5, 6, 7, 8};
            g.set(change, 6);
            break;
        }
        case 9:
        {
            int change[4] = {4, 5, 7, 8};
            g.set(change, 4);
            break;
        }
    }
}

void game()
{
    cin >> s;
    queue<Grid> q;
    q.push(Grid(s));
    while(!q.empty())
    {
        for(int i = 1; i <= 9; i++)
        {
            Grid newGrid = q.front();
            click(newGrid, i);
            newGrid.op = q.front().op + (char)(i + '0');
            if(newGrid.isFinish())
            {
                cout << newGrid.op << endl;
                return;
            }
            q.push(newGrid);
        }
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    cin >> t;
    while(t--)
        game();
}
