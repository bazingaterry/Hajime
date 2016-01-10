#include "iostream"
#include "cstdlib"
using namespace std;

class Node
{
public:
    int tag;
    Node* next[10];
    Node()
    {
        tag = 0;
        for (int i = 0; i < 10; ++i)
            next[i] = NULL;
    }
};

class Catalogue
{
private:
    Node* root;
    Node* arr;
    int tail;
    bool insert(Node*& _root, const string& phoneNum)
    {
        if (_root == NULL)
            _root = &arr[tail++];
        if (phoneNum.size() == 0)
        {
            if (_root->tag != 0)
                return false;
            else
            {
                _root->tag = 2;
                return true;
            }
        }
        else
        {
            if (_root->tag == 2)
                return false;
            else
            {
                _root->tag = 1;
                return insert(_root->next[phoneNum[0] - '0'], phoneNum.substr(1));
            }
        }
    }
    void remove(Node*& _root)
    {
        for (int i = 0; i < 10; ++i)
        {
            if (_root->next[i] != NULL)
            {
                remove(_root->next[i]);
                delete _root->next[i];
            }
        }
        delete _root;
        _root = NULL;
    }
public:
    Catalogue(int cap)
    {
        cap *= 10;
        root = NULL;
        arr = new Node[cap];
        tail = 0;
    }
    ~Catalogue()
    {
        //remove(root);
        delete[] arr;
    }
    bool insert(const string& phoneNum)
    {
        return insert(root, phoneNum);
    }
};

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Catalogue ca(n);
        string phoneNum;
        int flag = true;
        while (n--)
        {
            cin >> phoneNum;
            if (flag)
                flag = ca.insert(phoneNum);
        }
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}