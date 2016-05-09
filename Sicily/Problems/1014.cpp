#include "iostream"
#include "vector"
using namespace std;

int sum(int num, int digit)
{
    vector<int> v;
    int result = 0;
    while(num != 0)
    {
        v.push_back(num % digit);
        num /= digit;
    }
    for(int i = 0; i < v.size(); i++)
        result += v[i];
    return result;

}int main(int argc, char const *argv[])
{
    for(int i = 1000; i <= 10000; i++)
        if(sum(i, 10) == sum(i, 12) && sum(i, 10) == sum(i, 16))
            cout << i << endl;
    return 0;
}
