#include "iostream"
#include "algorithm"
#include "queue"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        queue<int> q;
        string operation;
        while (N--)
        {
            cin >> operation;
            if (operation == "Count")
            {
                cout << q.size() << endl;
            }
            else if (operation == "Out")
            {
                if (q.empty())
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << q.front() << endl;
                    q.pop();
                }
            }
            else if (operation == "In")
            {
            	int num;
            	cin >> num;
            	q.push(num);
            }
        }
    }
	return 0;
}