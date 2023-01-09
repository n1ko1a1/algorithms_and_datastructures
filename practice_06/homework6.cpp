#include <iostream>
#include <limits>

class Node
{
public:
    Node* left;
    Node* right;
    int data; 

    Node(int v)
    {
        left = NULL;
        right = NULL;
        data = v;
    }
};

void PrintTree(
    Node* root, 
    std::string prefix = "", 
    bool isLeft = false
)
{
    if (root)
    {
        std::cout << prefix << (isLeft ? "├──>" : "└──>") << root->data << std::endl;

        PrintTree(root->left, prefix + (isLeft ? "|   " : "    "), true);
        PrintTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
    }
}

bool IsBinaryTree(Node* root, int min, int max)
{   
	if (root == NULL)
		return true;
	if (root -> data <= min)
		return false;
    if (root -> data >= max)
		return false;
	return IsBinaryTree(root -> right, root -> data, max) && 
            IsBinaryTree(root -> left, min, root -> data);	
}

int main(int argc, char ** argcv)
{
    int min = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::max();
    
    auto root = new Node(12);
    
    root->left = new Node(10);
    root->right = new Node(15);

    root->left->left = new Node(4);
    root->left->right = new Node(11);

    root->right->left = new Node(13);
    root->right->right = new Node(16);

    PrintTree(root);
    std::cout << (IsBinaryTree(root, min, max) ? "true" : "false") << std::endl;

    root = new Node(12);
    
    root->left = new Node(10);
    root->right = new Node(15);

    root->left->left = new Node(4);
    root->left->right = new Node(15);

    root->right->left = new Node(13);
    root->right->right = new Node(16);

    std::cout << std::endl;
    PrintTree(root);
    std::cout << (IsBinaryTree(root, min, max) ? "true" : "false") << std::endl;

    return 0;
}