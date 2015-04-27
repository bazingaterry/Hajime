#include "string"
#include "cstdio"
#include "iostream"
using namespace std;

const int INF = 999999;
const int SIZE = 1000;

class campus
{
public:
	campus()
	{
		storage = 0;
	}

	int storage;

	int CamNum(string str)
	{
		for (int i = 0; i < storage; ++i)
		{
			if (str == name[i])
			{
				return i;
			}
		}
		newCam(str);
		return storage-1;
	}
	
private:
	string name[SIZE];

	void newCam(string str)
	{
		name[storage++] = str;
	}
};

int main(int argc, char const *argv[])
{
	
	int c;
	scanf("%d", &c);
	while (c--)
	{
		int dis[SIZE][SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			for (int j = 0; j < SIZE; ++j)
			{
				if (i != j)
					dis[i][j] = INF;
				else
					dis[i][j] = 0;
			}
		}

        campus cam;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			string str1, str2;
			int dist;
            cin >> str1 >> str2 >> dist;
            dis[cam.CamNum(str1)][cam.CamNum(str2)] = dist;
            dis[cam.CamNum(str2)][cam.CamNum(str1)] = dist;
		}

        for (int k = 0; k < cam.storage; ++k)
        {
            for (int i = 0; i < cam.storage; ++i)
            {
                for (int j = 0; j < cam.storage; ++j)
                {
                    if (dis[i][j] > dis[i][k] + dis[k][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        string str1, str2;
        cin >> str1 >> str2;
     	if (dis[cam.CamNum(str1)][cam.CamNum(str2)] == INF)
	    {
	    	cout << -1 << endl;
	    }
	    else
	    {
	    	cout << dis[cam.CamNum(str1)][cam.CamNum(str2)] << endl;
	    }
	}
	return 0;
}