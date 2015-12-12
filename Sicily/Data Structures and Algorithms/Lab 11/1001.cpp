#include "cstdio"
#include "string"
#include "iostream"
#include "cmath"
using namespace std;

//  this is part of my unfinished project HashMap
//  more information please visit the main page of HashMap

class HashMap
{
protected:
    const int capacity;
    int size;
    unsigned int (*hash) (const std::string&);
    
public:
    HashMap(const int capacity, unsigned int (*) (const std::string&));
    virtual ~HashMap() = 0;
    virtual bool insert(const std::string& key, const std::string& value) = 0;
    virtual bool erase(const std::string& key) = 0;
    virtual bool find(const std::string& key, std::string& value) = 0;
};

HashMap::HashMap(const int capacity, unsigned int (*hash) (const std::string&)) : capacity(capacity)
{
    size = 0;
    this->hash = hash;
}

HashMap::~HashMap()
{
}

struct StringPair
{
    std::string first, second;
};

class HashMap_OA : public HashMap
{
protected:
    const int increment;
    bool search(const std::string& key, int& _index) const;
    bool findAddress(const std::string& key, int& _index) const;
    StringPair* map;
    bool* isInvalid;
    
public:
    HashMap_OA(const int capacity, unsigned int (*) (const std::string&), const int increment);
    ~HashMap_OA();
    bool insert(const std::string& key, const std::string& value);
    bool erase(const std::string& key);
    bool find(const std::string& key, std::string& value);
};

bool HashMap_OA::search(const std::string& key, int& _index) const
{
    int count = 0;
    int originalIndex = hash(key) % capacity;
    int add = 0;
    int index;
    while (count++ <= capacity)
    {
        index = (originalIndex + (int)pow(add++, increment)) % capacity;
        if (this->map[index].first == key)
        {
            _index = index;
            return true;
        }
        else if (this->map[index].first == "" && isInvalid[index] == false)
            return false;

    }
    return false;
}

bool HashMap_OA::findAddress(const std::string& key, int& _index) const
{
    if (size >= capacity)
    {
        return false;
    }    
    else
    {
        int originalIndex = hash(key) % capacity;
        int add = 0;
        int index = originalIndex;
        while (this->map[index].first != "")
        {
            index = (originalIndex + (int)pow(++add, increment)) % capacity;
        }
        _index = index;
        return true;
    }
}

HashMap_OA::HashMap_OA(const int capacity, unsigned int (*hash) (const std::string&), const int increment)
             : HashMap(capacity, hash), increment(increment)
{
    map = new StringPair[capacity];
    isInvalid = new bool[capacity];
    std::memset(isInvalid, false, sizeof(bool) * capacity);
}

HashMap_OA::~HashMap_OA()
{
    delete[] map;
}

bool HashMap_OA::insert(const std::string& key, const std::string& value)
{
    int index;
    if (findAddress(key, index))
    {
        map[index].first = key;
        map[index].second = value;
        isInvalid[index] = false;
        size++;
        return true;
    }    
    else
        return false;
}

bool HashMap_OA::erase(const std::string& key)
{
    int index;
    if (search(key, index))
    {
        map[index].first = "";
        isInvalid[index] = true;
        size--;
        return true;
    }    
    else
        return false;
}

bool HashMap_OA::find(const std::string& key, std::string& value)
{
    int index;
    if (search(key, index))
    {
        value = map[index].second;
        return true;
    }    
    else
        return false;
}

unsigned int RSHash(const std::string& s) 
{ 
    unsigned int b = 378551 ; 
    unsigned int a = 63689 ; 
    unsigned int hash = 0 ;     
    for (int i = 0; i < s.size(); ++i)
    { 
        hash = hash * a + s[i]; 
        a *= b ; 
    }     
    return hash; 
}

void query(string A[], int n, string B[], int m)
{
	HashMap_OA hm(5000000, RSHash, 2);
    for (int i = 0; i < n; ++i)
    {
        hm.insert(A[i], "");
    }
    string s;
    for (int i = 0; i < m; ++i)
    {
        if (hm.find(B[i], s)) cout << B[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    string s1[4], s2[2];
    s1[0] = "A";
    s1[1] = "B";
    s1[2] = "C";
    s1[3] = "D";
    s2[0] = "A";
    s2[1] = "E";
    query(s1, 4, s2, 2);
    return 0;
}