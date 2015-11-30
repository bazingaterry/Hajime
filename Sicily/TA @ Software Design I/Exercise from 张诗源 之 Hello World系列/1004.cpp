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

int main(int argc, char const *argv[])
{
	cout << "Goodbye world" << endl;
	return 0;
}