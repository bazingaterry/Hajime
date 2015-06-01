#include <bits/stdc++.h>
using namespace std;

template <typename T>
T* Sort (const T array[], const int size)
{
    T* tmp = new T[size];
    for (int i = 0; i < size; i++)
        tmp[i] = array[i];
    sort(tmp, tmp + size);
    return tmp;
}

template <typename T>
T maximumValue (const T array[], const int size)
{
    T* tmp = Sort(array, size);
    return tmp[size - 1];
    delete []tmp;
}

template <typename T>
T minimumValue (const T array[], const int size)
{
    T* tmp = Sort(array, size);
    return tmp[0];
    delete []tmp;
}

template <typename T>
T medianValue (const T array[], const int size)
{
    T* tmp = Sort(array, size);
    return tmp[size / 2];
    delete []tmp;
}                                 