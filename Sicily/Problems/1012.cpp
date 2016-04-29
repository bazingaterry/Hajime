#include "iostream"
#include "cmath"
#include "iomanip"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while(cin >> n && n)
    {
        double cyl[110];
        for(int i = 0; i < n; i++)
            cin >> cyl[i];
        sort(cyl, cyl + n);
        double height = 1;
        double leftCyl = cyl[0];
        for(int i = 1; i < n; i++)
        {
            double rightCyl = (cyl[0] + cyl[i]) / 2;
            double dis = rightCyl - leftCyl;
            height += sqrt(4 - pow(dis, 2));
            leftCyl = rightCyl;
        }
        cout << setprecision(4) << fixed << (cyl[0] + cyl[n - 1]) / 2 << ' ' << height << endl;
    }
    return 0;
}
