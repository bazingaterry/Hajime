#include <iostream>
using namespace std;

int main()
{
	cout<<"Goodbye world"<<endl;
	return 0;
}

#include <sstream>
#include <cstdio>
stringstream buffer;
__attribute((constructor)) void before_main()
{
	printf("Hello World\n");
	streambuf* old = cout.rdbuf(buffer.rdbuf());
}