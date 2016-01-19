#include "string"
#include "iostream"
#include "cmath"
using namespace std;

const int SIZE = 2187;
char graph[SIZE][SIZE];

void init()
{
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            graph[i][j] = ' ';
}

void creat(int x, int y, int size)
{
    if (size == 3)
    {
        for (int i = x; i < x + 3; ++i)
            for (int j = y; j < y + 3; ++j)
                graph[i][j] = '#';
        graph[x + 1][y + 1] = ' ';
    }
    else
    {
        int block_size = size / 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i != 1 || j != 1)
                {
                    creat(x + i * block_size, y + j * block_size, block_size);
                }
            }
        }
        
    }
}

void print(int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            cout << graph[i][j];
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    init();
    int n;
    cin >> n;
    int size = pow(3, n);
    creat(0, 0, size);
    print(size);
    return 0;
}