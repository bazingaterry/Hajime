#include "string"
#include "iostream"
#include "cmath"
using namespace std;

class Rational
{
public:
    Rational(long numerator, long denominator);
    long getNumerator();
    long getDenominator();
    Rational add(Rational &secondRational);
    Rational subtract(Rational &secondRational);
    Rational multiply(Rational &secondRational);
    Rational divide(Rational &secondRational);
    int compareTo(Rational &secondRational);	// ”<”: -1, “=”: 0, “>”: 1
    bool equals(Rational &secondRational);
 
    // Define function operators for relational operators
    bool operator<(Rational &secondRational);
    bool operator<=(Rational &secondRational);
    bool operator>(Rational &secondRational);
    bool operator>=(Rational &secondRational);
    bool operator!=(Rational &secondRational);
    bool operator==(Rational &secondRational);
 
    // Define function operators for arithmetic operators
    Rational operator+(Rational &secondRational);
    Rational operator-(Rational &secondRational);
    Rational operator*(Rational &secondRational);
    Rational operator/(Rational &secondRational);
 
    // Define function operators for shorthand operators
    Rational& operator+=(Rational &secondRational);
    Rational& operator-=(Rational &secondRational);
    Rational& operator*=(Rational &secondRational);
    Rational& operator/=(Rational &secondRational);
 
    // Define function operator [], 0 for numerator and 1 for denominator
    long& operator[](const int &index);
 
    // Define function operators for prefix ++ and --
    Rational& operator++();
    Rational& operator--();
 
    // Define function operators for postfix ++ and --
    Rational operator++(int dummy);
    Rational operator--(int dummy);
 
    // Define function operators for unary + and -
    Rational operator+();
    Rational operator-();
 
    // Define the output and input operator
    friend ostream &operator<<(ostream &stream, Rational rational);
    friend istream &operator>>(istream &stream, Rational &rational);
 
    // Define function operator for conversion
    operator double();
 
private:
    long numerator;
    long denominator;
    static long gcd(long n, long d);
};

Rational::Rational(long numerator, long denominator)
{
    long gcm = gcd(denominator, numerator);
    this->numerator = numerator / gcm;
    this->denominator = denominator / gcm;
}


long Rational::getNumerator()
{
    return numerator;
}


long Rational::getDenominator()
{
    return denominator;
}

Rational Rational::add(Rational &secondRational)
{
    long denominator = this->denominator * secondRational.denominator;
    long numerator = this->numerator * secondRational.denominator + 
                     secondRational.numerator * this->denominator;
    long gcm = gcd(denominator, numerator);
    Rational result(numerator / gcm, denominator / gcm);
    return result;
}

Rational Rational::subtract(Rational &secondRational)
{
    long denominator = this->denominator * secondRational.denominator;
    long numerator = this->numerator * secondRational.denominator - 
                     secondRational.numerator * this->denominator;
    long gcm = gcd(denominator, numerator);
    Rational result(numerator / gcm, denominator / gcm);
    return result;
}

Rational Rational::multiply(Rational &secondRational)
{
    long denominator = this->denominator * secondRational.denominator;
    long numerator = this->numerator * secondRational.numerator;
    long gcm = gcd(denominator, numerator);
    Rational result(numerator / gcm, denominator / gcm);
    return result;
}

Rational Rational::divide(Rational &secondRational)
{
    long denominator = this->denominator * secondRational.numerator;
    long numerator = this->numerator * secondRational.denominator;
    long gcm = gcd(denominator, numerator);
    Rational result(numerator / gcm, denominator / gcm);
    return result;
}

int Rational::compareTo(Rational &secondRational) // ”<”: -1, “=”: 0, “>”: 1
{
    long denominator = this->denominator * secondRational.denominator;
    long numerator = this->numerator * secondRational.denominator - 
                     secondRational.numerator * this->denominator;
    if (numerator == 0)
        return 0;
    else if (numerator * denominator > 0)
        return 1;
    else
        return -1;
}

bool Rational::equals(Rational &secondRational)
{
    if (this->compareTo(secondRational) == 0)
        return true;
    else
        return false;
}
 
// Define function operators for relational operators
bool Rational::operator<(Rational &secondRational)
{
    if (this->compareTo(secondRational) == -1)
        return true;
    else
        return false;
}

bool Rational::operator<=(Rational &secondRational)
{
    if (this->compareTo(secondRational) == 1)
        return false;
    else
        return true;
}

bool Rational::operator>(Rational &secondRational)
{
    if (this->compareTo(secondRational) == 1)
        return true;
    else
        return false;
}

bool Rational::operator>=(Rational &secondRational)
{
    if (this->compareTo(secondRational) == -1)
        return false;
    else
        return true;
}

bool Rational::operator!=(Rational &secondRational)
{
    if (this->compareTo(secondRational) == 0)
        return false;
    else
        return true;
}

bool Rational::operator==(Rational &secondRational)
{
    if (this->compareTo(secondRational) == 0)
        return true;
    else
        return false;
}

// Define function operators for arithmetic operators
Rational Rational::operator+(Rational &secondRational)
{
    Rational result = this->add(secondRational);
    return result;
}

Rational Rational::operator-(Rational &secondRational)
{
    Rational result = this->subtract(secondRational);
    return result;
}

Rational Rational::operator*(Rational &secondRational)
{
    Rational result = this->multiply(secondRational);
    return result;
}

Rational Rational::operator/(Rational &secondRational)
{
    Rational result = this->divide(secondRational);
    return result;
}
 
// Define function operators for shorthand operators
Rational& Rational::operator+=(Rational &secondRational)
{
    long denominator = this->denominator * secondRational.denominator;
    long numerator = this->numerator * secondRational.denominator + 
                     secondRational.numerator * this->denominator;
    long gcm = gcd(denominator, numerator);
    Rational result(numerator / gcm, denominator / gcm);
    this->denominator = denominator;
    this->numerator = numerator;
    return *this;    
}

Rational& Rational::operator-=(Rational &secondRational)
{
    long denominator = this->denominator * secondRational.denominator;
    long numerator = this->numerator * secondRational.denominator - 
                     secondRational.numerator * this->denominator;
    long gcm = gcd(denominator, numerator);
    Rational result(numerator / gcm, denominator / gcm);
    this->denominator = denominator;
    this->numerator = numerator;
    return *this; 
}

Rational& Rational::operator*=(Rational &secondRational)
{
    long denominator = this->denominator * secondRational.denominator;
    long numerator = this->numerator * secondRational.numerator;
    long gcm = gcd(denominator, numerator);
    Rational result(numerator / gcm, denominator / gcm);
    this->denominator = denominator;
    this->numerator = numerator;
    return *this; 
}

Rational& Rational::operator/=(Rational &secondRational)
{
    long denominator = this->denominator * secondRational.numerator;
    long numerator = this->numerator * secondRational.denominator;
    long gcm = gcd(denominator, numerator);
    Rational result(numerator / gcm, denominator / gcm);
    this->denominator = denominator;
    this->numerator = numerator;
    return *this; 
}
 
// Define function operator [], 0 for numerator and 1 for denominator
long& Rational::operator[](const int &index)
{
    if (index)
        return denominator;
    else
        return numerator;
}
 
// Define function operators for prefix ++ and --
Rational& Rational::operator++()
{
    this->numerator += denominator;
    return *this;
}

Rational& Rational::operator--()
{
    this->numerator -= denominator;
    return *this;
}
 
// Define function operators for postfix ++ and --
Rational Rational::operator++(int dummy)
{
    ++(*this);
    Rational result(this->numerator - denominator, this->denominator);
    return result;
}

Rational Rational::operator--(int dummy)
{
    --(*this);
    Rational result(this->numerator + denominator, this->denominator);
    return result;
}
 
// Define function operators for unary + and -
Rational Rational::operator+()
{
    return *this;
}

Rational Rational::operator-()
{
    Rational result(-abs(this->numerator), abs(this->denominator));
    return result;
}
 
// Define the output and input operator
ostream& operator<<(ostream &stream, Rational rational)
{
    long gcm = rational.gcd(rational.denominator, rational.numerator);
    rational.numerator /= gcm;
    rational.denominator /= gcm;
    if (rational.denominator != 1) 
        stream << rational.numerator << "/" << rational.denominator;
    else
        stream << rational.numerator;
    return stream;
}

istream& operator>>(istream &stream, Rational &rational)
{
    stream >> rational.numerator >> rational.denominator;
    return stream;
}
 
// Define function operator for conversion
Rational::operator double()
{
    return double(numerator) / double(denominator);
}

long Rational::gcd(long n, long d)
{
    long tmp;
    while (d > 0)
    {
        tmp =  n % d;
        n = d;
        d = tmp;
    }
    return n;
}

int main()
{
    // Create and initialize two rational numbers r1 and r2.
    Rational r1(3, 2);
    Rational r2(2, 3);
    
    // Test relational operators
    cout << r1 << " > " << r2 << " is " << (r1 > r2) << endl;
    cout << r1 << " >= " << r1 << " is " << (r1 >= r1) << endl; 
    cout << r1 << " < " << r2 << " is " << (r1 < r2) << endl;
    cout << r1 << " <= " << r1 << " is " << (r1 <= r1) << endl;
    cout << r1 << " == " << r2 << " is " << (r1 == r2) << endl;
    cout << r1 << " == " << r1 << " is " << (r1 == r1) << endl;
    cout << r1 << " != " << r2 << " is " << (r1 != r2) << endl;
    cout << r1 << " != " << r1 << " is " << (r1 != r1) << endl;
 
 
    // Test toString, add, substract, multiply, and divide operators
    cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
    cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
    cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
    cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;
 
    // Test shorthand operators
    Rational r3(1, 2);
    r3 += r1;
    cout << "r3 is " << r3 << endl;
    r3 -= r1;
    cout << "r3 is " << r3 << endl;
    
    // Test function operator []
    Rational r4(1, 2);
    r4[0] = 3; r4[1] = 4;
    cout << "r4 is " << r4 << endl;
 
    // Test function operators for 
    // prefix ++ and --
    // postfix ++ and --
    r3 = r4++;
    cout << "r3 is " << r3 << endl;
    cout << "r4 is " << r4 << endl;
    r3 = r4--;
    cout << "r3 is " << r3 << endl;
    cout << "r4 is " << r4 << endl;
 
 
    r3 = ++r4;
    cout << "r3 is " << r3 << endl;
    cout << "r4 is " << r4 << endl;
    r3 = --r4;
    cout << "r3 is " << r3 << endl;
    cout << "r4 is " << r4 << endl;
 
    // Test function operator for conversion
    cout << "1 + " << r4 << " is " << (1 + r4) << endl;
 
 
    return 0;
}
