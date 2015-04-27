#include "iostream"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int num[100];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	cout << num[1] << endl;
	
	return 0;
}
