template <class T, int capacity>
Stack<T, capacity>::Stack() : num(-1)
{
    elements = new T[capacity];
}

template <class T, int capacity>
Stack<T, capacity>::~Stack()
{
    delete []elements;
}

template <class T, int capacity>
bool Stack<T, capacity>::empty()
{
    return num == -1;
}

template <class T, int capacity>
T Stack<T, capacity>::peek()
{
    return elements[num];
}

template <class T, int capacity>
void Stack<T, capacity>::push(T value)
{
    elements[++num] = value;
}

template <class T, int capacity>
T Stack<T, capacity>::pop()
{
    return elements[num--];
}

template <class T, int capacity>
int Stack<T, capacity>::size()
{
    return num + 1;
}                                 