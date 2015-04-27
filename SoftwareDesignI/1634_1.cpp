#include "iostream"
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int i=1; i <= t; i++)
	{
		cout << "test case " << i << ":\n";
		int grid[5][5] = {{},{}};
		int n;
		cin >> n;
		for (int i=1; i <= n; i++)
		{
			int rowNum,columnNum,player;
			char token;
			cin >> rowNum >> columnNum >> token;
			
			if (token == 'X')
				player = 1;
			else
				player = -1;

			grid[rowNum][4] += player;
			grid[4][columnNum] += player;
			if (rowNum == columnNum)
				grid[4][4] += player;
			if (rowNum + columnNum == 4)
				grid[0][4] += player;

			if (grid[4][1] == 3 || grid[4][2] == 3 || grid[4][3] == 3 || grid[4][4] == 3 || grid[3][4] == 3 || grid[2][4] == 3 || grid[1][4] == 3 || grid[0][4] == 3 )
				cout << "player1 won\n";
			else if (grid[4][1] == -3 || grid[4][2] == -3 || grid[4][3] == -3 || grid[4][4] == -3 || grid[3][4] == -3 || grid[2][4] == -3 || grid[1][4] == -3 || grid[0][4] == -3 )
				cout << "player2 won\n";
			else if (i == 9)
				cout << "draw\n";
			else
				cout << "unfished\n";
				
		}
	}
	return 0;
}
