#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int qm (int n)
{
	if (n == 0)
		return 0;
		
	int result = 0;
	
	for (int i = 1; i < n; ++i)
	{	
		if (n % i == 0)
			result += i;
	}
	
	return result;
}


int main(int argc, char const *argv[])
{
	int array[3000];
	int loc = 0;
	
	
	for (int a = 1; a <= 3000; ++a)
	{
		int b = qm(a);
		if (qm(b) == a && a != b)
			{
				
				cout << a << " " << b << endl;
			}
	}
	return 0;
}
