#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n != 0)
    {
        int array[101][3] = {{}, {}, {}};
        
        for (int i = 0; i < n; ++i)
        {
            cin >> array[i][0] >> array[i][1] >> array[i][2];
        }

        
        int value = 0;
        bool jug = 1;
        for (int i = 1000; i <= 9999; ++i) // enumerate
        {
            
            int time = 0;
            int base[10] = {};
            int tmp = i;
            while (tmp != 0)
            {
                base[tmp % 10]++;
                tmp = tmp / 10;
            }

            for (int j = 0; j < n; j++) // test case in array
            {
                int test[10] = {};
                int tmp = array[j][0];
                while (tmp != 0)
                {
                    test[tmp % 10]++;
                    tmp = tmp / 10;
                }
                
                int b = 0;
                for (int i = 0; i <= 9; ++i) // b
                {
                    b += min(base[i], test[i]);
                }

                int c = 0;
                int x = i;
                int y = array[j][0];
                for (int i = 1; i <= 4; ++i) // c
                {
                    if (x % 10 == y % 10)
                    {
                        c++;
                    }
                    x = x / 10;
                    y = y / 10;
                }

                if (b == array[j][1] && c == array[j][2])
                {
                    time++;
                }
                else
                {
                	break;
                }
            }

            if (time == n)
            {
                if (value == 0)
                    value = i;
                else
                {
                    jug = 0;
                    break;
                }
            }   
        }
        
        if (jug)
            cout << value << endl;
        else
            cout <<"Not sure\n";
    }

    return 0;
}                                 
