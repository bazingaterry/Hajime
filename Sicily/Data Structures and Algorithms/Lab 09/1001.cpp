#include "iostream"
#include "vector"
using namespace std;

int select(int* array, int size, int k)
{
    int pivot = array[0];
    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        while (array[right] >= pivot && left < right)
            right--;
        while (array[left] <= pivot && left < right)
            left++;
        if (left < right)
            swap(array[left], array[right]);
    }
    swap(array[0], array[left]);
    if (k < left)
        return (select(array, left, k));
    else if (k == left)
        return array[left];
    else
        return (select(array + left + 1, size - left - 1, k - left - 1));
}

int main(int argc, char const *argv[])
{
    int size;
    srand((unsigned)time(NULL));
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; ++i)
        array[i] = rand() % 100;
    int k = rand() % size;
    vector<int> v(array, array + size);
    nth_element(v.begin(),v.begin() + k, v.end());
    if (select(array, size, k) == v[k])
        cout << "AC\n";
    else
        cout << "WA\n";
    return 0;
}