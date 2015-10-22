#include "iostream"
#include "string"
#include "cmath"
using namespace std;

class MyInteger
{
private:
    int value;
public:
    MyInteger(int);
    int getValue();
    bool isEven();
    bool isOdd();
    bool isPrime();
    static bool isEven(int);
    static bool isOdd(int);
    static bool isPrime(int);
    static bool isEven(MyInteger&);
    static bool isOdd(MyInteger&);
    static bool isPrime(MyInteger&);
    bool equals(int);
    bool equals(MyInteger&);
    static int parseInt(string&);
};

MyInteger::MyInteger(int data)
{
    value = data;
}

int MyInteger::getValue()
{
    return value;
}

bool MyInteger::isEven()
{
    return isEven(value);
}

bool MyInteger::isEven(int n)
{
    return n % 2 == 0;
}

bool MyInteger::isEven(MyInteger& NewInteger)
{
    return NewInteger.isEven();
}

bool MyInteger::isOdd(int n)
{
    return n % 2 == 1;
}

bool MyInteger::isOdd()
{
    return isOdd(value);
}

bool MyInteger::isOdd(MyInteger& NewInteger)
{
    return NewInteger.isOdd();
}

bool MyInteger::isPrime(int n)
{
    if (n <= 0)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

bool MyInteger::isPrime()
{
    return isPrime(value);
}

bool MyInteger::isPrime(MyInteger& NewInteger)
{
    return NewInteger.isPrime();
}

bool MyInteger::equals(int data)
{
    return value == data;
}

bool MyInteger::equals(MyInteger& NewInteger)
{
    return value == NewInteger.getValue();
}

int MyInteger::parseInt(string& str)
{
    int result = 0;
    int base = 1;
    for (int i = str.size() - 1; i >= 0; --i)   //  change string to int
    {
        result += (str[i] - '0') * base;
        base *= 10;
    }
    return result;
}

/********test code*********************

int main(int argc, char const *argv[])
{
    int tmp;
    string str;
    while(cin >> tmp && tmp != -1)
    {
        MyInteger integer(tmp);
        cout << integer.getValue() << endl;
        cout << integer.isPrime() << " " << integer.isOdd() << " "
             << integer.isEven() << endl;
        
        cin >> tmp;
        MyInteger newinteger(tmp);
        cout << integer.equals(tmp) << " " << integer.equals(newinteger) << endl;
    }

    while(cin >> tmp)
    {
        static MyInteger integer(tmp);
        cout << integer.getValue() << endl;
        cout << integer.isPrime() << " " << integer.isOdd() << " "
             << integer.isEven() << endl;
        
        cin >> tmp >> str;
        MyInteger newinteger(tmp);
        cout << integer.equals(tmp) << " " << integer.equals(newinteger) 
             << " " << integer.parseInt(str) << endl;
    }
    return 0;
}

********test code*********************/