#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

typedef struct node
{
    node *next[26];
    char word[11];
    node()
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        strcpy(word, "");
    }
}TreeNode;

void Insert(TreeNode *pHead, char word[], char foreign[])
{
    TreeNode *p = pHead;
    int nLen = strlen(foreign);
    for (int i = 0; i < nLen; i++)
    {
        int index = foreign[i] - 'a';
        if (p->next[index] == NULL)
        {
            p->next[index] = new TreeNode;
        }
        p = p->next[index];
    }
    strcpy(p->word, word);
}

void Search(TreeNode *pHead, char foreign[])
{
    TreeNode *p = pHead;
    int nLen = strlen(foreign);
    for (int i = 0; i < nLen; i++)
    {
        int index = foreign[i] - 'a';
        if (p->next[index] == NULL)
        {
            printf("eh\n");
            return;
        }
        p = p->next[index];
    }
    if (strcmp(p->word, "") == 0)
    {
        printf("eh\n");
    }
    else
    {
        printf("%s\n", p->word);
    }
}

void DeleteNode(TreeNode *pHead)
{
    if (pHead != NULL)
    {
        for (int i = 0; i < 26; i++)
        {
            DeleteNode(pHead->next[i]);
        }
    }
    delete pHead;
}

int main()
{
    char temp[25];
    char str1[11], str2[11];
    TreeNode *pHead = new TreeNode;
    gets(temp);
    while(strcmp(temp, ""))
    {
        int i = 0, j = 0;
        while(str1[i] = temp[j])
        {
            if (temp[j] == ' ')
            {
                break;
            }
            i++;
            j++;
        }
        str1[i] = '\0';
        i = 0;
        j++;
        while(str2[i] = temp[j])
        {
            if (temp[j] == '\0')
            {
                break;
            }
            i++;
            j++;
        }
        str2[i] = '\0';
        i = j = 0;
        Insert(pHead, str1, str2);
        gets(temp);
    }
    while(cin>>str2)
    {
        Search(pHead, str2);
    }
    DeleteNode(pHead);
    return 0;
}