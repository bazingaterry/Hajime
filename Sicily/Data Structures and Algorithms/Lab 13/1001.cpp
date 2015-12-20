#include "queue"
using namespace std;

template <typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T &x))
{
    if (root == NULL)
        return;
    else
    {
        queue<BinaryNode<T>*> q;
        q.push(root);
        while(!q.empty())
        {
            visit(q.front()->elem);
            if (q.front()->left != NULL )
                q.push(q.front()->left);
            if  (q.front()->right != NULL )
                q.push(q.front()->right);
            q.pop();
        }
    }
}