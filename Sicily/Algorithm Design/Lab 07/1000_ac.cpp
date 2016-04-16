#include "iostream"
#include "iomanip"
#include "cstring"
using namespace std;

const int MAXGRAM = 10010;
const int MAXAMOUNT = 5010;
const int MAXKIND = 6;
int W;
double f[MAXGRAM];

struct Coin
{
    double value;
    int weight;
    int amount;
} coins[MAXKIND];

void init()
{
    coins[0].value = 0.01;
    coins[0].weight = 3;
    coins[1].value = 0.05;
    coins[1].weight = 5;
    coins[2].value = 0.10;
    coins[2].weight = 2;
    coins[3].value = 0.25;
    coins[3].weight = 6;
    coins[4].value = 0.50;
    coins[4].weight = 11;
    coins[5].value = 1.00;
    coins[5].weight = 8;
}

void zeroOnePack(int weight, double value)
{
    for (int w = W; w >= weight; --w)
        f[w] = max(f[w], f[w - weight] + value);
}

void completePack(int weight, double value)
{
    for (int w = weight; w <= W; ++w)
        f[w] = max(f[w], f[w - weight] + value);
}

void multiplePack(double value, int weight, int amount)
{
    if (weight * amount >= W)
        completePack(weight, value);
    else
    {
        for (int k = 1; k < amount; k *= 2)
        {
            zeroOnePack(k * weight, k * value);
            amount -= k;
        }
        zeroOnePack(amount * weight, amount * value);
    }
}

int main(int argc, char const *argv[])
{
    init();
    while (cin >> W)
    {
        memset(f, 0, sizeof(f));
        for (int i = 0; i < MAXKIND; ++i)
        {
            cin >> coins[i].amount;
            multiplePack(coins[i].value, coins[i].weight, coins[i].amount);
        }
        cout << '$' << setprecision(2) << fixed << f[W] << endl;
    }
    return 0;
}
