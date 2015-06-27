#include "string"
#include "map"
#include "iostream"
using namespace std;

class student
{
private:
    map<int,string> stu;
public:
    void reg(int,string);
    bool graduate(int,string);
    string findName(int);
};

void student::reg(int id, string name)
{
	stu[id] = name;
}

bool student::graduate(int id, string name)
{
	map<int, string>::iterator it = stu.find(id);
	if (it != stu.end() && it->second == name)
	{
		stu.erase(it);
		return true;
	}
	else
	{
		return false;
	}
}

string student::findName(int id)
{
	return stu[id];
}