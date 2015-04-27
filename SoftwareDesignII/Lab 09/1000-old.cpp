#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;

/////////////////////////////////////////////////////////////
// Problem#: 14453
// Submission#: 3706473
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
class SafeIntArray
{
public:
    SafeIntArray(int size);
    ~SafeIntArray();
    void set(int index, int data);
    int get(int index);

protected:
    int begin;
    int end;
    int* arrayPtr;
};

SafeIntArray::SafeIntArray(int size)
{
    begin = 0;
    end = size - 1;
    arrayPtr = new int[size];
}

SafeIntArray::~SafeIntArray()
{
    delete[] arrayPtr;
}

void SafeIntArray::set(int index, int data)
{
    if (begin <= index && index <= end)
    {
        arrayPtr[index - begin] = data;
    }
    else
    {
        cout << "Outside the boundary!\n";
    }
}

int SafeIntArray::get(int index)
{
    if (begin <= index && index <= end)
    { 
        return arrayPtr[index - begin];
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
};

IndexIntArray::IndexIntArray(int begin, int end):SafeIntArray(end - begin + 1)
{
    this->begin = begin;
    this->end = end;
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