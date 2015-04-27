#include "iostream"
#include "cmath"
using namespace std;

class Complex
{
public:
	Complex(double real = 0, double imag = 0);
    Complex operator+(Complex& com);
	Complex operator-(Complex& com);
    Complex operator*(Complex& com);
    Complex operator/(Complex& com);
	double& operator[](int i);
    double operator[](int i) const;
	friend ostream& operator<<(ostream& os, Complex& com);	//友元函数重载提取运算符"<<"
    friend istream& operator>>(istream& is, Complex& com);	//友元函数重载插入运算符">>"

private:
    double real;
    double imag;
};


Complex::Complex(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

Complex Complex::operator+(Complex& com)
{
	Complex result(this->real + com.real, this->imag + com.imag);
	return result;
}

Complex Complex::operator-(Complex& com)
{
	Complex result(this->real - com.real, this->imag - com.imag);
	return result;
}

Complex Complex::operator*(Complex& com)
{
	Complex result(this->real * com.real - this->imag * com.imag, 
			       this->real * com.imag + com.real * this->imag);
	return result;
}

Complex Complex::operator/(Complex& com)
{
	Complex result((this->real * com.real + this->imag * com.imag) / (com.real * com.real + com.imag * com.imag),
				   (com.real * this->imag - this->real * com.imag) / (com.real * com.real + com.imag * com.imag));
	return result;
}

double& Complex::operator[](int i)
{
	return i == 0 ? real : imag;
}

double Complex::operator[](int i) const
{
	return i == 0 ? real : imag;
}

ostream& operator<<(ostream& output, Complex& com)
{
	if (com.real != 0)
		output << com.real;
	if (com.imag != 0)
	{
		if (com.imag > 0 && com.real != 0)
			output << "+";
		else if (com.imag < 0)
			output << "-";
		if (abs(com.imag) != 1)
			output << abs(com.imag);
		output << "i";
	}
	if (com.real == 0 && com.imag == 0)
		output << 0;
	return output;
}

istream& operator>>(istream& input, Complex& com)
{
	input >> com.real >> com.imag;
	return input;
}

int main()
{
int T;
cin >> T;
while (T--) {
Complex com1, com2;
cin >> com1;
cout << com1 << endl;
cout << com1[0] << " " << com1[1] << endl;
 
cin >> com2;
cout << com2 << endl;
cout << com2[0] << " " << com2[1] << endl;
 
Complex c1 = com1 + com2;
cout << "(" << com1 << ")+(" << com2 << ")=" << c1 << endl;
 
Complex c2 = com1 - com2;
cout << "(" << com1 << ")-(" << com2 << ")=" << c2 << endl;
 
Complex c3 = com1 * com2;
cout << "(" << com1 << ")*(" << com2 << ")=" << c3 << endl;
 
Complex c4 = com1 / com2;
cout << "(" << com1 << ")/(" << com2 << ")=" << c4 << endl;
}
    return 0;
}