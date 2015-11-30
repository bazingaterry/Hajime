#include "iostream"
#include "iomanip"
#include "cmath"
using namespace std;

const double PI = acos(-1.0);

struct circle
{
    double x;
    double y;
    double r;
};

double area(circle c1, circle c2)
{
    double dis = sqrt((c1.x - c2.x) * (c1.x - c2.x) + 
                      (c1.y - c2.y) * (c1.y - c2.y));
    if (c1.r > c2.r)
        swap(c1, c2);
    if (c1.r + c2.r <= dis) 
        return 0;
    else if (c2.r - c1.r >= dis) 
        return PI * c1.r * c1.r;
    else
    {
        double a1 = acos((c1.r * c1.r + dis * dis - c2.r * c2.r) / (2.0 * c1.r * dis));
        double a2 = acos((c2.r * c2.r + dis * dis - c1.r * c1.r) / (2.0 * c2.r * dis));
        return (a1 * c1.r * c1.r + a2 * c2.r * c2.r - c1.r * dis * sin(a1));
    }
}

int main(int argc, char const *argv[])
{
    circle c1, c2;
    cin >> c1.x >> c1.y >> c1.r;
    cin >> c2.x >> c2.y >> c2.r;
    cout << fixed << setprecision(7) << PI * (pow(c1.r, 2) + pow(c2.r, 2)) - area(c1, c2) << endl;
    return 0;
}                                 