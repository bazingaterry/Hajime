#include "iostream"
using namespace std;

int lowBou[4];
int upBou[4];
int rate[4];
int weight;
int price;
int delt;
int cnt = 1;

void init()
{
    cout << "Set number " << cnt++ << ":\n";
    lowBou[0] = 0;
    lowBou[1] = upBou[0] + 1;
    lowBou[2] = upBou[1] + 1;
    lowBou[3] = upBou[2] + 1;
    upBou[3] = 1000;
}

void findCheap()
{
    for (int i = 0; i < 4; ++i)
    {
        if (lowBou[i] <= weight && weight <= upBou[i])
        {
            price = weight * rate[i];
            delt = 0;
        }
        else if (weight < lowBou[i] && lowBou[i] * rate[i] < price)
        {
            delt = lowBou[i] - weight;
            price = lowBou[i] * rate[i];
        }
    }
}

void print()
{
    cout << "Weight (" << weight << ") has best price $"
         << price << " (add " << delt << " pounds)\n";
}

int main(int argc, char const *argv[])
{
    while (cin >> upBou[0] >> rate[0] >> upBou[1] >>
           rate[1] >> upBou[2] >> rate[2] >> rate[3])
    {
        init();
        while (cin >> weight && weight)
        {
            findCheap();
            print();
        }
        cout << endl;
    }
    return 0;
}
