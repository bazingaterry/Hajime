#include "set"
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
    cin >> N;
    set<string> word;
    string str;
    while (N--)
    {
        cin >> str;
        word.insert(str);
    }
    int M;
    cin >> M;
    while (M--)
    {
        cin >> str;
        if (word.count(str))
            cout << "Word is spelled correctly.\n";
        else
        {
            cout << "Word is not spelled correctly.";
            for (int i = 0; i < str.size() - 1; ++i)
            {
            	swap(str[i], str[i + 1]);
            	if (word.count(str))
            	{
            		cout << " Did you mean \"" << str << "?\".";
            		break;
            	}
            	swap(str[i], str[i + 1]);
            }
            cout << endl;
        }
    }
	return 0;
}
