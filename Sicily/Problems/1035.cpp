#include <iostream>
using namespace std;

int match(bool,bool);
int match(char f,char s)
{
	int result=0;
	if ((f=='A'&&s=='T')||(f=='G'&&s=='C')||(f=='C'&&s=='G')||(f=='T'&&s=='A')) result=1;
	return result;
}

int main ()
{
	int time,t,row,r1,r2,n,count;
	cin>>time;
	for (t=1;t<=time;++t)//the times of the task 
	{
		cin>>row;
		count=0;
		char dna[row] [101];
		for (r1=1;r1<=row;++r1)//read dna
		{
			cin>>dna [r1-1];
		}
		for (r1=1;r1<=row-1;++r1)//each row match
		{
			for (r2=r1+1;r2<=row;++r2)//begin match with the next row and end up with the last row
			{
				n=0;//match with the no.0 entry
				while (1)
				{
					if (match(dna[r1-1] [n],dna[r2-1] [n])==0||dna[r1-1] [n]=='\0'||dna[r2-1] [n]=='\0') break;
					++n;				
				}
				if (dna[r1-1] [n]=='\0'&&dna[r2-1] [n]=='\0')//match! 
				{
					dna[r1-1][0]='S';
					dna[r2-1][0]='S';
					count++;
					break; 
				}
			}
			
		}
		cout<<count<<endl;
	}

return 0;
}
