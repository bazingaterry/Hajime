#include <iostream>
using namespace std;

int main()
{
	double n;
	cin >> n;
	if (n<20000) cout << n*.8<<endl;
	else if (n<50000) cout<< (n-(n*.3-2000))<<endl;
	else cout << (n-(n*.4-7000))<<endl;
	
	return 0;
}
