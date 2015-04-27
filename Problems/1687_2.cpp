#include "cstdio"

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while ( scanf("%d", &n) != EOF )
		printf("%d\n", (n >> 4) & 15);

	return 0;
}