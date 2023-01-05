#include <iostream>
#include <climits> 

struct Node {
    Node* left;
    Node* right;
    int data;
};

bool SearchTree(Node* node, int minValue, int maxValue) {
    if (node == nullptr) {
        return true;
    }

    if (node->data < minValue || node->data > maxValue) {
        return false;
    }

    return SearchTree(node->left, minValue, node->data - 2) &&
        SearchTree(node->right, node->data + 2, maxValue);
}

int main() {
    Node* root = new Node{ nullptr, nullptr, 4 };
    root->left = new Node{ nullptr, nullptr, 2 };
    root->right = new Node{ nullptr, nullptr, 6 };

    bool searchTree = SearchTree(root, INT_MIN, INT_MAX);
    std::cout << (searchTree ? "true" : "false") << std::endl;

    return 0;
}