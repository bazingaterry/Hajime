#include "iostream"
#include "cmath"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n--)
	{
		int num[3];
		cin >> num[0] >> num[1] >> num[2];
		
		if (abs(num[0] - num[1]) != num[2] && num[0] + num[1] != num[2])
			cout << num[0] << " " << num[1] << " " << num[2] <<" NO SUM\n";
		else
		{
			if(num[0] > num[1] && num[0] > num[2])
			{
				cout << num[1] << " + " << num[2] << " = " << num[0] <<endl;
			}
			else if(num[1] > num[2] && num[1] > num[0])
			{
				cout << num[0] << " + " << num[2] << " = " << num[1] <<endl;
			}
			else if(num[2] > num[0] && num[2] > num[1])
			{
				cout << num[0] << " + " << num[1] << " = " << num[2] <<endl;
			}
		}
	}
	return 0;
}
