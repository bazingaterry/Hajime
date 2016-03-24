#include "iostream"
#include "vector"
#include "queue"
#include "cmath"
#include "iomanip"
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

class Point
{
public:
    Point(int x, int y, int index)
    {
        this->x = x;
        this->y = y;
        this->index = index;
    }
    int x, y, index;
    bool operator< (const Point& otherPoint) const
    {
        if (x < otherPoint.x)
            return true;
        else if (x > otherPoint.x)
            return false;
        else return y < otherPoint.y;
    }
};

class Edge
{
public:
    Edge(const Point& p1, const Point& p2)
    {
        this->index1 = p1.index;
        this->index2 = p2.index;
        distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
    double distance;
    int index1, index2;
};

struct cmp
{
    bool operator()(const Edge& x, const Edge& y)
    {
        return x.distance > y.distance + 10e-6;
    }
};

int main(int argc, char const *argv[])
{
    int n, k;
    while(cin >> n >> k)
    {
        vector<Point> v;
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            v.push_back(Point(x, y, i));
        }
        priority_queue<Edge, vector<Edge>, cmp> pq;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                pq.push(Edge(v[i], v[j]));
        UnionFind s(100);
        double result;
        for (int cnt = 0; cnt < n - k + 1;)
        {
            if (s.getFather(pq.top().index1) != s.getFather(pq.top().index2))
            {
                s.merge(pq.top().index1, pq.top().index2);
                result = pq.top().distance;
                cnt++;
            }
            pq.pop();
        }
        cout << setprecision(2) << fixed << result << endl;
    }
    return 0;
}
