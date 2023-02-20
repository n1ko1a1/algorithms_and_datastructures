#include <iostream>
#include <vector>

struct BSTreeNode {
	std::string key;
	struct BSTreeNode* left{};
	struct BSTreeNode* right{};
};

void insertNode(BSTreeNode*& root, const std::string& k) {
	if (root == nullptr) {
		root = new BSTreeNode;
		root->key = k;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		if (k < root->key)
			insertNode(root->left, k);
		else
			insertNode(root->right, k);
	}
}

void printTree(BSTreeNode* n) {
	if (n != nullptr) {
		printTree(n->left);
		std::cout << n->key << "; ";
		printTree(n->right);
	}
}

int main() {
	std::vector<std::string> v1{ "camel", "wind", "zero", "maya", "aim", "born", "xen" };

	BSTreeNode* root = nullptr;

	for (const auto& item : v1) {
		insertNode(root, item);
	}

	printTree(root);

	return 0;
}
