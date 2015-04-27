#include "iostream"
using namespace std;

int a,b,c;

int fx (int x)
{
	if (x<=3)
		return 1;
	else
		return (a*fx(x-1)+b*fx(x-2)+c*fx(x-3));

}


int main(int argc, char const *argv[])
{
	int x;
	cin >> a >> b >> c >> x;
	cout << fx(x) << endl;
	return 0;
}
