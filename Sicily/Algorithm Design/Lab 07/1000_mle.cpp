#include "iostream"
#include "iomanip"
using namespace std;

const int MAXGRAM = 10010;
const int MAXAMOUNT = 10010;
const int MAXKIND = 6;
double c[MAXAMOUNT][MAXGRAM];

class Coin
{
public:
    double money;
    int weight;
    int amount;
} coins[MAXKIND];

void init()
{
    coins[0].money = 0.01;
    coins[0].weight = 3;
    coins[1].money = 0.05;
    coins[1].weight = 5;
    coins[2].money = 0.1;
    coins[2].weight = 2;
    coins[3].money = 0.25;
    coins[3].weight = 6;
    coins[4].money = 0.5;
    coins[4].weight = 11;
    coins[5].money = 1;
    coins[5].weight = 8;
}

int getWeight(int i)
{
    for (int index = 0; index < MAXKIND; ++index)
    {
        if (i > coins[index].amount)
            i -= coins[index].amount;
        else
            return coins[index].weight;
    }
}

double getMoney(int i)
{
    for (int index = 0; index < MAXKIND; ++index)
    {
        if (i > coins[index].amount)
            i -= coins[index].amount;
        else
            return coins[index].money;
    }
}

int main(int argc, char const *argv[])
{
    init();
    int W;
    while (cin >> W)
    {
        int totalAmount = 0;
        for (int i = 0; i < MAXKIND; ++i)
        {
            cin >> coins[i].amount;
            totalAmount += coins[i].amount;
        }
        for (int w = 0; w <= W; ++w)
            c[0][w] = 0;
        for (int i = 1; i <= totalAmount; ++i)
        {
            c[i][0] = 0;
            for (int w = 1; w <= W; ++w)
            {
                if (getWeight(i) <= w)
                    c[i][w] = max(c[i - 1][w - getWeight(i)] + getMoney(i), c[i-1][w]);
                else
                    c[i][w] = c[i - 1][w];
            }
        }
        cout << '$' << setprecision(2) << fixed << c[totalAmount][W] << endl;
    }
    return 0;
}
