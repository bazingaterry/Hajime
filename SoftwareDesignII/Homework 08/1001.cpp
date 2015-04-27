class String
{
public:
    String();
    String(const char*);
    String(const String&);

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
    char *str;
};