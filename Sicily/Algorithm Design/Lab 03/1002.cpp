#include "iostream"
#include "queue"
#include "vector"
using namespace std;

class Node
{
public:
    Node(int weight)
    {
        l_c = r_c = NULL;
        this->weight = weight;
    }
    Node(const Node* const l_c, const Node* const r_c) : l_c(l_c), r_c(r_c)
    {
        weight = l_c->weight + r_c->weight;
    }
    const Node* l_c;
    const Node* r_c;
    int weight;
};

struct cmp
{
    bool operator()(const Node* const x, const Node* const y)
    {
        return x->weight > y->weight;
    }
};

int sum(const Node* const top, int level)
{
    if (top == NULL)
        return 0;
    else
    {
        int result = 0;
        if (top->l_c != NULL)
            result += sum(top->l_c, level + 1);
        if (top->r_c != NULL)
            result += sum(top->r_c, level + 1);
        if (top->l_c == NULL && top->r_c == NULL)
            result += top->weight * level;
        return result;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for (int i = 0; i < n; ++i)
    {
        char foo;
        int weight;
        cin >> foo >> weight;
        Node* newNode = new Node(weight);
        pq.push(newNode);
    }
    Node* top = NULL;
    while(!pq.empty())
    {
        Node* first = pq.top();
        pq.pop();
        if (pq.empty())
            top = first;
        else
        {
            Node* second = pq.top();
            pq.pop();
            Node* newNode = new Node(first, second);
            pq.push(newNode);
        }
    }
    cout << sum(top, 0) << endl;
    return 0;
}