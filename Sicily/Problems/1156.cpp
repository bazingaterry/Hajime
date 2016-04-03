#include "iostream"
#include "set"
using namespace std;

const int SIZE = 1010;

struct Node
{
    Node* l_ptr;
    Node* r_ptr;
    char c;
    Node()
    {
    	this->l_ptr = NULL;
    	this->r_ptr = NULL;
    }
};

struct Form
{
	int index, l_index, r_index;
};

void preorderTraversal(const Node* _root)
{
    if (_root == NULL)
        return;
    else
    {
        cout << _root->c;
        preorderTraversal(_root->l_ptr);
        preorderTraversal(_root->r_ptr);
    }
}

int main(int argc, char const *argv[])
{
	Node* array[SIZE];
	array[0] = NULL;
	for (int i = 1; i <= SIZE; ++i)
	{
		array[i] = new Node;
	}
	int n;
	while(cin >> n)
	{
		Form* form_ptr = new Form[n];
		for (int i = 0; i < n; ++i)
		{
			int index, l_index, r_index;
			char c;
			cin >> index >> c >> l_index >> r_index;
			array[index]->c = c;
			array[index]->l_ptr = array[l_index];
			array[index]->r_ptr = array[r_index];
			form_ptr[i].index = index;
			form_ptr[i].l_index = l_index;
			form_ptr[i].r_index = r_index;
		}
		set<int> s;
		for (int i = 0; i < n; ++i)
			s.insert(form_ptr[i].index);
		for (int i = 0; i < n; ++i)
		{
			s.erase(form_ptr[i].l_index);
			s.erase(form_ptr[i].r_index);
		}
		delete form_ptr;
		Node* root = array[*s.begin()];
		preorderTraversal(root);
		cout << endl;
	}
	return 0;
}