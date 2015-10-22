#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int hcToX (string str,int m)
{
	int result=0;

	for (int i=0;i<str.size();i++)
	{
		if (48<=str[i]&&str[i]<=57) result+=(str[i]-48)*pow(m,str.size()-i-1);//number
		else result+=(str[i]-55)*pow(m,str.size()-i-1);//letter
	}
		
		return result;
}

string XhcToM (int x,int m)
{
	string result;
	
	if (x==0) result="0";
	
	while(x!=0)
	{
		string mod;
		if (0<=x%m&&x%m<=9) mod=x%m+48;
		else mod=x%m+55;
		result=mod+result;
		x=x/m;
	}
	
	return result;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int m;
		string stra,strb;
		
		cin >> m >> stra >> strb;
		
		int a=hcToX(stra,m);
		int b=hcToX(strb,m);
		
		string p=XhcToM(a/b,m);
		string q=XhcToM(a%b,m);
		
		cout << p << endl << q << endl;
	}
	
	return 0;
}
