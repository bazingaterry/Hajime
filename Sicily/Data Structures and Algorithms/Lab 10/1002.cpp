#include "iostream"
#include "string"
using namespace std;

const string dic = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n;
bool isSelected[19];

void dfs(int step)
{
	if (step == n)
	{
		for (int i = 0; i < n; ++i)
			if (isSelected[i]) cout << dic[i];
		cout << endl;
	}
	else
	{
		isSelected[step] = false;
		dfs(step + 1);
		isSelected[step] = true;
		dfs(step + 1);
	}
}

int main(int argc, char const *argv[])
{
	cin >> n;
	dfs(0);
	return 0;
}