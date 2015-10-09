#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
    string para;
    while(cin >> para)
    {
        istringstream iss(para);
        int n;
        double d;
        iss >> n;
        if(iss.eof())
            cout << "Integer: " << showbase << hex << n << endl;
        else
        {
            iss.clear();
            iss.str(para);
            iss >> d;
            if(iss.eof())
            {
                cout << "Double: " << fixed << setprecision(6) << d << endl;
            }
            else cout << "String: " << para << endl;
        }
    }
}            