#include "iostream"
#include "iomanip"
using namespace std;

int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
int row, col;
int cost[105][105];
int best[105][105];
bool visited[105][105];

void print() {
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j)
            cout << setw(4) << best[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void refresh(int r, int c) {
    int tr, tc;
    for (int i = 0; i < 4; ++i) {
        tr = r + dir[i][0];
        tc = c + dir[i][1];
        if (tr < 1 || tr > row || tc < 1 || tc > col)
            continue;
        if (best[tr][tc] > best[r][c]+cost[tr][tc]) {
            best[tr][tc] = best[r][c]+cost[tr][tc];
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--) {
        cin >> row >> col;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                cin >> cost[i][j];
                best[i][j] = 9999;
                visited[i][j] = false;
            }
        }
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        if (sr == er && sc == ec) {
            cout << cost[sr][sc] << endl;
        }
        else
        {
            visited[sr][sc] = true;
            best[sr][sc] = cost[sr][sc];
            refresh(sr, sc);
            while (true) {
                
                int inr, inc, min = 9999;
                for (int i = 1; i <= row; ++i) {
                    for (int j = 1; j <= col; ++j) {
                        if (!visited[i][j] && min > best[i][j]) {
                            min = best[i][j];
                            inr = i;
                            inc = j;
                        }
                    }
                }
                if (inr == er && inc == ec)
                    break;
                visited[inr][inc] = true;
                refresh(inr, inc);
                print();
            }
            cout << best[er][ec] << endl;
        }
    }
}