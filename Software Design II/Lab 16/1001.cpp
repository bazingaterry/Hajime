#include <iostream>
#include <set>

using namespace std;

class SetOperation
{
public:
    SetOperation(int*, int, int*, int);
    set<int> Union();
    set<int> Intersetion();
private:
    set<int> setA;
    set<int> setB;
};

SetOperation::SetOperation(int* arrA, int sizeA, int* arrB, int sizeB)
{
    setA.insert(arrA, arrA + sizeA);
    setB.insert(arrB, arrB + sizeB);
}

set<int> SetOperation::Union()
{
    set<int> result(setA.begin(), setA.end());
    result.insert(setB.begin(), setB.end());
    return result;
}

set<int> SetOperation::Intersetion()
{
    set<int> result;
    for (set<int>::iterator itor = setA.begin(); itor != setA.end(); ++itor)
    {
        if (setB.count(*itor))
        {
            result.insert(*itor);
        }
    }
    return result;
}

void printSet(const set<int>& s)
{
    bool first = true;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        if (!first)
            cout << " ";
        else 
            first = false;
        cout << *it;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    int a[7] = {8, 7, 5, 3, 1, 4, 6};
    int b[4] = {2, 3, 5, 4};
    SetOperation s1(a, 7, b, 4);
    printSet(s1.Union());
    printSet(s1.Intersetion());
    return 0;
}