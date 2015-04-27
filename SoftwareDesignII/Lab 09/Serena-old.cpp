#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class SafeIntArray
{
public:
    SafeIntArray();
    SafeIntArray(int );
    void setsize(int);
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
SafeIntArray::SafeIntArray()
{
    array = new int[size+1];
}
SafeIntArray::SafeIntArray(int size)
{
    this->size=size;
    array = new int[size+1];
    for(int i=0;i<size;i++)
        array[i]=0;
    
    
    //cout<<"size"<<size<<endl;
}
void SafeIntArray::setsize(int size)
{
    this->size=size;
}
void SafeIntArray::set(int index,int value)
{
    if(index>=0 && index<size)
        array[index]=value;
    else
        cout<<"Outside the boundary!"<<endl;
   // cout<<"size"<<size<<endl;
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
}

IndexIntArray::IndexIntArray(int begin,int last)
{
    this->begin=begin;
    this->last=last;
    SafeIntArray::setsize(last-begin+1);
    
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