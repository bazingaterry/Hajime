#include "iostream"
#include "cstdlib"
using namespace std;

class helloWorld
{
public:
	helloWorld()
	{
		cout << "Hello World\n";
		exit(0);
	}
	
};

helloWorld hw;

void hello_world(){}

int main(int argc, char const *argv[])
{
	hello_world();
	hello_world();
	return 0;
}