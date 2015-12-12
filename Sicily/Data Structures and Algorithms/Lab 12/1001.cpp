#include <cstdlib>
#include <algorithm>
#include <iostream>

struct Node
{
    Node* lc;
    Node* rc;
    Node()
    {
        lc = NULL;
        rc = NULL;
    }
};

int getSize(const Node* root)
{
    if (root == NULL)
        return 0;
    else
        return getSize(root->lc) + getSize(root->rc) + 1;
}

int getHeight(const Node* root)
{
    if (root == NULL)
        return 0;
    else
        return std::max(getHeight(root->lc), getHeight(root->rc)) + 1;
}

void query(const Node* root, int& size, int& height)
{
    size = getSize(root);
    height = getHeight(root);
}

int main(int argc, char const *argv[])
{
    Node* root = new Node;
    root->lc = new Node;
    root->rc = new Node;
    root->rc->lc = new Node;
    std::cout << getSize(root) << ' ' << getHeight(root) << std::endl;
    return 0;
}