#include <iostream>
#include <climits> 

struct Node {
    Node* l;
    Node* r;
    int data;
};

bool SearchTree(Node* node, int minValue, int maxValue) {
    if (node == nullptr) {
        return true;
    }

    if (node->data < minValue || node->data > maxValue) {
        return false;
    }

    return SearchTree(node->l, minValue, node->data - 2) &&
        SearchTree(node->r, node->data + 2, maxValue);
}

int main() {
    Node* root = new Node{ nullptr, nullptr, 4 };
    root->l = new Node{ nullptr, nullptr, 2 };
    root->r = new Node{ nullptr, nullptr, 6 };

    bool searchTree = SearchTree(root, INT_MIN, INT_MAX);
    std::cout << (searchTree ? "true" : "false") << std::endl;

    return 0;
}