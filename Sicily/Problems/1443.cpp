#include "iostream"
#include "queue"
#include "vector"
using namespace std;

class Task
{
public:
    int priority;
    bool mark;
    Task (int priority, bool mark)
    {
        this->priority = priority;
        this->mark = mark;
    }
};

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    while(N--)
    {
        int jobs, des;
        cin >> jobs >> des;
        priority_queue<int> pq;
        queue<Task> printer;
        for (int i = 0; i < jobs; i++)
        {
            int priority;
            cin >> priority;
            pq.push(priority);
            if (i == des) printer.push(Task(priority, true));
            else printer.push(Task(priority, false));
        }
        int cnt = 0;
        while (!printer.empty())
        {
            int top = pq.top();
            Task front = printer.front();
            if (front.priority == top)
            {
                pq.pop();
                printer.pop();
                cnt++;
                if(front.mark == true) break;
            }
            else
            {
                printer.pop();
                printer.push(front);
            }

        }
        cout << cnt << endl;
    }
    return 0;
}
