#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	long int sum=0;
	long long sum2=0;
	int t;
	
	for (int i=0;i<=n-1;i++)
	{
		cin >> t;
		sum=sum+t;
		sum2=sum2+pow(t,2);
	}
	
	double e=(double) sum/n;
	double v=(double) sum2/n-pow(e,2);
	
	cout << fixed << setprecision(2) << e <<" "<<v<<endl;
		
	return 0;
}
