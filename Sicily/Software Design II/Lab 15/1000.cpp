#include "bits/stdc++.h"
using namespace std;

template <typename T, int capacity>
class Array
{
public:
	Array(); // Construct an empty Array.
	~Array(); // Deconstructor
	bool empty(); // Return true if the array is empty.
	void push(T value); // Push back an element into the array.
	T pop(); // Remove the last element of the array and returns it.
	int size(); // Return the number of elements in the array.
	T& operator[] (int index);  // Return the element by index.

private:
    T* elements; // Point to an array that stores elements.
    int num; // The number of the elements in the Array.
};

class ArrayException
{
public:
	ArrayException(const char* msg);
	const char* what() const;
private:
	const char* message;
};

template <typename T, int capacity>
Array<T, capacity>::Array() : num(-1)
{
	elements = new T[capacity];
}

template <typename T, int capacity>
Array<T, capacity>::~Array()
{
	delete elements;
}

template <typename T, int capacity>
bool Array<T, capacity>::empty()
{
	return num == -1;
}

template <typename T, int capacity>
void Array<T, capacity>::push(T value)
{
	if (num + 1 < capacity)
		elements[++num] = value;
	else
		throw ArrayException ("Array Full Exception");
}

template <typename T, int capacity>
T Array<T, capacity>::pop()
{
	if (num == -1)
		throw ArrayException ("Array Empty Exception");
	else
		return elements[num--];
}

template <typename T, int capacity>
int Array<T, capacity>::size()
{
	return num + 1;
}

template <typename T, int capacity>
T& Array<T, capacity>::operator[] (int index)
{
	if (index < 0 || index > num)
		throw ArrayException ("Out of Range Exception");
	else
		return elements[index];
}

ArrayException::ArrayException(const char* msg) : message(msg)
{
}

const char* ArrayException::what() const
{
	return message;
}

void test()
{
	Array<int,1> intArray;
	try
	{
		intArray.push(1);
	}
	catch(ArrayException ex)
	{
		cout << ex.what() << endl;
	}
	
	try
	{
		cout << intArray[3] << endl;
	}
	catch (ArrayException ex)
	{
		cout << ex.what() << endl;
	}

	try
	{
		cout << intArray.pop() << endl;
	}
	catch (ArrayException ex)
	{
		cout << ex.what() << endl;
	}
}

int main(int argc, char const *argv[])
{
	test();
	return 0;
}
