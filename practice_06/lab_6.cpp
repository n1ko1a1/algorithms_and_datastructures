#include <iostream>

struct Node {
	Node* left;
	Node* right;
	int data;
};


bool tree(Node* node) {
	if (node == nullptr) {
		return true;
	}
	if (node->left != nullptr && node->left->data > node->data) {
		return false;
	}
	if (node->right != nullptr && node->right->data < node->data) {
		return false;
	}
	return tree(node->left) && tree(node->right);
}

int main() {
	Node root;
	root.data = 5;
	root.left = new Node{ nullptr, nullptr, 3 };
	root.right = new Node{ nullptr, nullptr, 7 };

	if (tree(&root)) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}

	return 0;
}