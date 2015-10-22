#include <iostream>
using namespace std;

int main()
{
	int n,big,small;
	
	for (int i=0;i<5;i++)
 	{
		cin >> n;
		if (i==0||n>big) big=n;
		if (i==0||n<small) small=n;
    }
	
	cout << big << " " << small << endl;
	return 0;
}
