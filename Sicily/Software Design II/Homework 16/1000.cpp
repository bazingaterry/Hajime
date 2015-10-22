#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(const vector<int>&);

bool isPalindrome(const vector<int>& v)
{
    vector<int>::const_iterator i = v.begin(), j = v.end() - 1;
    while(i < j)
    {
    	if (*i != *j)
    		return false;
    	i++;
    	j--;
    }
    return true;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<int> vi;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			vi.push_back(k);
		}
		cout << (isPalindrome(vi) ? "yes" : "no") << endl;
	}
	return 0;
}