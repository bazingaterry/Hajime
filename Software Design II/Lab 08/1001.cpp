#include "cstring"
#include "iostream"
using namespace std;
/*****
class String
{
public:
    String();                  // str = ""
    String(const char*);       // str = "abc" 
    String(const String&);     // str = other_string
    String& operator=(const char *);
    String& operator=(const String&);
    String operator+(const String&);
    ~String();
 
    char& operator[](int i);
    char operator[](int i) const;
 
    int size() const;
 
    String& operator+=(const String&);
    String& operator+=(const char*);
 
    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
 
    friend bool operator==(const String& x, const char* s);
    friend bool operator==(const String& x, const String& y);
    friend bool operator!=(const String& x, const char* s);
    friend bool operator!=(const String& x, const String& y);

private:
    char* str;
};
****/

String::String()
{
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* ch)
{
    str = new char[strlen(ch) + 1];
    for (int i = 0; i <= strlen(ch); ++i)
        str[i] = ch[i];
}

String::String(const String& newString)
{
    str = new char[strlen(newString.str) + 1];
    for (int i = 0; i <= strlen(newString.str); ++i)
        str[i] = newString.str[i];
}

String& String::operator=(const char* ch)
{
    str = new char[strlen(ch) + 1];
    for (int i = 0; i <= strlen(ch); ++i)
        str[i] = ch[i];
    return *this;
}

String& String::operator=(const String& newString)
{
    for (int i = 0; i <= strlen(newString.str); ++i)
        str[i] = newString.str[i];
    return *this;
}

String String::operator+(const String& newString)
{
    int len1 = strlen(this->str);
    int len2 = strlen(newString.str);
    char* tmp = new char[len1 + len2 + 1];
    for (int i = 0; i < len1; ++i)  // copy the first string
        tmp[i] = this->str[i];
    for (int i = len1; i <= len1 + len2; ++i)   //  copy the second string
        tmp[i] = newString.str[i - len1];
    String result(tmp);
    return result;

}

String::~String()
{
    delete []str;
}

char& String::operator[](int i)
{
    return str[i];
}
char String::operator[](int i) const
{
    return str[i];
}
 
int String::size() const
{
    return strlen(str);
}
 
String& String::operator+=(const String& newString)
{
    int len1 = strlen(this->str);
    int len2 = strlen(newString.str);
    char* tmp = new char[len1 + len2 + 1];
    for (int i = 0; i < len1; ++i)
        tmp[i] = this->str[i];
    for (int i = len1; i <= len1 + len2; ++i)
        tmp[i] = newString.str[i - len1];
    str = tmp;
    return *this;
}

String& String::operator+=(const char* ch)
{
    int len1 = strlen(this->str);
    int len2 = strlen(ch);
    char* tmp = new char[len1 + len2 + 1];
    for (int i = 0; i < len1; ++i)
        tmp[i] = this->str[i];
    for (int i = len1; i <= len1 + len2; ++i)
        tmp[i] = ch[i - len1];
    str = tmp;
    return *this;   
}
 
ostream& operator<<(ostream& output, const String& MyString)
{
    output << MyString.str;
    return output;
}

istream& operator>>(istream& input, String& MyString)
{
    input >> MyString.str;
    return input;
}
 
bool operator==(const String& x, const char* s)
{
    if (strlen(x.str) != strlen(s))
        return false;
    else
    {
        for (int i = 0; i < strlen(s); ++i)
        {
            if (x.str[i] != s[i])
                return false;
        }
        return true;
    }
}

bool operator==(const String& x, const String& y)
{
    if (x == y.str)
        return true;
    else
        return false;
}

bool operator!=(const String& x, const char* s)
{
    if (x == s)
        return false;
    else
        return true;
}

bool operator!=(const String& x, const String& y)
{
    if (x == y)
        return false;
    else
        return true;
}

/**************
String f1(String a, String b)
{
  a[2] = 'x';
  char c = b[2];
  cout << "in f: " << a << ' ' << b << ' ' << c << '\n';
  return b;
}
 
void f2(String s, const String& r)
{
  char c1 = s[1];  // c1 = s.operator[](1).operator char()
  s[1] = 'c';    // s.operator[](1).operator=('c')
 
  char c2 = r[1];  // c2 = r.operator[](1)
//  r[1] = 'd';    // error: assignment to non-lvalue char, r.operator[](1) = 'd'
}
 
void f()
{
  String x, y, s;
  cout << "Please enter two strings\n";
  cin >> x >> y;
  cout << "x= " << x << " , y = " << y << '\n';
 
    y = f1(x,y);
    cout << y << endl;
    
    f2(x,y);
 
  cout << "s = \"" << s << "\"" << endl;
  s = "abc";
  cout << "s = \"" << s << "\"" << endl;
 
    cout << "\"" << x << "\" + \"" << y << "\" = " << "\"" << x+y << "\"\n";
  String z = x;
  if (x != z) cout << "x corrupted!\n";
  x[0] = '!';
  if (x == z) cout << "write failed!\n";
  cout << "exit: " << x << ' ' << z << '\n';  
 
    z = s;
  if (s != z) cout << "s corrupted!\n";
  s[0] = '!';
  if (s == z) cout << "write failed!\n";
  cout << "exit: " << s << ' ' << z << '\n';  
 
}
 
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    f();
  }
}
*******/