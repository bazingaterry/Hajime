#include "cstdlib"

template <typename Node_entry>struct Node
{
    Node_entry entry;
    Node* next;
    Node();
    Node(Node_entry item, Node *add_on = NULL);
};

template <typename Node_entry> Node<Node_entry>::Node()
{
    next = NULL;
}

template <typename Node_entry> Node<Node_entry>::Node(Node_entry item, Node *add_on)
{
    entry = item;
    next = add_on;
}

template<typename T> const Node<T>* medianElement(const Node<T>* head)
{
    const Node<T>* fast = head;
    const Node<T>* slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast == NULL)
            return slow;
        else
        {
            fast = fast->next;
            if (fast == NULL)
                return slow;
            slow = slow->next;
        }
    }
    return slow;
}