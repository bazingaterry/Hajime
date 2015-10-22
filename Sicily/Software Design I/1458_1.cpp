#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	char ch1 [100],ch3 [100];

	while (cin >> ch1)
	{
		int i;
		char ch2 [100];
		
		cin >> i >> ch2;
		
		int t1=0,t3;
		while (1)
		{
			if (t1==i)
			{
				t3 = t1;
				break;
			}

			ch3[t1] = ch1[t1];
			t1++;
		}
		
		int t2=0;
		while (ch2[t2]!='\0')
		{
			ch3[t1] = ch2 [t2];
			t2++;t1++;
		}
		
		while (ch1[t3]!='\0')
		{
			ch3[t1] = ch1[t3];
			t1++;t3++;
		}
		
		ch3 [t1] = '\0';

		for(int i =0,j=strlen(ch3)-1;i<j; ++i,--j)
		{
			char c=ch3[i];
			ch3[i]=ch3[j];
			ch3[j]=c;
		}
		
		cout << ch3 <<endl;
	}
	return 0;
}
