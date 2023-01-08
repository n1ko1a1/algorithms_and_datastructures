
#include <iostream>
struct Node
{
    Node* left;
    Node* right;
    int data;
};


bool isBSTUtil(Node* node, int min, int max)
{
    if (node == nullptr)
    {
        return true;
    }
    if ((node->data < min) || (node->data > max))
    {
        return false;
    }
    if (node->left != nullptr && node->left->data > node->data)
    {
        return false;
    }
        
    if (node->right != nullptr && node->right->data < node->data)
    {
        return false;
    }
}


int main()

{
    setlocale(LC_ALL, "Russian");

         /*           12
                   /     \
                  8        14
                 /\       /   \
               6   7     13     16      */

    int min = 6;
    int max = 16;

    Node a, b, c, d, e, f, g;

    a.data = 12;
    a.left = &b;
    a.right = &c;

    b.data = 8;
    b.left = &d;
    b.right = &e;

    c.data = 14;
    c.left = &f;
    c.right = &g;

    d.data = 6;
    e.data = 7;
    f.data = 13;
    g.data = 16;

    d.left = d.right = e.left = e.right = f.left = f.right = g.right = g.right = nullptr;

    if (isBSTUtil(&a, min, max)) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    return 0;

}
