#include "iostream"
using namespace std;

class Time
{
	private:
		int second;
		int minute;
		int hour;
		
	public:
	    Time()
	    {
	    	second = 0;
	    }
	    
	    Time(int totalSeconds)
	    {
	    	second = totalSeconds;
	    	
	    	hour = second / 3600;
	    	second = second % 3600;
	    	
	    	minute = second / 60;
	    	second = second % 60;
	    }
	    
	    int getHour()
	    {
	    	return hour;
	    }
	    
	    int getMinute()
	    {
	    	return minute;
	    }
	    
	    int getSecond()
	    {
	    	return second;
	    }
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Time t(n);
	cout << t.getHour() << " " << t.getMinute() << " " << t.getSecond() << endl;

	return 0;
}
