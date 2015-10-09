#include "iostream"
#include "string"
using namespace std;

string numtostr (int num)//
{
	string result="00";
	result[1] = num%10+48;
	num = num/10;
	result[0] = num+48;
	return result;
}


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int result=1;

		string str;
		cin >> str;
		if ((str[str.size()-1]-48)%2==0)
		{
			while((str[str.size()-1]-48)%2==0)
			{
				string newstr="";

				if(str.size()&1)
					str="0"+str;

				int rem=0;
				for (int i = 0; i < str.size(); i+=2)
				{
					int num = (str[i]-48)*10 + (str[i+1]-48) + rem;
					rem = (num%2)*100;
					newstr = newstr + numtostr(num/2);
				}
				result++;
				str = newstr;
			}
		}
		cout << "Case " << i << ": " << result << "\n";
		if (i!=t)
			cout << endl;
	}
	return 0;
}
