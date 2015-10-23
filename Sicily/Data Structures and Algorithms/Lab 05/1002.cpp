#include "stack"
#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    while (cin >> T)
    {
        while (T--)
        {
            int queue[200002];
            int N;
            cin >> N;
            {
                for (int i = 0; i < N; ++i)
                {
                    int a, b;
                    cin >> a >> b;
                    queue[a] = i;
                    queue[b] = i;
                }

                stack<int> s;
                for (int i = 1; i <= N * 2; ++i)
                {
                    if (s.empty())
                        s.push(queue[i]);
                    else if (s.top() == queue[i])
                        s.pop();
                    else
                        s.push(queue[i]);
                }
                if (s.empty())
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
    }
    return 0;
}