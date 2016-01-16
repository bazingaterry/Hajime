#include "stack"
#include "string"
#include "map"
#include "iostream"
using namespace std;

bool brackets(string s)
{
	stack<char> st;
	map<char, char> m;
	m[']'] = '[';
	m[')'] = '(';
	m['}'] = '{';
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '{' || s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
		{
			if (!st.empty() && m[s[i]] == st.top())
				st.pop();
			else
				return false;
		}
	}
	return st.empty() ? true : false; 
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	cout << brackets(s);
	return 0;
}