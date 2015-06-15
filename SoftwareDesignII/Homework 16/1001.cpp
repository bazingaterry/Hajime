#include "list"
#include "iostream"
#include "string"
using namespace std;

void print(list<int>& ls)
{
	cout << "List:\n";
	for (list<int>::iterator i = ls.begin(); i != ls.end(); ++i)
	{
		cout << *i << endl;
	}
}

int main(int argc, char const *argv[])
{
	int N;
	while(cin >> N)
	{
		list<int> ls;
        while(N--)
		{
			string operation;
            cin >> operation;
            if(operation == "push_back")
            {
                int n;
                cin >> n;
                ls.push_back(n);
            }
            else if (operation == "push_front")
            {
                int n;
                cin >> n;
                ls.push_front(n);
            }
            else if (operation == "pop_back")
            {
                ls.pop_back();
            }
            else if (operation == "pop_front")
            {
                ls.pop_front();
            }
            else if (operation == "print")
            {
                print(ls);
            }
		}
	}
	return 0;
}