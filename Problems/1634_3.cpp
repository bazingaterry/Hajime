#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{

	int t;
	cin >> t;
	for (int testCase = 1; testCase <= t; testCase++)
	{
		cout << "test case " << testCase << ":\n";
		char ch[101][10];
		int score[100] = {};
		int student;
		cin >> student;
		
		for (int i = 0; i < student; ++i)
			for (int j = 0; j < 10; ++j)
				cin >> ch[i][j];

		for (int i = 0; i < 10; ++i)
			cin >> ch[100][i];

		for (int i = 0; i < student; ++i)
			for (int j = 0; j < 10; ++j)
				if (ch[i][j] == ch[100][j])
					score[i]++;

		for (int i = 0; i <= 10; ++i)
			for (int j = 0; j < student; ++j)
				if (score[j] == i)
					cout << "Student " << j << ": " << i << endl;
	}

	return 0;
}
