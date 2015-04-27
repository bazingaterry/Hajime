#include "cstdio"
#include "algorithm"
using namespace std;

int n;
int list[200];

int main(int argc, char const *argv[])
{

	scanf("%d",&n);
	
	for (int i=0;i<n;++i)
		scanf("%d",&list[i]);

	sort(list,list+n);

	for (int i=0;i<n;++i)
		printf("%d\n",list[i]);
	
	return 0;
}
