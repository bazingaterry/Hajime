#include "iostream"
#include "stack"
using namespace std;

int N;
int res[1000];
int out[1000];

bool check()
{
    int i = 1, j = 0;
    stack<int> st;
    while (i <= N)
    {
        if (st.empty()) st.push(i++);
        else if (st.top() == res[j])
        {
            out[j++] = st.top();
            st.pop();
        }
        else st.push(i++);
    }
    while (!st.empty())
    {
        out[j++] = st.top();
        st.pop();
    }
    for (int i = 0; i < N; ++i)
        if (out[i] != res[i]) return false;
    return true;
}

int main(int argc, char const *argv[])
{
    next: while (cin >> N && N)
    {
        for(;;)
        {
            for (int i = 0; i < N; ++i)
            {
                cin >> res[i];
                if (res[0] == 0)
                {
                    cout << endl;
                    goto next;
                }
            }
            if (check()) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}
