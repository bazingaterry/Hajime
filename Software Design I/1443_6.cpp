#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool d5 = n%5==0;
	bool d6 = n%6==0;
	if (d5&&d6) cout << "Is " << n <<" divisible by 5 and 6? true"<<endl;
	else cout << "Is " << n<<" divisible by 5 and 6? false"<<endl;
	if (d5||d6) cout<<"Is "<< n << " divisible by 5 or 6? true"<<endl;
	else cout<<"Is "<< n << " divisible by 5 or 6? false"<<endl;
	if ((d5||d6)&&(1-(d5&&d6))) cout<<"Is "<<n<<" divisible by 5 or 6, but not both? true"<<endl;
	else cout<<"Is "<<n<<" divisible by 5 or 6, but not both? false"<<endl;	
	
	return 0;
}
