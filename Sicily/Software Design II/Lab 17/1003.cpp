#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;

class Sequence
{
public:
    Sequence(const vector<int>& v):seq(v) { }

    friend int second_max(const Sequence& s)
    {
        vector<int> v = s.seq;
        sort(v.begin(), v.end());
        if (v.size() <= 1)
            return -1;  
        int flag = v[v.size() - 1];
        for (int i = v.size() - 1; i>=0; --i)
        {
            if(v[i] == flag)
                continue;
            else
                return v[i];
        }
        return -1;
    }
private:
    vector<int> seq;
};                                 

int main(int argc, char const *argv[])
{
    int a[] = {3, 3, 3, 1};
    vector<int> v(a, a + 4);
    Sequence s(v);
    cout << second_max(s) << endl;
    return 0;
}
