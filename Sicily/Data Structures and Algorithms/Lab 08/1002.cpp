#include "iostream"
using namespace std;

struct linkedlist
{
    int data;
    linkedlist* next;
};

void mergesort(linkedlist*& head, int length)
{
    if (length > 1)
    {
        //  divide the first part
        int mid = length / 2;
        mergesort(head, mid);
        
        //  attach the middle of the list
        linkedlist* midPtr = head;
        for (int i = 0; i < mid; ++i)
            midPtr = midPtr->next;
        //  divide the second part
        mergesort(midPtr, length - mid);
        
        //  store the linked list temporary
        int* tempArray = new int[length];
        linkedlist* tempPtr = head;
        //  copy the element
        for (int i = 0; i < length; ++i)
        {
            tempArray[i] = tempPtr->data;
            tempPtr = tempPtr->next;
        }
        //  merge
        int first = 0;
        int second = mid;
        tempPtr = head;
        while (first < mid && second < length)
        {
            if (tempArray[first] < tempArray[second])
            {
                tempPtr->data = tempArray[first++];
                tempPtr = tempPtr->next;
            }
            else
            {
                tempPtr->data = tempArray[second++];
                tempPtr = tempPtr->next;
            }
        }
        while (first < mid)
        {
            tempPtr->data = tempArray[first++];
            tempPtr = tempPtr->next;
        }
        while (second < length)
        {
            tempPtr->data = tempArray[second++];
            tempPtr = tempPtr->next;
        }
        delete[] tempArray;
    }
}

int main(int argc, char const *argv[])
{
    int n = 5;
    linkedlist* head = new linkedlist;
    head->data = 5;
    linkedlist* pre = head;
    while (n--)
    {
        pre->next = new linkedlist;
        pre = pre->next;
        pre->data = n;
    }
    pre->next = NULL;
       
    pre = head;   
    cout << "before sort:\n";
    while (pre != NULL)
    {
        cout << pre->data << ' ';
        pre = pre->next;
    }

    mergesort(head, 6);
    
    pre = head;
    cout << "\nafter sort:\n";
    while (pre != NULL)
    {
        cout << pre->data << ' ';
        pre = pre->next;
    }
    
    return 0;
}
