#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	int* table = new int[m];
	bool* exist = new bool[m];
	while(n--)
	{
		int key;
		cin >> key;
		int index = key % m;
		while(exist[index])
			index = (index + 1) % m;
		table[index] = key;
		exist[index] = true;
	}
	for (int i = 0; i < m; ++i)
	{
		if (exist[i]) cout << i << '#' << table[i] << '\n';
		else cout << i << "#NULL\n";
	}

	return 0;
}