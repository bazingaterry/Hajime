#include "iostream"
#include "queue"
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--)
    {
        int size;
        cin >> size;
        priority_queue<int> pq;
        while(size--)
        {
            int price;
            cin >> price;
            pq.push(price);
        }
        int result = 0;
        int cnt = 0;
        while(!pq.empty())
        {
            if (cnt == 2) result += pq.top();
            pq.pop();
            cnt++;
            cnt %= 3;
        }
        cout << result << endl;
    }
    return 0;
}
