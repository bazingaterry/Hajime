#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1,str2;
	cin >> str1 >> str2;
	
	for (int i=0;i<str1.size()&&i<str2.size();i++)
	{
		if (str1[i]==str2[i]) cout << str1[i];
		else if (i==0&&(str1[0]!=str2[0])) cout <<"no common prefix";
		
	}
	cout << endl;
	
	return 0;
}
