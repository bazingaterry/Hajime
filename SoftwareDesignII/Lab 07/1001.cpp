#include "iostream"
#include "cstdio"
using namespace std;

class MyVector
{
public:
    MyVector(int = 0, int = 0, int = 0);
    MyVector(const MyVector& );
    void display();
    friend MyVector add(MyVector& v1, MyVector& v2);
    friend MyVector sub(MyVector& v1, MyVector& v2);
    friend int dot(MyVector& v1, MyVector& v2);
    friend MyVector cross(MyVector& v1, MyVector& v2);
private:
    int x, y, z;
};

MyVector::MyVector(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

MyVector::MyVector(const MyVector& newMyVector)
{
	x = newMyVector.x;
	y = newMyVector.y;
	z = newMyVector.z;
}

void MyVector::display()
{
	printf("(%d,%d,%d)\n", x, y, z);
}

MyVector add(MyVector& v1, MyVector& v2)
{
	MyVector result(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); 
	return result;
}

MyVector sub(MyVector& v1, MyVector& v2)
{
	MyVector result(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return result;
}

int dot(MyVector& v1, MyVector& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

MyVector cross(MyVector& v1, MyVector& v2)
{
	MyVector result(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	return result;
}

/*
int main()
{
    MyVector a;
    MyVector b(1);
    MyVector c(2,3);
    MyVector d(3,4,5);
    MyVector e(c);
    MyVector x = add(a, b);
    x.display();
    MyVector y = sub(b, c);
    y.display();
    MyVector z = cross(c, d);
    z.display();
    int w = dot(d, e);
    cout << w << endl;
    return 0;
}
*/