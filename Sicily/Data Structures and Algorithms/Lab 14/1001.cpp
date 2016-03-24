#include "iostream"
#include "cstdio"
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
        for (int i = 0; i < capacity; ++i)
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
    int T;
    bool flag = false;
    scanf("%d", &T);
    while (T--)
    {
        if (flag)
            printf("\n");
        else
            flag = true;
        int n, m;
        scanf("%d%d", &n, &m);
        UnionFind uf(n);
        while (m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            uf.merge(a, b);
        }
        int q;
        cin >> q;
        while (q--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (uf.getFather(a) == uf.getFather(b))
                printf("Yes\n");
            else
                printf("No\n");
        }

    }
    return 0;
}
