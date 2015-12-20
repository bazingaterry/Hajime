#include <iostream>
using namespace std;

struct Node
{
    Node* leftChild;
    Node* rightChild;
    int data;
    Node()
    {
        leftChild = NULL;
        rightChild = NULL;
    }
};

class BinarySearchTree
{
private:
    Node* root;
    void insert(Node*& _root, const int data)
    {
        if (_root == NULL)
        {
            _root = new Node;
            _root->data = data;
        }
        else if (data < _root->data)
            insert(_root->leftChild, data);
        else if (data > _root->data)
            insert(_root->rightChild, data);
    }
    void inorderTraversal(const Node* _root)
    {
        if (_root == NULL)
            return;
        else
        {
            inorderTraversal(_root->leftChild);
            cout << _root->data << ' ';
            inorderTraversal(_root->rightChild);
        }
    }
    void preorderTraversal(const Node* _root)
    {
        if (_root == NULL)
            return;
        else
        {
            cout << _root->data << ' ';
            preorderTraversal(_root->leftChild);
            preorderTraversal(_root->rightChild);
        }
    }
    void remove(Node*& _root)
    {
        if (_root->leftChild != NULL)
        {
            remove(_root->leftChild);
            delete _root->leftChild;
        }
        if (_root->rightChild != NULL)
        {
            remove(_root->rightChild);
            delete _root->rightChild;
        }
        delete _root;
        _root = NULL;
    }
public:
    BinarySearchTree()
    {
        root = NULL;
    }
    void insert(const int data)
    {
        insert(root, data);
    }
    void traversal()
    {
        inorderTraversal(root);
        cout << endl;
        preorderTraversal(root);
        cout << endl;
    }
    ~BinarySearchTree()
    {
        remove(root);
    }
};

int main(int argc, char const *argv[])
{
    int m;
    while (cin >> m && m != 0)
    {
        BinarySearchTree bst;
        while (m--)
        {
            int data;
            cin >> data;
            bst.insert(data);
        }
        bst.traversal();
    }
    return 0;
}