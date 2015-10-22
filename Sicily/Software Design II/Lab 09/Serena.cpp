#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class SafeIntArray
{
public:
    SafeIntArray(int);
    void set(int,int);
    int get(int);
    ~SafeIntArray();
private:
    int size;
    int *array;
};

class IndexIntArray : public SafeIntArray
{
public:
    IndexIntArray(int,int);
    void set(int,int);
    int get(int);
private:
    int begin,last;
};

SafeIntArray::SafeIntArray(int size)
{
    this->size=size;
    array = new int[size+1];
    for(int i=0;i<size;i++)
        array[i]=0;
    cout << "I'm SafeIntArray\n";
}

void SafeIntArray::set(int index,int value)
{
    if(index>=0 && index<size)
        array[index]=value;
    else
        cout<<"Outside the boundary!"<<endl;
}

int SafeIntArray::get(int index)
{
    if(index>=0 && index<size)
        return array[index];
    else
    {
        cout<<"Outside the boundary!"<<endl;
        return -1;
    }
}

SafeIntArray::~SafeIntArray()
{
    delete []array;
    cout << "Goodbye SafeIntArray\n";
}

IndexIntArray::IndexIntArray(int begin,int last):SafeIntArray(last - begin + 1)
{
    cout << "I'm IndexIntArray\n";
    this->begin=begin;
    this->last=last;
}

void IndexIntArray::set(int index,int value)
{
    if(index>=begin && index<=last)
    {
        SafeIntArray::set(index-begin,value);
    }
    else
        cout<<"Outside the boundary!"<<endl;
}
int IndexIntArray::get(int index)
{
    if(index>=begin && index<=last)
    {
        return SafeIntArray::get(index-begin);
    }
    else
    {
        cout<<"Outside the boundary!"<<endl;
        return -1;
    }
}

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