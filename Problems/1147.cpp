#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int max=0;
	int sum=0;
	string welguy;
	
	int n;
	cin >> n;
	
	while (n--)
	{
	
		string name,isOfficer,isWest;
		int exam,consult,paper;
		cin >> name >> exam >> consult >> isOfficer >> isWest >> paper;
		
		int money=(exam>80)*(paper>=1)*8000+(exam>85)*(consult>80)*4000+(exam>90)*2000+(exam>85)*(isWest=="Y")*1000+(consult>80)*(isOfficer=="Y")*850;
		
		sum+=money;
		
		if (money>max) 
		{
			max=money;
			welguy=name;
		}
	}
	
	cout << welguy << endl << max << endl << sum <<endl;
	
	return 0;
}
