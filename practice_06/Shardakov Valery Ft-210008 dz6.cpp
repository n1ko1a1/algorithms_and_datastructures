#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isBinarySearchTree(Node* root, int minValue, int maxValue) {
    if (root == nullptr) {
        return true;
    }
    if (root->data < minValue || root->data > maxValue) {
        return false;
    }
    return isBinarySearchTree(root->left, minValue, root->data - 1) && isBinarySearchTree(root->right, root->data + 1, maxValue);
}

int main() {
    Node n1, n2, n3, n4, n5;
    n1.data = 10;
    n2.data = 5;
    n3.data = 15;
    n4.data = 6;
    n5.data = 20;
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;
    n2.left = n2.right = n4.left = n4.right = n5.left = n5.right = nullptr;
    if (isBinarySearchTree(&n1, INT_MIN, INT_MAX)) {
        std::cout << "The tree is the correct search tree" << std::endl;
    }
    else {
        std::cout << "The tree is not a proper search tree" << std::endl;
    }
    return 0;
}
