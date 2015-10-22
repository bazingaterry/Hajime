#include "iostream"
#include "cstring"
using namespace std;

int displayed[101]; // dispalyed numbers
int count=0; // how many number in the array

bool isDisplayed (int num) 
{
	for (int i = 0; i < count; ++i)
	{
		if (displayed[i]==num)
			return 1;
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) // t test cases
	{
		count=0;
		memset(displayed,0,sizeof(displayed)); //reset the array
		
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			if (isDisplayed(num)==0) // the number hasn't been displayed
			{
				if (i!=0)
					cout << " "; // print a blank between each number
				cout << num;
				
				displayed[count]=num;
				count++;// store the new number
			}
		}
		cout << endl;
	}
	return 0;
}
