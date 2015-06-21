#include "vector"
#include "iostream"
using namespace std;

class Mod
{
public:
    virtual int productMod(const vector<int>&) = 0;
};

class Mod9999 : public Mod
{
public:
    int productMod(const vector<int>& v)
    {
    	const int p = 9999;
    	long long result = 1;
    	for (int i = 0; i < v.size(); ++i)
    	{
    		result = (result * v[i] % p) % p;
    	}
    	return result;
    }
};

int main(int argc, char const *argv[])
{
	int arr[] = {2222, 3333, 1, 2333};
	vector<int> v(arr, arr + 4);
	Mod9999 myMod;
	cout << myMod.productMod(v) << endl;
	return 0;
}