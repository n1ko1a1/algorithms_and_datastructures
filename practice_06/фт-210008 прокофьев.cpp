#include <iostream>

using namespace std;


struct Node {
  Node* left;
  Node* right;
  int data;
};


bool isBinarySearchTree(Node* node) {
    if (node == nullptr) {
        return true;
    }

    if (node->left != nullptr && node->left->data > node->data) {
        return false;
    }

    if (node->right != nullptr && node->right->data < node->data) {
        return false;
    }

    return isBinarySearchTree(node->left) && isBinarySearchTree(node->right);
}


int main() {
    Node root;
    root.data = 5;
    root.left = new Node{nullptr, nullptr, 2};
    root.right = new Node{nullptr, nullptr, 7};

    if (isBinarySearchTree(&root)) {
        cout << "Дерево является правильным деревом поиска" << endl;
    }

    else {
        cout << "Дерево НЕ является правильным деревом поиска" << endl;
    }

    return 0;
}