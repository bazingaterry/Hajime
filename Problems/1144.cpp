#include "iostream"
#include "string"
using namespace std;

int main(int argc, char const *argv[])
{
	int num[10];
	int count = 0;
	for (int i = 0; i < 10; ++i)
	{
		cin >> num[i];
	}
	int n;
	cin >> n;
	for (int i = 0; i < 10; ++i)
	{
		if (n + 30 >= num[i])
		{
			count++;
		}
	}
	
	cout << count << endl;

	return 0;
}