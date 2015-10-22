#include "iostream"
#include "fstream"
#include "string"

using namespace std;

int main(int argc, char const *argv[])
{
    string address;
    cin >> address;
    ifstream File1(address);
    cin >> address;
    ifstream File2(address);

    string str1;
    string str2;

    File1 >> str1;
    File2 >> str2;
    
    File1.close();
    File2.close();

    int size = str1.size() > str2.size() ? str2.size() : str1.size();

    cin >> address;
    ofstream File3(address);


    for (int i = 0; i < size; ++i)
    {
        if (str1[i] != str2[i])
        {
            File3 << "Different " << i << endl;
            File3.close();
            return 0;
        }
    }
    File3 << "Same" << endl;
    File3.close();
    return 0;
}                                 