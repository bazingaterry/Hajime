#include "stack"
#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int queue[200002];
	int size;
	while (cin >> size && size != 0)
	{
		for (int i = 0; i < size; ++i)
		{
			int m, n;
			cin >> m >> n;
			queue[m] = i;
			queue[n] = i;
		}

		stack<int> myStack;
		for (int i = 1; i <= size * 2; ++i)
		{
			if (myStack.empty())
				myStack.push(queue[i]);
			else if (myStack.top() == queue[i])
				myStack.pop();
			else
				myStack.push(queue[i]);
		}
		if (myStack.empty())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}