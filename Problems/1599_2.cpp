#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int testCase = 1; testCase <= t; ++testCase)
	{
		int num[101][101]{}; // set array to 0
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> num[i][j];       // read the matrix

		int countOf0Row = 0;
		int countOf1Row = 0;
		int countOf0Col = 0;
		int countOf1Col = 0;
		for (int i = 0; i < n; ++i) // count of row&col
		{
			for (int j = 0; j < n; ++j)
			{
				num[i][100]+=num[i][j]; // sum of i row
				num[100][i]+=num[j][i]; // sum of i col
			}
			if (num[i][100] == 0) // count of row
				countOf0Row++;
			else if (num[i][100] == n)
				countOf1Row++;

			if (num[100][i] == 0) // count of Col
				countOf0Col++;
			else if (num[100][i] == n)
				countOf1Col++;
		}

		int sumOf1Dia = 0;
		int sumOf2Dia = 0;
		int countOf0Dia = 0;
		int countOf1Dia = 0;
		for (int i = 0; i < n; ++i) // count of Dia
		{
			sumOf1Dia+=num[i][i];
			sumOf2Dia+=num[i][n-1-i];
		}
		if (sumOf1Dia == 0)
			countOf0Dia++;
		else if (sumOf1Dia == n)
			countOf1Dia++;

		if (sumOf2Dia == 0)
			countOf0Dia++;
		else if (sumOf2Dia==n)
			countOf1Dia++;

		cout << "test case " << testCase <<":\n";
		cout << "The count of all 0s rows, columns, or diagonals is " << countOf0Dia + countOf0Col + countOf0Row << endl;
		cout << "The count of all 1s rows, columns, or diagonals is " << countOf1Dia + countOf1Col + countOf1Row << endl;
	}
	return 0;
}
