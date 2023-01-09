#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

bool test(Node* root, int min, int max) 
{
    if (root == nullptr) 
    {
        return true;
    }
    if (root->data < min || root->data > max) 
    {
        return false;
    }
    return test(root->left, min, root->data - 1 ) && test(root->right, root->data + 1, max); 
}

int main() 
{
    Node cell1, cell2, cell3, cell4, cell5, cell6, cell7; 
    cell1.data = 12, cell2.data = 4, cell3.data = 15, cell4.data = 14, cell5.data = 20, cell6.data = 6, cell7.data = 0;
    cell1.left = &cell2;
    cell1.right = &cell3;
    cell3.left = &cell4;
    cell3.right = &cell5;
    cell2.left = &cell7;
    cell2.right = &cell6;
    cell7.right = cell7.left = cell6.right = cell6.left = cell5.left = cell5.right = cell4.left = cell4.right = nullptr; 
    if (test(&cell1, INT_MIN, INT_MAX)) 
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    return 0;
}
