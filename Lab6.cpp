#include <iostream>
#include <stack>
using namespace std;
 
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
bool isLeaf(Node* node) {
    return node->left == nullptr && node->right == nullptr;
}
 
Node* getNextLeafNode(stack<Node*> &s)
{
    Node* curr = s.top();
    s.pop();
 
    while (curr != nullptr && !isLeaf(curr))
    {

        if (curr->right != nullptr) {
            s.push(curr->right);
        }
 
        if (curr->left != nullptr) {
            s.push(curr->left);
        }
 
        curr = s.top();
        s.pop();
    }
 
    return curr;
}
 
bool isLeafTraversalSame(Node* x, Node* y)
{
    // создаем два пустых stack
    stack<Node*> first;
    stack<Node*> second;
 
    first.push(x);
    second.push(y);
 
    while (!first.empty() && !second.empty())
    {
        Node* xLeaf = getNextLeafNode(first);
 
        Node* yLeaf = getNextLeafNode(second);
 
        if (xLeaf == nullptr && yLeaf == nullptr) {
            return true;
        }
 
        // вернуть false, если их данные не совпадают
        if (xLeaf == nullptr || yLeaf == nullptr || xLeaf->data != yLeaf->data) {
            return false;
        }
    }
 
    return first.empty() && second.empty();
}
 
int main()
{
    Node* x = new Node(1);
    x->left = new Node(2);
    x->right = new Node(3);
    x->left->left = new Node(4);
    x->left->right = new Node(5);
    x->right->left = new Node(6);
 
    Node* y = new Node(1);
    y->left = new Node(2);
    y->right = new Node(3);
    y->left->right = new Node(4);
    y->right->left = new Node(5);
    y->right->right = new Node(6);
 
    bool isSame = isLeafTraversalSame(x, y);
    if (isSame) {
        cout << "The tree traversals are the same" << endl;
    }
    else {
        cout << "The tree traversals are different" << endl;
    }
 
    return 0;
}
