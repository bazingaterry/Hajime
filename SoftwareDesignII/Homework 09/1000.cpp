class Rational
{
public:
    Rational();
    Rational(long numerator, long denominator);
    long getNumerator();
    long getDenominator();
    Rational add(Rational &secondRational);
    Rational subtract(Rational &secondRational);
    Rational multiply(Rational &secondRational);
    Rational divide(Rational &secondRational);
    int compareTo(Rational &secondRational);	// ”<”: -1, “=”: 0, “>”: 1
    bool equals(Rational &secondRational);
    int intValue();
    double doubleValue();
    string toString();
 
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

Rational::Rational()
{
	
}
    Rational(long numerator, long denominator);
    long getNumerator();
    long getDenominator();
    Rational add(Rational &secondRational);
    Rational subtract(Rational &secondRational);
    Rational multiply(Rational &secondRational);
    Rational divide(Rational &secondRational);
    int compareTo(Rational &secondRational);	// ”<”: -1, “=”: 0, “>”: 1
    bool equals(Rational &secondRational);
    int intValue();
    double doubleValue();
    string toString();
 
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