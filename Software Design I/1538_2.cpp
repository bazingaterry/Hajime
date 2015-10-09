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
		int l,r;
		cin >> l >> r;
		for (;l<r;l++,r--)
			swap(list[l-1],list[r-1]);
	}

	for (int i = 0; i < n-1; ++i)
		cout << list[i] <<" ";
	cout << list[n-1] << endl;
	
	return 0;
}
