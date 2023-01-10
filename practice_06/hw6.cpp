#include <iostream>

struct Node {
    Node* left;
    Node* right;
    int data;
};

bool IsBinTree(Node* node, int minValue, int maxValue) {
    if (node == nullptr) {
        return true;
    }

    if (node->data < minValue || node->data > maxValue) {
        return false;
    }

    return IsBinTree(node->left, minValue, node->data - 1) &&
        IsBinTree(node->right, node->data + 1, maxValue);
}

int main() {
    Node* root = new Node{ NULL, NULL, 3 };
    root->left = new Node{ NULL, NULL, 2 };              //   3
    root->right = new Node{ NULL, NULL, 4};             // 2   4
    root->right->right = new Node{ NULL, NULL, 5 };    //1       5
    root->left->left = new Node{ NULL, NULL, 1 };

    std::cout << IsBinTree(root, 0, 5);
}