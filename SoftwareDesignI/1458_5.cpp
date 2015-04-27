#include <iostream>
#include <cstring>
using namespace std;

int longestPalindrome (char,int);

int longestPalindrome (char ch[],int m)
{
	int longest=1;
	//left
	int i=m,j=m+1;
	while (m>=0&&j<=strlen(ch)-1)
	{
		if (ch[i]==ch[j])
		{
			i--;j++;
		}
		else
		{
			break;
		}
	}
	if (j-i-1>longest) longest=j-i-1;
	
	//middle
	i=m-1;
	j=m+1;
	while (m>=0&&j<=strlen(ch)-1)
	{
		if (ch[i]==ch[j])
		{
			i--;j++;
		}
		else
		{
			break;
		}
	}
	if (j-i-1>longest) longest=j-i-1;
	
	//right
	i=m-1;
	j=m;
	while (m>=0&&j<=strlen(ch)-1)
	{
		if (ch[i]==ch[j])
		{
			i--;j++;
		}
		else
		{
			break;
		}
	}
	if (j-i-1>longest) longest=j-i-1;
	
	
	return longest;
}




int main ()
{
	char ch[101];
		
	while(cin >> ch)
	{
		int result=1;
		for (int i=0;i<strlen(ch);i++) 
		{
			int x=longestPalindrome (ch,i);
			if (x>result) result=x;
		}
		
		cout << result <<endl;
	}
	return 0;
}
