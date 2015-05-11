#include <iostream>
#include <vector>

using namespace std;
const int maxObserver = 10;

class Observer
{
public:
	virtual ~Observer() {}
	virtual void notify() = 0;
};

class ObserverA : public Observer
{
public:
	void notify()
	{
		cout << "ObserverA is notified that Subject changed.\n";
	}
};

class ObserverB : public Observer
{
public:

	void notify()
	{
		cout << "ObserverB is notified that Subject changed.\n";
	}
};

class Subject
{
public:
	Subject();
	
	//add observer to observerList
	void addObserver(Observer* observer);
	
	//remove observer from observerList
	void removeObserver(Observer* observer);
	
	//send subject changed message
	void change();
	
private:
	Observer* observerList[maxObserver];
	int numObserver;
};

Subject::Subject()
{
	this->numObserver = 0;
}

void Subject::addObserver(Observer* observer)
{
	observerList[numObserver++] = observer;
}

void Subject::removeObserver(Observer* observer)
{
	//	hehe
}

void Subject::change()
{
	for (int i = 0; i < numObserver; ++i)
	{
		observerList[i]->notify();
	}
}

int main(int argc, char *argv[])
{
	ObserverA a;
	ObserverB b;
	
	Subject subject;
	
	subject.addObserver(&a);
	subject.addObserver(&b);
	
	subject.change();

	return 0;
}
