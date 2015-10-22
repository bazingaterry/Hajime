#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	while (n--)
	{
		int ques;
		cin >> ques;
		
		int count=0;
		while (ques!=0)
		{
			if (ques%10==a||ques%10==b||ques%10==c) count++;
			ques=ques/10;
		}
		cout << count << endl;
	}
	
	
	return 0;
}
