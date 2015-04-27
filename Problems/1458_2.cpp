#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	char ch [100],ts [100];
	while (cin >> ch >> ts)
	{
		int t1=0,count=0;

		while (ch[t1]!='\0')
		{
			
			
			if (ch[t1]==ts[0])
			{
				int i=1;
				
				for (int j=t1+1;i<strlen(ts);i++,j++) if (ch[j]!=ts[i]) break;

				if (i==strlen(ts))
				{
					count++;
					t1=t1+strlen(ts)-1;
				}

			}

			t1++;
 		}
		cout << count << endl;
	}
	
	return 0;
}
