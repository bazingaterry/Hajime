#include "stack"
#include "cstdio"
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	int path1[1000], path2[1000];
	scanf("%d", &T);
	while(T--)
	{
        int num1, num2;
        int index1 = 0, index2 = 0;
        scanf("%d%d", &num1, &num2);
        while(num1)
        {
            path1[++index1] = num1;
            num1 >>= 1;
        }
        while(num2)
        {
            path2[++index2] = num2;
            num2 >>= 1;
        }
        int xi;
        while(path1[index1] == path2[index2] && index1 > 0 && index2 > 0)
        {
        	xi = path1[index1];
        	index1--;
        	index2--;
        }
        printf("%d\n", xi);
    }
	return 0;
}