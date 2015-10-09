template <typename T>
int binarySearch(T array[], T key, int arraySize)
{
    int imax = arraySize - 1;
    int imin = 0;
    while (imax >= imin)
    {
        int imid = (imin + imax) / 2;
        if(array[imid] == key)
            return imid; 
        else if (array[imid] < key)
            imin = imid + 1;
        else         
          imax = imid - 1;
    }
    return -1;
}                                 