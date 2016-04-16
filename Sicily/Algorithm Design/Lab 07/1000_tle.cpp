#include "iostream"
#include "iomanip"
#include "cstring"
using namespace std;

const int MAXGRAM = 10010;
const int MAXAMOUNT = 5010;
const int MAXKIND = 6;
double value[MAXGRAM];

struct Coin
{
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
    coins[2].money = 0.10;
    coins[2].weight = 2;
    coins[3].money = 0.25;
    coins[3].weight = 6;
    coins[4].money = 0.50;
    coins[4].weight = 11;
    coins[5].money = 1.00;
    coins[5].weight = 8;
}

inline int getWeight(int i)
{
    for (int index = 0; index < MAXKIND; ++index)
    {
        if (i > coins[index].amount)
            i -= coins[index].amount;
        else
            return coins[index].weight;
    }
}

inline double getMoney(int i)
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
        memset(value, 0, sizeof(value));
        for (int i = 0; i <= totalAmount; ++i)
            for (int w = W; w >= getWeight(i); --w)
                value[w] = max(value[w], value[w - getWeight(i)] + getMoney(i));
        cout << '$' << setprecision(2) << fixed << value[W] << endl;
    }
    return 0;
}
