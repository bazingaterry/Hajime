#include "iostream"
#include "set"
#include "queue"
#include "string"
using namespace std;

class MagicBoard
{
    int factorial(int n)
    {
        if (n == 1 || n == 0) return 1;
        else return n * factorial(n-1);
    }

public:
    int step;
    int magicBoard[8];
    string op;

    MagicBoard() : step(0)
    {
        for (int i = 0; i < 4; ++i)
            magicBoard[i] = i+1;
        for (int i = 4; i < 8; ++i)
            magicBoard[i] = 12-i;
    }

    MagicBoard(int cantorExpansion) : step(0)
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
        for (int i = 0; i < 8; ++i)
        {
            int index = cantorExpansion / factorial(7-i);
            magicBoard[i] = v[index];
            v.erase(v.begin() + index);
            cantorExpansion %= factorial(7-i);
        }
    }

    int getCantorExpansion()
    {
        int result = 0;
        for (int i = 0; i < 8; ++i)
        {
            int cnt = 0;
            for (int j = i+1; j < 8; ++j)
                if (magicBoard[j] < magicBoard[i]) cnt++;
            result += cnt * factorial(7-i);
        }
        return result;
    }

    MagicBoard operationA()
    {
        swap(magicBoard[0], magicBoard[4]);
        swap(magicBoard[1], magicBoard[5]);
        swap(magicBoard[2], magicBoard[6]);
        swap(magicBoard[3], magicBoard[7]);
        op += 'A';
        step++;
        return *this;
    }

    MagicBoard operationB()
    {
        int tmp = magicBoard[3];
        magicBoard[3] = magicBoard[2];
        magicBoard[2] = magicBoard[1];
        magicBoard[1] = magicBoard[0];
        magicBoard[0] = tmp;
        tmp = magicBoard[7];
        magicBoard[7] = magicBoard[6];
        magicBoard[6] = magicBoard[5];
        magicBoard[5] = magicBoard[4];
        magicBoard[4] = tmp;
        op += 'B';
        step++;
        return *this;
    }

    MagicBoard operationC()
    {
        int tmp = magicBoard[1];
        magicBoard[1] = magicBoard[5];
        magicBoard[5] = magicBoard[6];
        magicBoard[6] = magicBoard[2];
        magicBoard[2] = tmp;
        op += 'C';
        step++;
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    int N;
    while (cin >> N && N != -1)
    {
        queue<MagicBoard> q;
        set<int> s;
        MagicBoard init, tmp, res;
        for (int i = 0; i < 8; ++i)
            cin >> tmp.magicBoard[i];
        int des = tmp.getCantorExpansion();
        q.push(init);
        s.insert(init.getCantorExpansion());
        bool nf = true;
        if (q.front().getCantorExpansion() == des)
        {
            nf = false;
            res = q.front();
        }
        {
            while (!q.empty())
            {
                MagicBoard ele = MagicBoard(q.front()).operationA();
                if (s.find(ele.getCantorExpansion()) == s.end() && ele.step <= N)
                {
                    if (ele.getCantorExpansion() == des)
                    {
                        nf = false;
                        res = ele;
                        break;
                    }
                    else
                    {
                        q.push(ele);
                        s.insert(ele.getCantorExpansion());
                    }
                }
                ele = MagicBoard(q.front()).operationB();
                if (s.find(ele.getCantorExpansion()) == s.end() && ele.step <= N)
                {
                    if (ele.getCantorExpansion() == des)
                    {
                        nf = false;
                        res = ele;
                        break;
                    }
                    else
                    {
                        q.push(ele);
                        s.insert(ele.getCantorExpansion());
                    }
                }
                ele = MagicBoard(q.front()).operationC();
                if (s.find(ele.getCantorExpansion()) == s.end() && ele.step <= N)
                {
                    if (ele.getCantorExpansion() == des)
                    {
                        nf = false;
                        res = ele;
                        break;
                    }
                    else
                    {
                        q.push(ele);
                        s.insert(ele.getCantorExpansion());
                    }
                }
                q.pop();
            }
        }
        if (nf) cout << -1 << endl;
        else cout << res.step << ' ' << res.op << endl;
    }
    return 0;
}
