#include "iostream"
#include "vector"
#include "queue"
using namespace std;

typedef int T;

struct treeNode {
  T data;
  struct treeNode *left, *right;
 
  treeNode(T d, treeNode *l=NULL, treeNode *r=NULL):data(d),left(l),right(r){};
};

int width(treeNode* root)
{
	int maxWidth = 0;
	queue<treeNode*> pre;
	queue<treeNode*> next;
	if (root != NULL) next.push(root);
	while(!next.empty())
	{
		maxWidth = max(maxWidth, (int)next.size());
		pre = next;
		while (!next.empty()) next.pop();
		while (!pre.empty())
		{
			if (pre.front()->left != NULL)
				next.push(pre.front()->left);
			if  (pre.front()->right != NULL)
				next.push(pre.front()->right);
			pre.pop();
		}
	}
	return maxWidth;
}