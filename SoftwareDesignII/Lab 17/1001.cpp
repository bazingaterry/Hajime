#include "iostream"
using namespace std;

class Date
{
public:
    Date(int y, int m, int d) 
    {
        year=y; month=m; day=d;
    }
    int getYear() {return year;}
    int getMonth() {return month;}
    int getDay() {return day;}
private:
    int year, month, day;
};
 
class Person
{
public:
    Person(int id, int year, int month, int day)
    {
        this->id = id;
        birthDate = new Date(year, month, day);
    }
    Person(Person& newPerson)
    {
        this->id = newPerson.getId();
        birthDate = new Date(newPerson.getBirthDate()->getYear(),
                             newPerson.getBirthDate()->getMonth(),
                             newPerson.getBirthDate()->getDay());
    }
    ~Person() { delete birthDate; }
    int getId() { return id; }
    Date* getBirthDate() { return birthDate; }
    void operator=(Person& newPerson)
    {
        this->id = newPerson.getId();
        delete this->birthDate;
        this->birthDate = new Date(newPerson.getBirthDate()->getYear(),
                                   newPerson.getBirthDate()->getMonth(),
                                   newPerson.getBirthDate()->getDay());
    }
private:
    int id;
    Date* birthDate;
};

int main(int argc, char const *argv[])
{
    Person a(1, 2, 3, 4);
    Person b = a;
    return 0;
}

