#include "map"
#include "iostream"
using namespace std;

template <typename T>
void frequency(T arr[], int len)
{
	map<T, int> f;
	for (int i = 0; i < len; ++i)
		f[arr[i]]++;
	for (typename map<T, int>::iterator i = f.begin(); i != f.end(); i++)
		cout << i->first << ' ' << i->second << endl;
}

int main(int argc, char const *argv[])
{
	int a[4] = {1, 2, 1, 1};
	frequency(a, 4);
	return 0;
}