#include "iostream"
using namespace std;

int hanoi(int n)
{
	if (n==1)
		return 1;
	else
		return hanoi(n-1)*2+1;
}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << hanoi(n);
	return 0;
}