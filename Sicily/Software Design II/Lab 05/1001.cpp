#include "iostream"
using namespace std;

class Student
{
public:
	int id;
	int grade;
};


int main(int argc, char const *argv[])
{
	Student* MyStudent = new Student[5];

	for (int i = 0; i < 5; ++i)
	{
		cin >> MyStudent[i].id >> MyStudent[i].grade;
	}

	for (int i = 0; i < 5; i += 2)
	{
		cout << MyStudent[i].id << " " << MyStudent[i].grade << endl;
	}
	return 0;
}