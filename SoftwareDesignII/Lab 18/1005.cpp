#include "iostream"
using namespace std;

class Base
{
public:
	void virtual print()
	{
		cout << "Base\n";
	}

	virtual ~Base()
	{
		cout << "Base destruct\n";
	}
};

class Derived : public Base
{
public:
	void print()
	{
		cout << "Derived\n";
	}

	~Derived()
	{
		cout << "Derived destruct\n";
	}
};

int main(int argc, char const *argv[])
{
	Base* pTest1 = new Base;
	Base* pTest2 = new Derived;
	pTest1->print();
	pTest2->print();
	delete pTest1;
	delete pTest2;
	return 0;
}