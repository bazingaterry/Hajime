#include "iostream"
using namespace std;

int* post = NULL;
int j;

void findPost(int* pre, int* in, int size)
{
    if (size <= 0)
        return;
    else
    {
        post[j--] = pre[0];
        int i = 0;
        while(in[i] != pre[0])
            i++;
        findPost(pre + 1 + i, in + i + 1, size - i - 1);
        if (in[0] == pre[0])
            findPost(pre + 1, in + 1, i);
        else
            findPost(pre + 1, in, i);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    cin >> size;
    int* pre = new int[size];
    int* in = new int[size];
    post = new int[size];
    for (int i = 0; i < size; ++i)
        cin >> pre[i];
    for (int i = 0; i < size; ++i)
        cin >> in[i];
    j = size - 1;
    findPost(pre, in, size);
    cout << post[0];
    for (int i = 1; i < size; ++i)
        cout << ' ' << post[i];
    cout << endl;
    return 0;
}