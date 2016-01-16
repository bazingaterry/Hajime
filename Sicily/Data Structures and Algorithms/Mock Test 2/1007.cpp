#include "iostream"
using namespace std;

class UnionFind
{
private:
    int* father;
    const int capacity;
    
public:
    UnionFind(int cap) : capacity(cap + 1)
    {
        father = new int[cap + 1];
        for (int i = 1; i <= cap; ++i)
            father[i] = i;
    }
    ~UnionFind()
    {
        delete[] father;
    }
    inline void merge(int a, int b)
    {
        if(getFather(a) == getFather(b))
            return;
        else
            father[getFather(b)] = getFather(a);
    }
    inline int getFather(int a)
    {
        if (father[a] == a)
            return a;
        else
        {
            father[a] = getFather(father[a]);
            return father[a];
        }
    }
};

int main(int argc, char const *argv[])
{
	int p, q;
    UnionFind u(1000000);
    while (cin >> p >> q)
    {
        if (u.getFather(p) != u.getFather(q))
            cout << p << ' ' << q << '\n';
        u.merge(p, q);
    }
	return 0;
}