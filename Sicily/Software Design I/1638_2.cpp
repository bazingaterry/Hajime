#include "iostream"
using namespace std;

class Date
{
	public:

		Date(int year, int month, int day)
		{
			this -> year = year;
			this -> month = month;
			this -> day = day;
		}

		int GetWeekday()
		{
			if ( isVaild( year, month, day) )
			{
				if ( month <= 2)
				{
					year--;
					month += 12;
				}

				int c = int(year / 100);
				int y = year - 100 * c;
				int w = int( c/4 )- 2 * c + y + int( y/4 )+(26 * ( month+1 )/ 10)+ day - 1;
				w= ( w % 7 + 7 ) % 7;
				if ( w == 0 )
					return 7;
				else
					return w;

			}
			else
				return -1;
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
};

int main(int argc, char const *argv[])
{
	int y,m,d;
	while (cin >> y>>m>>d)
	{
		Date da(y, m, d);
		cout << da.GetWeekday() <<endl;
	}
	return 0;
}



