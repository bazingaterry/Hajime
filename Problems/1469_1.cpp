#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	char ch[51];
	while (cin >> ch)
	{
		sort(ch,ch+strlen(ch));
		
		for(int i=0,j=strlen(ch)-1;i<j; ++i,--j) //turn back ch
		{
			char c=ch[i];
			ch[i]=ch[j];
			ch[j]=c;
		}
		
		cout << ch << endl;
	}
	
	
	return 0;
}
