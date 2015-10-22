#include <iostream>
using namespace std;

bool rn(int y)
{
	if ((y%4==0&&y%100!=0)||y%400==0)
		return 1;
	else 
		return 0;
}


int getNum(int y1,int m1,int d1,int y2,int m2,int d2)
{
	if (rn(y1)&&m1==2&&d1==29)
	{
		int year=0;
		for (int i=y1;i<=y2;i++)
			{
				if (rn(i)) year++;
			}
		if (rn(y2)&&(m2<2||m2==2&&d2<29))
			year--;
		return year;
	}
	else
	{
		int year=y2-y1;
		if (m2>m1||(m2==m1&&d2>=d1)) year++;
		return year;
	}
}



int main(int argc, char const *argv[])
{
	int y1,m1,d1,y2,m2,d2;
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
	cout << getNum(y1,m1,d1,y2,m2,d2);
	return 0;
}