#include "iostream"
#include "cstring"
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	string str[100];
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; ++i)
			cin >> str[i];

		for (int k = 0; k < n; ++k)
			for(int i=0,j=m-1;i<j; ++i,--j)
				swap(str[k][i],str[k][j]);

		for (int i = 0; i < n; ++i)
			for(int j=0; j < m; ++j)
				if (str[i][j] == 'b')
					str[i][j] = 'd';


		for (int i = 0; i < n; ++i)
			cout << str[i] << endl;
		cout << endl;
	}

	return 0;
}
