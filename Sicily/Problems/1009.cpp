#include "iostream"
#include "vector"
using namespace std;

const int M = 64;
bool isPrimes[M + 1];
vector<int> primes;
vector<long long> pf;

void genPrimes()
{
    for(int i = 0; i < M + 1; i++)
    {
        isPrimes[i] = true;
    };
    isPrimes[0] = false;
    isPrimes[1] = false;
    for(int i = 2; i < M + 1; i++)
    {
        if(isPrimes[i])
            for(int j = i * 2; j < M + 1; j += i)
                isPrimes[j] = false;
    }
    for(int i = 0; i < M + 1; i++)
    {
        if(isPrimes[i])
            primes.push_back(i);
    }
}

void factor(int prime)
{
    long long base = 1;
    long long mersenne = (base << prime) - 1;
    long long i;
    for(i = 3; i * i <= mersenne; i += 2)
    {
        while(mersenne % i == 0)
        {
            mersenne /= i;
            pf.push_back(i);
        }
    }
    if(mersenne > 1)
    {
        pf.push_back(mersenne);
    }
}

void printInfo(long long mersenne, int prime)
{
    int size = pf.size();
    for(int i = 0; i < size - 1; i++)
    {
        cout << pf[i] << " * ";
    }
    cout << pf[size - 1] << " = ";
    cout << mersenne << " = ( 2 ^ " << prime << " ) - 1";
    cout << endl;
}

void getMersennes(const int minK)
{
    int size = primes.size();
    for(int i = 0; i < size - 1 && primes[i] <= minK; i++)
    {

        int prime = primes[i];
        factor(prime);
        if(pf.size() > 1)
        {
            long long base = 1;
            long long mersenne = (base << prime) - 1;
            printInfo(mersenne, prime);
        }
        pf.clear();
    }
}

int main(int argc, char const *argv[])
{
    genPrimes();
    int k;
    cin >> k;
    getMersennes(k);
    return 0;
}
