#include<iostream>
#include<stack>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

int main() {
    int T;
    cin >> T;
    while (T--)
    {
        stack<int> gun;
        stack<int> bomb;
        int test[10];
        for (int i = 0; i < 10; i++) cin >> test[i];
        for (int i = 10; i > 0; i--) bomb.push(i);
        int tmp, t;
        bool flag;
        for (flag = true, tmp = 0, t = 0; t < 10;)
        {
            if (!gun.empty() && (gun.top() == test[t]))
            {
                gun.pop();
                t++;
            }
            else if (!bomb.empty())
            { 
                gun.push(bomb.top());
                bomb.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
}                                 