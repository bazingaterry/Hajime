#include "iostream"
#include "map"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n)
    {
        string name, ip;
        map<string, string> main, mj;
        for (int i = 0; i < n; ++i)
        {
            cin >> name >> ip;
            map<string, string>::iterator it = mj.find(ip);
            if (it == mj.end()) //  not found
                mj[ip] = name;
            else
                main[it->second] = name;
        }
        for (map<string, string>::iterator it = main.begin(); it != main.end(); it++)
        {
            cout << it->second << " is the MaJia of " << it->first << endl;
        }
        cout << endl;
    }
    return 0;
}                                 