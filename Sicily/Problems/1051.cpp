#include "iostream"
#include "iomanip"
using namespace std;

const double PI = 3.1415927;

int main(int argc, char const *argv[])
{
    double diameter, time;
    int revolutions;
    while(cin >> diameter >> revolutions >> time && revolutions != 0)
    {
        static int cnt = 1;
        cout << "Trip #" << cnt++ << ": ";
        //  inches -> miles
        double distance = diameter * PI * revolutions / 5280 / 12;
        cout << setprecision(2) << fixed << distance << ' ' << distance / time * 3600 << endl;
    }
    return 0;
}
