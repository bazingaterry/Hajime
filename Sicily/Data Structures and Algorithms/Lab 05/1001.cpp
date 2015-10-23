#include "iostream"
#include "list"
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
    list<int> l;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        l.push_back(num);
    }

    list<int>::iterator it = l.begin();
    for (int i = 0; i < m; ++i)
    {
        int o;
        cin >> o;
        switch(o)
        {
            case 1:
                int x;
                cin >> x;
                l.insert(it, x);
                it--;
                break;
            case 2:
                int k;
                cin >> k;
                while (k--)
                    it++;
                break;     
        }
    }

    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << endl;
    }
	return 0;
}