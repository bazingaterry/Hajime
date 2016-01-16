#include "iostream"
#include "queue"
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        queue<int> q;
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i)
        {
            int task;
            cin >> task;
            q.push(task);
            pq.push(task);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (q.front() == pq.top())
            {
                q.pop();
                pq.pop();
            }
            else
            {
                while (q.front() != pq.top())
                {
                    q.push(q.front());
                    q.pop();
                    cnt++;
                }
                q.pop();
                pq.pop();
            }
        }
        cout << cnt << endl;
    }
    return 0;
}