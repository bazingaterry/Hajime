#include "iostream"
using namespace std;

class INT
{
    int i;

public:
    int getI()
    {
        return i;
    }

    INT(int num)
    {
        this->i = num;
    }

    INT()
    {}

    void operator=(int num)
    {
        this->i = num;
    }

    INT operator+(INT myINT)
    {
        INT result(this->i + myINT.getI());
        return result;
    }

    int operator++()
    {
        return ++i;
    }

    int operator++(int dummy)
    {
        return i++;
    }

    bool operator==(INT myINT)
    {
        return i == myINT.getI();
    }

    friend ostream& operator<<(ostream& os, INT myINT)
    {
        os << myINT.getI();
        return os;
    }
};

int main()
{
    INT a = 1, b(2), c;
    c = 3;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;  
    cout << "a+b = " << a+b << endl;
    cout << "++a = " << ++a << endl;
    cout << "a++ = " << a++ << endl;
    cout << "a = " << a << endl;

    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "a == b? " << (a==b) << endl;
    cout << "a == c? " << (a==c) << endl;
}