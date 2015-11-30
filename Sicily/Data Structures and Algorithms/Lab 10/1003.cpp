#include "cstdio"
#include "string"
using namespace std;

const string dic = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    string result;
    int index = 1;
    result = "A";
    printf("\nA\n");
    while(result[0] != dic[n - 1])
    {
        if (result[result.size() - 1] != dic[n - 1])
        {
            result += result[result.size() - 1] + 1;
            index = result.size() - 1;
        }
        else
            result[--index]++;
        result = result.substr(0, index + 1);
        printf("%s\n", result.c_str());
    }
    return 0;
}