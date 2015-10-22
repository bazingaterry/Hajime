#include "iostream"
using namespace std;

class Student
{
public:
    int grade;
    int id;
    int rank;
};

int main(int argc, char const *argv[])
{
    /* read */
    int n;  //  studentQuantity
    cin >> n;
    Student stu[101];
    for (int i = 0; i < n; ++i)
    {
        cin >> stu[i].id >> stu[i].grade;
    }

    /* sort */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (stu[i].grade > stu[j].grade)
            {
                swap(stu[i], stu[j]);
            }
        }
    }
    stu[1].rank = 1;
    int rank = 1;
    for (int i = 1; i < n; ++i)
    {
        if (stu[i].grade == stu[i - 1].grade)
            stu[i].rank = rank;
        else stu[i].rank = ++rank;
    }

    /* print */
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            for (int i = 0; i < n; ++i)
            {
                if (stu[i].id == y)
                    cout << stu[i].grade << endl;
            }
        }
        else if (x == 2)
        {
            for (int i = 0; i < n; ++i)
            {
                if (stu[i].id == y)
                    cout << stu[i].rank << endl;
            }
        }
        else if (x == 3)
        {
            for (int i = 0; i < n; ++i)
            {
                if (stu[i].grade == y)
                {
                    cout << stu[i].rank << endl;
                    break;
                }
            }
        }
        else
        {
            int total = 0;
            for (int i = 0; i < n; ++i)
            {
                if (stu[i].grade == y)
                    total++;
            }
            cout << total << endl;
        }
    }
    return 0;
}
