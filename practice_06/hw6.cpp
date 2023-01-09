#include <iostream>
#include <limits>

class Node
{
public:
    Node* left;
    Node* right;
    int value;

    Node(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};


void PrintBST(
    Node* root,
    std::string prfx = "",
    bool is_left = false,
    bool h_one_value = false
)
{
    if (root || h_one_value)
    {
        std::cout << prfx;
        std::cout << (is_left ? "├---> " : "└---> ");
        
        if (!root && h_one_value)
            std::cout << "NULL" << std::endl;
        else
        {
            std::cout << root->value << std::endl;    
            
            PrintBST(
                root->left, 
                prfx + (is_left ? "│   " : "    "), 
                true, 
                (root->left || root->right)
            );
            PrintBST(
                root->right, 
                prfx + (is_left ? "│   " : "    "), 
                false, 
                (root->left || root->right)
            );
        }
    }
}

bool IsBST(
    Node* root, 
    int min = std::numeric_limits<int>::min(), 
    int max = std::numeric_limits<int>::max()
)
{
    if (root == NULL)
		return true;
	if (root->value <= min || root->value >= max)
		return false;
	return IsBST(root->right, root->value, max) 
            && IsBST(root->left, min, root->value);	
}

int main()
{
    Node* root;

    root = new Node(8);
    
    root->left = new Node(3);
    root->right = new Node(10);
    
    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    PrintBST(root);
    std::cout << (IsBST(root) ? "true" : "false") << std::endl;

    root->right->right->left = new Node(7);

    std::cout << std::endl;
    for (int i = 0; i < 25; i++)
        std::cout << "-";
    std::cout << std::endl;

    PrintBST(root);
    std::cout << (IsBST(root) ? "true" : "false") << std::endl;

    return 0;
}