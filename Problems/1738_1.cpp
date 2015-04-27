#include "iostream"
using namespace std;

class CharNode
{
private:
	char ch[101] = "";
    int next[101];
    int free = 0;

public:
    void Read (void)
    {
		while (true)
		{
			int tmpChar = getchar();
	    	if (tmpChar == '\n')
	    	{
	    		ch[free] = '\0';
	    		next[free] = ++free;
	    		break;
	    	}
	    	ch[free] = tmpChar;
	    	next[free] = ++free;
	    }
    }

    void Delete (int location)
    {
    	int step = 1;
    	int now = 0;
    	while (step < location - 1)
    	{
    		now = next[now];
    		step++;
    	}
    	if (ch[next[now]] == '\0')	//	last node
    	{
    		ch[now] = '\0';
    	}
    	else
    	{
    		next[now] = next[next[now]];
    	}
    }

    void Reverse (void)
    {
    	char stack[102];
    	int node = 0; 
    	int now = 0;
    	while (ch[now] != '\0')
    	{
    		stack[node++] = ch[now];
    		now = next[now];
    	}
    	
    	now = 0;
    	while (node >= 0)
    	{
    		ch[now] = stack[--node];
    		now = next[now];
    	}
    	ch[now] = '\0';
    }

    void Insert (int location, char cha)
    {
    	if(location == 1)
    	{
    		char tmpChar = ch[0];
    		ch[0] = cha;
    		ch[free] = tmpChar;
	    	next[free] = next[0];
	    	next[0] = free++;
    	}
    	else
    	{
	    	int step = 1;
	    	int now = 0;
	    	while (step < location - 1)
	    	{
	    		now = next[now];
	    		step++;
	    	}
	    	ch[free] = cha;
	    	next[free] = next[now];
	    	next[now] = free++;
    	}
    }

    void Print (void)
    {
    	int now = 0;
    	while (ch[now] != '\0')
    	{
    		printf("%c", ch[now]);
    		now = next[now];
    	}
    	printf("\n");
    }
};


int main(int argc, char const *argv[])
{
    CharNode cn;
    cn.Read();
    int k;
    cin >> k;
    while (k--)
    {
    	char operation[10];
    	cin >> operation;

    	if (operation[0] == 'D')
    	{
    		int t;
    		cin >> t;
    		cn.Delete(t);
    	}
    	else if (operation[0] == 'R')
    		cn.Reverse();
    	else if (operation[0] == 'I')
    	{
    		int t;
    		char ch;
    		cin >> t >> ch;
    		cn.Insert(t, ch);
    	}
    }
    cn.Print();

    return 0;
}