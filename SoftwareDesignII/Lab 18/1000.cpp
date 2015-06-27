#include "map"
#include "string"
#include "iostream"
using namespace std;

class Array
{
public:
    int& operator[](int index)
    {
        return array1[index];
    }

    int& operator[](string index)
    {
        return array2[index];
    }

private:
    map<string, int> array2;
    map<int, int> array1;
};

int main(int argc, char const *argv[])
{
    Array arr;
    arr["one"] = 1;
    arr[1] = 1;

    cout << arr["one"] << endl;
    cout << arr[1] << endl;
    cout << arr["two"] << endl;
    return 0;
}