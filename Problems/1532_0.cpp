#include <cmath>
#include <cstring>
using namespace std;

int reverse(int number)
{
	bool isMinus=0;
	if (number<0) isMinus=1;
	
	int length=0;
	if (number==0) length=1;	
	while(number/(int)pow(10,length)!=0)
		length++;
	
	int result=0;
	while(number!=0)
	{
		result+=(number%10)*pow(10,length-1);
		length--;
		number/=10;
	}
	
	return result;
	
}
