#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	char ch[999];
	while (cin >> ch)
	{
		if (ch[0]=='#') break;
		
		for(int i=0,j=strlen(ch)-1;i<j; ++i,--j) //turn back ch
		{
			char c=ch[i];
			ch[i]=ch[j];
			ch[j]=c;
		}
		
		int i;
		for(i=0;ch[i]!='\0';i++)
		{
			if (ch[i]=='a'||ch[i]=='c'||ch[i]=='e'||ch[i]=='f'||ch[i]=='g'||ch[i]=='h'||ch[i]=='j'||ch[i]=='k'||ch[i]=='l'||ch[i]=='m'||ch[i]=='n'||ch[i]=='r'||ch[i]=='s'||ch[i]=='t'||ch[i]=='u'||ch[i]=='y'||ch[i]=='z') break;
			else if (ch[i]=='b') ch[i]='d';
			else if (ch[i]=='d') ch[i]='b';
			else if (ch[i]=='p') ch[i]='q';
			else if (ch[i]=='q') ch[i]='p';
		}
		if (i==strlen(ch)) cout << ch << endl;
		else cout << "INVALID" << endl;
	}
	return 0;
}
