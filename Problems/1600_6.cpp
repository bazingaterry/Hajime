#include "iostream"
#include "cstring"
using namespace std;

int main(int argc, char const *argv[])
{
	string p;
	int n,k;
	while (cin >> n >> k >> p)
	{
		int point = 0;
		while (k--)
		{
			if (point == -1)
				point =0;
			bool hasDeleted = 0;
			for (; point < p.size()-1; ++point)
			{
				if (p[point] > p[point+1])
				{
					p.erase(point,1);
					point--;
					hasDeleted = 1;
					break;
				}
			}
			if (hasDeleted == 0)
			{
				p.erase(p.size()-k-1,k+1);
				break;
			}
			//cout << p << endl;
		}
		
		while(p[0]=='0')
			p.erase(0,1);
		if (p =="")
			p = "0";
		cout << p << endl;
	}

	return 0;
}
