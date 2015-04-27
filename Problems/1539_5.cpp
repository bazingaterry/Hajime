#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

const double pi=3.1415926535898;
double a,b,dx;

double cx(double i)
{
	return a+i*dx;
}

double yi(double x)
{
	double xi=cx(x);
	return exp(-pow(xi,2)/2)/(sqrt(2*pi));
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> a >> b >> n)
	{
		dx=(b-a)/n;

		double result=yi(0)+yi(n);
		
		for (int i =1 ; i <= n-1; i+=2)
			result+=4*yi(i);

		for (int i = 2; i <= n-2; i+=2)
			result+=2*yi(i);

		cout << fixed << setprecision(2) << dx*result/3 << endl;
	}
	return 0;
}
