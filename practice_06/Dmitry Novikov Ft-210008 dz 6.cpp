#include <iostream>
#include <climits> // Для INT_MIN и INT_MAX

struct Node {
  Node* left;
  Node* right;
  int data;
};

bool IsBinarySearchTree(Node* node, int minValue, int maxValue) {
  if (node == nullptr) {
    return true;
  }

  if (node->data < minValue || node->data > maxValue) {
    return false;
  }

  return IsBinarySearchTree(node->left, minValue, node->data - 1) &&
         IsBinarySearchTree(node->right, node->data + 1, maxValue);
}

int main() {
  Node* root = new Node{nullptr, nullptr, 5};
  root->left = new Node{nullptr, nullptr, 3};
  root->right = new Node{nullptr, nullptr, 7};

  bool isBinarySearchTree = IsBinarySearchTree(root, INT_MIN, INT_MAX);
  std::cout << (isBinarySearchTree ? "true" : "false") << std::endl;

  return 0;
}
