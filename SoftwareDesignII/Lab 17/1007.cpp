#include <string>
#include <iostream>
#include "map"
using namespace std;

class Dictionary
{
private:
    map<string, string> dic;
public:
    void put(const string& english, const string& chinese)
    {
        dic[english] = chinese;
    }

    string get(const string& english)
    {
        if(dic.count(english))
            return dic[english];
        else
            return "[not found]";
    }
};

int main()
{
    Dictionary dictionary;
   
    // initialize dictionary
    while (true)
    {
        string english;
        cin >> english;
        if (english == "end") break;
        string chinese;
        cin >> chinese;
        dictionary.put(english, chinese);
    }
   
    // lookup dictionary
    while (true)
    {
      string english;
      cin >> english;
      if (english == "end") break;
      cout << dictionary.get(english) << endl;
    }
}