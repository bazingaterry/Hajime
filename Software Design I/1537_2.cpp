#include<iostream>
#include<cstring>
#include<string>

using namespace std;
bool choosen[8];
string original;

void permutation(string newstr)
{
    if(newstr.size()==original.size()) //all characters are choosen
        cout << newstr << endl;
    else
    {
        for(int i=0;i<original.size();i++)
        {
            if(choosen[i] == false)
            {
                choosen[i] = true; //in the next recursion, the character can not be chosen
                permutation(newstr + original[i]);
                choosen[i] = false; //reset the character's situation in the next loop
            }
        }
    }
}

int main()
{
    cin >> original;
    permutation(""); //start with a empty string
    return 0;   
}

