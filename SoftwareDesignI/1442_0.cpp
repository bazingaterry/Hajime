#include <iostream>
using namespace std;

int main()
{
	char ch[3];

	cin >> ch;
	
	for (int i=0;i<3;i++) ch[i] = ch[i] - 32;
	
	cout << ch << endl;

	return 0;
}
