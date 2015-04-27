#include "iostream"
#include "cstring"
using namespace std;

int parseBinary(const char * const binaryString)
{
	int decimal = 0;
	int base = 1;
	for (int i = strlen(binaryString) - 1; i >= 0; --i)
	{
		decimal += (binaryString[i]-'0') * base;
		base *= 2;
	}
	return decimal;
}


int main(int argc, char const *argv[])
{

	char ch[1000];
	cin >> ch;
	cout << parseBinary(ch);

	return 0;
}
