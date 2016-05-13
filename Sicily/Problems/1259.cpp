#include "iostream"
#include "cstring"
#include "vector"
using namespace std;

const int MAX = 10000;
bool isPrime[10001];
vector<int> primeNum;

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = true; isPrime[1] = false;
    for(int i = 2; i < MAX; i++)
        if(isPrime[i] == true)
            for(int j = 2; i * j <= MAX; j++)
                isPrime[i * j] = false;


    for(int i = 2; i < MAX; i++)
        if(isPrime[i]) primeNum.push_back(i);
}

int main(int argc, char const *argv[])
{
    int n;
    init();
    while(cin >> n && n != 0)
    {
        int cnt = 0;
        for(int i = 0; i < primeNum.size(); i++)
        {
            int sum = primeNum[i];
            if(primeNum[i] == n) cnt++;
            for(int j = i + 1; sum <= n; j++)
            {
                sum += primeNum[j];
                if(sum == n) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

