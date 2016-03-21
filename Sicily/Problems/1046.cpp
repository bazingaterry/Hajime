#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

class Period
{
public:
    int begin, end, length;
    double weight;
    Period(int begin, int end, double sum)
    {
        this->begin = begin;
        this->end = end;
        this->length = end - begin + 1;
        this->weight = sum / length;

    }
    bool operator< (const Period& p) const
    {
        if (this->weight > p.weight) return true;
        else if (this->weight < p.weight) return false;
        else if (this->length > p.length) return true;
        else if (this->length < p.length) return false;
        else if (this->end < p.end) return true;
        else return false;
    }
    friend ostream& operator<< (ostream& os, const Period& p)
    {
        os << p.begin << '-' << p.end;
        return os;
    }
};

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int quarters, requested, least;
        cin >> quarters >> requested >> least;
        int array[310];
        array[0] = 0;
        for (int j = 1; j <= quarters; ++j)
        {
            cin >> array[j];
            array[j] += array[j - 1];
        }
        vector<Period> v;
        for (int m = 1; m <= quarters - least + 1; ++m)
        {
            for (int n = m + least - 1; n <= quarters; ++n)
                v.push_back(Period(m, n, array[n] - array[m - 1]));
        }
        sort(v.begin(), v.end());
        cout << "Result for run " << i << ":\n";
        for (int k = 0; k < min((int)v.size(), requested); ++k)
            cout << v[k] << '\n';
    }
    return 0;
}
