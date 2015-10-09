#include "map"
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    while(cin >> N)
    {
        int hottest = 0;
        map<string, int> wordMap;
        while (N--)
        {
            string str;
            cin >> str;
            if (wordMap.count(str))
                wordMap[str]++;
            else
                wordMap[str] = 1;
            hottest = max(hottest, wordMap[str]);
        }
        cout << hottest << endl;
        for (map<string, int>::iterator i = wordMap.begin(); i != wordMap.end(); ++i)
        {
            if (i->second == hottest)
                cout << (i->first) << endl;
        }
    }
    return 0;
}