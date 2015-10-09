#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(int argc, char const *argv[])
{
	int n = 21;
	while (n != 1)
	{
		int t;
		cin >> t;
		cout << 5 - t <<" ";
		n -= 5;
		cout << n << endl;
	}
	cout << "Game Over!\n";
	
	return 0;
}
