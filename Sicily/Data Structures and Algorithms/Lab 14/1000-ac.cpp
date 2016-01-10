#include<bits/stdc++.h>
using namespace std;
#define max 10
int num;
bool ok;
struct node
{
 bool isword;
 int next[max];
 void init()
 {
    memset(next,0,sizeof(next));
    isword=false;
 }
}tree[100010];
void insert(char a[])
{
 int cou=0;
 int index=0;
 int len=strlen(a);
 for(int i=0;i<len;i++)
 {
    if(tree[index].next[a[i]-'0']==0)
    {
     tree[++num].init();
     tree[index].next[a[i]-'0']=num;
     index=num;
    }
    else
    {
     cou++;
     index=tree[index].next[a[i]-'0'];
     if(tree[index].isword)
     {
        ok=false;
        return;
     }
    }
 }

 tree[index].isword=true;
 if(cou==len)//关键是这个，防止9112,911的情况！！！ 
 ok=false;
}
int main()
{
 char a[14];
 int t,n;
 cin>>t;
 
 while(t--)
 {
    cin>>n;
    tree[0].init();
    ok=true;
    num=0;
    while(n--)
    {
     if(ok)
            {
        scanf("%s",a);
        insert(a);
     }
     else
     scanf("%s",a);
    }
    if(ok)
    printf("YES\n");
    else
    printf("NO\n");
 }
 return 0;
}