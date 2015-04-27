#include "iostream"
#include "cmath"
using namespace std;


int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	
	int list[1000];
	for (int i = 0; i < n; ++i)
		cin >> list[i];

	while(m--)
	{
		int t;
		cin >> t;
		cout << list[t-1] << endl;
	}

	return 0;
}
