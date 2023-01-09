#include <iostream>
#include <limits.h>

class Node
{
    public:
    Node* left = NULL;
    Node* right = NULL;
    int val;
};

void PrintBST(Node* node, bool is_left = false, std::string pref = "")
{
    if (node != NULL)
    {
        std::cout << pref;
        std::cout << (is_left ? "|---> " : "L---> ");
        std::cout << node->val << std::endl;
        PrintBST(node->left, true, pref + (is_left ? "|    " : "    "));
        PrintBST(node->right, false, pref + (is_left ? "|    " : "    "));
    }
}

int IsBST(Node* node, int min = INT_MIN, int max = INT_MAX)
{
    if (node == NULL)
		return true;
	else if (node->val <= min || node->val >= max)
		return false;
    else
	    return IsBST(node->right, node->val, max) && IsBST(node->left, min, node->val);	
}

int main()
{
    auto r = new Node();
    r->val = 5;

    r->left = new Node();
    r->left->val = 4;
    r->left->left = new Node();
    r->left->left->val = 2;
    r->left->left->right = new Node();
    r->left->left->right->val = 3; 

    r->right = new Node();
    r->right->val = 8;
    r->right->left = new Node();
    r->right->left->val = 6;
    r->right->right = new Node();
    r->right->right->val = 9;
    r->right->left->right = new Node();
    r->right->left->right->val = 7;

    PrintBST(r);
    std::cout << (IsBST(r) ? "Binary tree search is correct." 
                    : "Binary tree search is incorrect.") << std::endl;

    r->right->left->right->val = 8;
    std::cout << std::endl;
    PrintBST(r);
    std::cout << (IsBST(r) ? "Binary tree search is correct." 
                    : "Binary tree search is incorrect.") << std::endl;
}