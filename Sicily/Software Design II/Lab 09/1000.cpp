#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;

/////////////////////////////////////////////////////////////
class SafeIntArray
{
public:
    SafeIntArray(int size);
    ~SafeIntArray();
    void set(int index, int data);
    int get(int index);

private:
    int size;
    int* arrayPtr;
};

SafeIntArray::SafeIntArray(int size)
{
    this->size = size;
    arrayPtr = new int[size];
}

SafeIntArray::~SafeIntArray()
{
    delete[] arrayPtr;
}

void SafeIntArray::set(int index, int data)
{
    if (0 <= index && index <= size - 1)
    {
        arrayPtr[index] = data;
    }
    else
    {
        cout << "Outside the boundary!\n";
    }
}

int SafeIntArray::get(int index)
{
    if (0 <= index && index <= size - 1)
    { 
        return arrayPtr[index];
    }
    else
    {
        cout << "Outside the boundary!\n";
        return -1;
    }
}

class IndexIntArray : public SafeIntArray
{
public:
    IndexIntArray(int begin, int end);
    void set(int index, int data);
    int get(int index);

private:
    int begin;
    int end;
};

IndexIntArray::IndexIntArray(int begin, int end):SafeIntArray(end - begin + 1)
{
    this->begin = begin;
    this->end = end;
}

void IndexIntArray::set(int index, int data)
{
    SafeIntArray::set(index - begin, data);
}

int IndexIntArray::get(int index)
{
    return SafeIntArray::get(index - begin);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
 
int main(int argc, char** argv) {
    
    int test;
    cin >> test;
    while (test --) {
        int size, n;
        cin >> size;
        SafeIntArray sia(size);
        // test SafeIntArray::set(int,int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            sia.set(index, data);
        }
        // test SafeIntArray::get(int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = sia.get(index);
            if (value != -1) {
                cout << value << endl;
            }
        }

        int begin, end;
        cin >> begin >> end;
        IndexIntArray iia(begin, end);
        // test IndexIntArray::set(int,int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            iia.set(index, data);
        }
        // test IndexIntArray::get(int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = iia.get(index);
            if (value != -1) {
                cout << value << endl;
            }
        }
    }

    return 0;
}