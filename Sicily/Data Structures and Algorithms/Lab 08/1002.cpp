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
        const int mid = length / 2;
        //  attach the middle of the list
        linkedlist* midPtr = head;
        for (int i = 0; i < mid; ++i)
            midPtr = midPtr->next;

        //  divide the first part
        mergesort(head, mid);
        
        //  divide the second part
        mergesort(midPtr, length - mid);
        
        //  creat head pointer
        linkedlist* tempPtr = new linkedlist;
        //  record head pointer
        linkedlist* headPtr = tempPtr;
        //  merge
        int first = 0;
        int second = mid;
        while (first < mid && second < length)
        {
            if (head->data < midPtr->data)
            {
                tempPtr->next = head;
                head = head->next;
                tempPtr = tempPtr->next;
                first++;
            }
            else
            {
                tempPtr->next = midPtr;
                midPtr = midPtr->next;
                tempPtr = tempPtr->next;
                second++;
            }
        }
        while (first < mid)
        {
            tempPtr->next = head;
            head = head->next;
            tempPtr = tempPtr->next;
            first++;
        }
        while (second < length)
        {
            tempPtr->next = midPtr;
            midPtr = midPtr->next;
            tempPtr = tempPtr->next;
            second++;
        }
        tempPtr->next = NULL;
        head = headPtr->next;
        delete headPtr;
    }
}

int main(int argc, char const *argv[])
{
    int n = 9;
    linkedlist* head = new linkedlist;
    head->data = -1;
    linkedlist* pre = head;
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        pre->next = new linkedlist;
        pre = pre->next;
        pre->data = rand() % 100;
    }
    pre->next = NULL;
    
    pre = head;
    cout << "before sort:\n";
    while (pre != NULL)
    {
        cout << pre->data << ' ';
        pre = pre->next;
    }
    cout << endl;
    
    mergesort(head, n + 1);
    
    pre = head;
    cout << "after sort:\n";
    while (pre != NULL)
    {
        cout << pre->data << ' ';
        pre = pre->next;
    }
    cout << endl;
    return 0;
}
