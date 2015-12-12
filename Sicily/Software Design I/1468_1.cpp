#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int pattern;
	cin >> pattern;
	switch (pattern)
	{
		case 1:	//	Pattern 1 -begin
			for (int i = 1; i <= 6; i++)	//	the i colmun
			{
				for (int j = 1; j <= i; j++)	//	the j number
					cout << setw(3) << j;				
				cout << endl;
			}
			break;	//	Pattern 1 -end

		case 2:	//	Pattern 2 -begin
			for (int i = 6; i >= 1; i--)	//	the 7-i colmun
			{
				for (int j = 1; j <= i; j++)	//	the j number
					cout << setw(3) << j;				
				cout << endl;
			}
			break;	//	Pattern 2 -end

		case 3:	//	Pattern 3 -begin
			for (int i = 1; i <= 6; i++)	//	the i colmun
			{
				for (int j = 5; j >= i; j--)	//	print space
					cout << "   ";				
				for (int j = 1; j <= i; j++)	//	the j number
					cout << setw(3) << j;
				cout << endl;
			}
			break;	//	Pattern 3 -end
			
		case 4:	//	Pattern 4 -begin
			for (int i = 6; i >= 1; i--)	//	the 7-i colmun
			{
				for (int j = 1; j <= 6 - i; j++)	//	print space
					cout << "   ";								
				for (int j = 1; j <= i; j++)	//	the j number
					cout << setw(3) << j;
				cout << endl;
			}
			break;	//	Pattern 4 -end
	}
	return 0;
}
