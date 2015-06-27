#include "string"
using namespace std;

class Animal
{
public:
    Animal(string n): name(n) {}
    virtual string shout() = 0;

private:
    string name;
};

class Dog: public Animal
{
public:
    Dog(string name, string color) : Animal(name)
    {
        this->color = color;
    }

    string shout()
    {
        return "bark";
    }

    string getColor()
    {
        return color;
    }
private:
    string color;
};

class Donkey: public Animal
{
public:
    Donkey(string name, int weight) : Animal(name)
    {
        this->weight = weight;
    }

    string shout()
    {
        return "hee-haw";
    }

    int getWeight()
    {
        return weight;
    }
private:
    int weight;
};