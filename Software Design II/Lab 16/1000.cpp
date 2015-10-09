#include "algorithm"
#include "vector"
#include "string"
#include "iostream"
using namespace std;

class Student
{
public:
	string name;
	int score;
	bool operator< (const Student stu) const;
};

bool Student::operator< (const Student stu) const
{
	return this->score < stu.score;
}


int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	std::vector<Student> studentList(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> studentList[i].name >> studentList[i].score;
	}
	sort(studentList.begin(), studentList.end());
	while(M--)
	{
		int i;
		cin >> i;
		cout << studentList[i - 1].name << " " << studentList[i - 1].score << endl;
	}
	return 0;
}