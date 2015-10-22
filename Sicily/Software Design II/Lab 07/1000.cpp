#include "iostream"
#include "cstring"
using namespace std;

class MyString
{
public:
    MyString(const char*);
    MyString(int = 0, char = '\0');  //initialize size_t number of char, terminated with '\0'
    MyString(const MyString&);           //copy constructor
    ~MyString();                        //destructor
    const char* c_str();                   //return private char*
    static int getNumberOfObjects();
private:
    char* str;
    static int numberOfObjects;            //count the number of MyString objects
};

MyString::MyString(const char* ch)
{
    str = new char[strlen(ch) + 1];
    for (int i = 0; i <= strlen(ch); ++i)
    {
        str[i] = ch[i];
    }
    numberOfObjects++;
}

MyString::MyString(int size, char ch)
{
    str = new char[size + 1];
    for (int i = 0; i < size; ++i)
    {
        str[i] = ch;
    }
    str[size] = '\0';
    numberOfObjects++;
}

MyString::MyString(const MyString& newMyString)
{
    str = new char[strlen(newMyString.str) + 1];
    for (int i = 0; i <= strlen(newMyString.str); ++i)
    {
        str[i] = newMyString.str[i];
    }
    numberOfObjects++;
}

const char* MyString::c_str()
{
    return str;
}

int MyString::getNumberOfObjects()
{
    return numberOfObjects;
}

MyString::~MyString()
{
    delete str;
    numberOfObjects--;
}

int MyString::numberOfObjects = 0;

/*
int main()
{
    MyString ms1(5, 'c');
    cout << ms1.c_str() << endl;
    MyString *ptr_ms2 = new MyString("Hello!");
    {
        MyString ms3(ms1);
    }
    cout << ptr_ms2->c_str() << endl;
    delete ptr_ms2;
    cout << MyString::getNumberOfObjects() << endl;
    return 0;
}
*/