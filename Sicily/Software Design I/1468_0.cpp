#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int row;
	cin >> row;
	for (int i = 1; i <= row; i++)	//the i column
	{
		for (int j = 1; j <= row - i; j++)	//print the space
			cout << "     ";
		
		for (int j = 1; j <= i; j++)	//print the left half numbers
			cout << setw(5) << pow(2, j - 1);
		
		for (int j = i-1; j >= 1; j--)	//print the right half numbers
			cout << setw(5) << pow(2, j - 1);
		
		cout << endl;
	}	
	return 0;
}
