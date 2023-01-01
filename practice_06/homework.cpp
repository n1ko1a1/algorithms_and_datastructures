#include <iostream>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

bool IsCorrectTree(
    Node* root,
    Node* parent = NULL,
    bool isLeft = false 
)
{   
    if (!root)
        return true;
    
    if (parent)
    {
        if (isLeft && root->data >= parent->data)
            return false;
        
        if (!isLeft && root->data <= parent->data)
            return false;
    }

    return IsCorrectTree(root->left, root, true) && 
            IsCorrectTree(root->right, root, false);
}

void PrintTree(
    Node* root, 
    std::string prefix = "", 
    bool isLeft = false
)
{
    if (root)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << root->data << std::endl;

        PrintTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
        PrintTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
    }
}

void PrintResult(
    bool isCorrectTree, 
    bool isLast = true
)
{
    std::cout   << (isCorrectTree ? 
                    ">>> \033[32mBinary tree is correct.\033[0m\n" : 
                    ">>> \033[31mBinary tree is invalid.\033[0m\n");
    if (!isLast)
    {
        for (int i = 0; i < 15; i++)            
            std::cout << "──";
        std::cout << std::endl;
    }       
}

int main(int argc, char** argcv)
{
    Node* root1 = new Node(30);
    
    root1->left = new Node(20);
    root1->right = new Node(34);
    
    root1->left->left = new Node(12);
    root1->left->right = new Node(24);
    
    root1->right->left = new Node(12);
    root1->right->right = new Node(45);
    
    PrintTree(root1);
    PrintResult(IsCorrectTree(root1), false);

//////////////////////////////////////////////////////

    Node* root2 = new Node(30);
    
    root2->left = new Node(20);
    root2->right = new Node(34);
    
    root2->left->left = new Node(12);
    root2->left->right = new Node(24);
    
    root2->right->left = new Node(34);
    root2->right->right = new Node(45);
    
    PrintTree(root2);
    PrintResult(IsCorrectTree(root2));
}