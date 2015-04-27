#include<iostream>
#include<algorithm>
using namespace std;

int num[101];


int main()
{
    int n;
    while(cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> num[i];
        
        sort(num, num+n);
        
        int x = 0;
        int y = 0;
        
        for (int i = 0; i < n; ++i)
        {
            if (x < y)
                x += num[i];
            else
                y += num[i];
        }
        
        cout << (x * y) / 2 << endl;
    }
    
    return 0;
}
