#include "iostream"
#include "cmath"
using namespace std;

int step(int n, int m, int time)
{
	if (n < m)
		swap(n, m);
	if (n % m == 0 || n > m * 2)
		return time;
	return step(n - m, m, time + 1);
}

int main(int argc, char const *argv[])
{
	int n, m;
	while(cin >> n >> m && (n != 0 || m != 0))
	{
		if (step(n, m, 0) % 2 == 0)
			cout << "Singa wins\n";
		else
			cout << "Suny wins\n";
	}
	

	return 0;
}
