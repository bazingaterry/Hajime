#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string keyword;
	while (cin >> keyword && keyword != "THEEND" )
	{
		string ciphertext;
		int  k=0;//the k+1 letter in ciphertext
		cin >> ciphertext;
		
		int col = keyword.size();
		int row = ciphertext.size()/col;
		
		char mat[100][10];
				
		for (int i='A';i<='Z';i++)
		{
			for (int j=0;j<col;j++)//the j+1 letter in keyword 
			{
				if (keyword[j]==i)
				{
					for (int t=0;t<row;t++)//put ciphertext into matrix
					{
						mat[t][j]=ciphertext[k++];
					}
				}
			}
		}
		
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				cout << mat[i][j];
			}
		}
		cout << endl;
	}
	
	
	return 0;
}
