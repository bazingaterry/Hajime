#include <iostream>
#include <cstring>
using namespace std;


int main ()
{
	char ch[81];
	
	
	
	
	int t;
	while (cin >> t)
	{
		if (t==0) break;

		int count=0;

		for (int i=1;i<=t;i++)
		{
			int at=0;
			int point[80]={0};
			int p=1;//empty point location
			int wor=0;

			cin >> ch;

			for (int x=0;x<strlen(ch);x++)//search point
			{
				if (ch[x]=='@')
				{
					at++;
					point[p]=x;
					p++;
				}
				else if (ch[x]=='.')
				{
					point[p]=x;
					p++;
				}
				//cout << p <<endl;
			}
			point[0]=-1;
			point[p]=strlen(ch);
			//cout << point[0] << point[1] << point[2] << point[3] << strlen(ch) << endl;
			
			
			int m=0;
			for (int x=0;x<p;x++)//check each block
			{
    			int i;
				
				if (point[x+1]-point[x]==1) wor++;
				
				for (i=point[x]+1;i<=point[x+1]-1;i++)
				{
					//cout << point[x] << endl;
					if (('a'<=ch[i]&&ch[i]<='z')||('A'<=ch[i]&&ch[i]<='Z')||('0'<=ch[i]&&ch[i]<='9'));
					else break;
					//cout << i <<" "<<point[x+1]-1<<endl;
				}

				//cout << i <<" "<<point[x+1]-1<<endl;
				if (i==point[x+1]) m++;//the block is valid
				//cout << m <<endl;
			}
			//cout << p <<endl;
			if (m==p&&p>=3&&at==1&&ch[point[1]]=='@'&&wor==0) count++;
			

		}
		cout << count << endl;
	}


	return 0;
}
