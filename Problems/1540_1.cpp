#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) // t test cases
	{
		int n,count;
		int max=-2147483648;
		
		cin >> n; // n integers
		while(n--)
		{
			int num;
			cin >> num;
			if (num>max) // new max number
			{
				max=num;
				count=1; //reset the count
			}
			else if (num==max) // max occur
				count++;
		}
		cout << max << " " << count << endl;

	}
	return 0;
}
