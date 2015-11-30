#include "iostream"
#include "algorithm"
using namespace std;

const int MAXN = 1000;

class array
{
private:
    int elem[MAXN];
public:
    int& operator[](int i)
    {
        return elem[i];
    }
};

class heap
{
private:
    int n;
    array h;
public:
    void clear()
    {
        n = 0;
    }
    int top()
    {
        return h[1];
    }
    int size()
    {
        return n;
    }
    void push(int);
    void pop();
};

void heap::push(int num)
{
    int index = ++n;
    h[index] = num;
    while (index > 1)   //  siftup
    {
        if (h[index] >= h[index / 2])
            return;
        else
        {
            swap(h[index], h[index / 2]);
            index /= 2;
        }
    }
}

void heap::pop()
{
    h[1] = h[n--];
    int index = 1;
    while (index < n)   //  shifdown
    {
        if (index * 2 > n)  //  no child
            return;
        else if (index * 2 + 1 > n) //  only one child
        {
            if (h[index] > h[index * 2])
                swap(h[index], h[index * 2]);
            return;
        }
        else
        {
            if (h[index] <= min(h[index * 2], h[index * 2 + 1]))
                return; //  need not to swap
            else
            {
                if (h[index * 2] < h[index * 2 + 1])
                    index *= 2;
                else
                    index = index * 2 + 1;
                swap(h[index], h[index / 2]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    heap h;
    int size;
    srand((unsigned)time(NULL));
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        int n = rand() % 100;
        cout << n << ' ';
        h.push(n);
    }
    cout << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << h.top() << ' ';
        h.pop();
    }
    cout << endl;
    return 0;
}