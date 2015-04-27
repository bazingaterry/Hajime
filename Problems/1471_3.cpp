#include <iostream>
using namespace std;

int main()
{
	int n;//number of data
	int array[100];//data
	int count[1000]={0};
	int max=1;
	cin >> n;
	
	for (int i=0;i<n;i++) cin >> array[i];
	
	for (int i=0;i<n;i++) count[array[i]-1]++;
	
	for (int i=0;i<1000;i++) if (count[i]>max) max=count[i];
	
	if (max<=n/2.0+.99||n==1) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
