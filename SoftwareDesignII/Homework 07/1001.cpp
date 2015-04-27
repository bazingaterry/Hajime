#include "cstdio"

class Number
{
public:
	Number(int num)
	{
		data = num;
	}
	Number add(int num)
	{
		data += num;
		return *this;
	}
	Number sub(int num)
	{
		data -= num;
		return *this;
	}
	void print()
	{
		printf("%d\n", data);
	}
private:
	int data;
};

int main()
{
    Number n(1);
    n.add(0).sub(3).add(0);
    n.print();
    return 0;
}