#include "iostream"
#include "string"
#include "sstream"

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    char ch;
    int letters = 0;
    int words = 0;
    while(cin.get(ch))
    {
        if(ch != '\n')
            letters++;
        str += ch;
    }
    istringstream strm(str);
    while(strm >> str)
        words++;

    cout << "Letters: " << letters
         << "\nWords: " << words << endl;

    return 0;
}                                 