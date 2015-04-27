#include "iostream"
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) // t test cases
	{
		double num[100]; // store the number
		
		int n; // n numbers
		cin >> n;

		double sum=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> num[i]; // input numbers
			sum+=num[i]; // calculate the sum
		}

		double average = sum/n;

		int count=0;
		for (int i = 0; i < n; ++i)
			if (num[i]>average) // calculate the numbers above average
				count++;

		cout << count <<endl;
	}
	return 0;
}
