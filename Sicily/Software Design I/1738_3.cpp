#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    const int MAX = 100;
    while (cin >> n && n != 0)
    {
        printf("1\t\n");
        int triangel[MAX];
        triangel [1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            int tmp[MAX] = {0, 1};
            for (int j = 2; j <= i - 1; ++j)    //  generate
            {
                tmp[j] = triangel[j - 1] + triangel[j];
            }

            for (int j = 1; j <= i - 1; ++j)    //  copy
            {
                triangel[j] = tmp[j];
            }
            triangel[i] = 1;

            for (int j = 1; j <= i; ++j) //  print
            {
                printf("%d\t", triangel[j]);
            }
            printf("\n");
        }
    }
    return 0;
}