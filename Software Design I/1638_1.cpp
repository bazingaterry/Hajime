#include <iostream>
using  namespace std;

class Date
{
	public:

	    Date(int year = 2013, int month = 1, int day = 1)
	    {
	    	this -> year = year;
	    	this -> month = month;
	    	this -> day = day;
	    }

	    bool setYear(int y)
	    {
	    	if ( isVaild(y, month, day) )
	    	{
	    		year = y;
	    		return true;
	    	}
	    	else
	    		return false;
	    }

	    bool setMonth(int m)
	    {
	    	if ( isVaild(year, m, day) )
	    	{
	    		month = m;
	    		return true;
	    	}
	    	else
	    		return false;
	    }

	    bool setDay(int d)
	    {
	    	if ( isVaild(year, month, d) )
	    	{
	    		day = d;
	    		return true;
	    	}
	    	else
	    		return false;
	    }

	    void print()
	    {
	    	printf( "%d/", year);
	    	
	    	if ( 1 <= month && month <= 9)
	    		printf("0%d/", month);
	    	else
	    		printf("%d/", month);

			if ( 1 <= day && day <= 9)
	    		printf("0%d\n", day);
	    	else
	    		printf("%d\n", day);
	    	
	    }

	private:

	    int year;
	    int month;
	    int day;

	    bool rn(int y)
		{
			if (( y%4 == 0 && y%100 != 0 ) || y % 400 == 0 )
				return 1;
			else
				return 0;
		}

		bool isVaild(int y, int m, int d)
		{
			if (y < 1970)
	    		return false;
	    	else
	    	{
	    		if ( m == 2 )
	    		{
	    			if ( rn(y) && 1 <= d && d <= 29)
	    				return true;
	    			else if (1 <= d && d <= 28 )
	    				return true;
	    			else
	    				return false;
	    		}
	    		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	    		{
	    			if ( 1 <= d && d <= 31 )
	    				return true;
	    			else
	    				return false;
	    		}
	    		else if (m == 4 || m == 6 || m == 9 || m == 11)
	    		{
	    			if ( 1 <= d && d <= 30 )
	    				return true;
	    			else
	    				return false;
	    		}
	    		else
	    			return false;

	    	}
		}
};



int main()
{

    Date d(2013, 2, 28);

    d.print();

    d.setDay(27);

    d.print();

    if(d.setDay(29) == false){

    cout << "Invalid!\n";

     }

     d.setMonth(12);

     d.setDay(1);

     d.print();

     if(d.setMonth(2) == false){

     cout << "Invalid!\n";

     }

     d.setYear(1000);

     d.print();

    return 0;

}



