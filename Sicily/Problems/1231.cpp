#include "iostream"
#include "string"
#include "cstring"
#include "vector"
using namespace std;

const int MAX = 1000001;
bool isPrime[MAX];
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

inline bool isMod(const string& s, int n)
{
    int res = 0;
    for(int i = 0; i < s.size(); i++)
        res = (res * 10 + s[i] - '0') % n;
    return !res;
}

int check(const string& s, int l)
{
    for(int i = 0; i < primeNum.size(); i++)
        if(primeNum[i] < l && isMod(s, primeNum[i])) return primeNum[i];
    return 0;
}

int main(int argc, char const *argv[])
{
    string s;
    int l;
    init();
    while(cin >> s >> l && (s[0] != '0' && l))
    {
        int mod = check(s, l);
        if (mod) cout << "BAD" << ' ' << mod << endl;
        else cout << "GOOD\n";
    }
    return 0;
}
