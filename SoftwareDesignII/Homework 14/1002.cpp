template<typename T>
MyVector<T>::MyVector(int _capacity) : _capacity(_capacity), _size(-1)
{
    v = new T[_capacity];
}

template<typename T>
MyVector<T>::~MyVector()
{
    delete []v;
}

template<typename T>
void MyVector<T>::push_back(T element)
{
    v[++_size] = element;
}

template<typename T>
void MyVector<T>::pop_back()
{
    _size--;
}

template<typename T>
unsigned int MyVector<T>::size() const
{
    return _size + 1;
}

template<typename T>
T& MyVector<T>::operator [] (int index)
{
    return v[index];
}

template<typename T>
bool MyVector<T>::empty() const
{
    return _size == -1;
}

template<typename T>
void MyVector<T>::clear()
{
    _size = -1;
}                                 