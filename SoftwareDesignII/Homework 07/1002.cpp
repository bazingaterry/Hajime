#include "iostream"
#include "cstdio"
using namespace std;

class MyVector
{
public:
    MyVector()
    {
        data = NULL;
        size = 0;
    }
    MyVector(int size)
    {
        this->size = size;
        data = new double[size];
    }
    void create(int size)
    {
        if (data != NULL)
            delete data;
        this->size = size;
        data = new double[size];
    }
    void setValue(double value, int index)
    {
        if (0 <= index && index < size)
            data[index] = value;
    }
    void multiply(double k)
    {
        if (data != NULL)
        {
            for (int i = 0; i < size; ++i)
            {
                data[i] *= k;
            }
        }
    }
    void display()
    {
        if (data != NULL)
        {
            cout << "(" << data[0];
            for (int i = 1; i < size; ++i)
            {
                cout << "," << data[i];
            }
            printf(")\n");
        }
    }
    ~MyVector()
    {
        delete data;
    }
private:
    double* data;
    int size;
};

int main()
{
    int size,i;
    double input;
    double k;
    while (cin>>size>>k)
    {
        MyVector vector1(size);
        vector1.create(size); // this sentence is redundant
        for(i=0;i<size;i++)
        {
           cin >> input;
           vector1.setValue(input,i);
        }
        vector1.display();
        vector1.multiply(k);
        vector1.display();
    }
    return 0;
}