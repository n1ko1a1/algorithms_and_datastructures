#include <iostream>
#include <vector>

struct BSTreeNode {
    std::string key;
    struct BSTreeNode *left{};
    struct BSTreeNode *right{};
};

void insert(BSTreeNode *&root, const std::string &k) {
    if (root == nullptr) {
        root = new BSTreeNode;
        root->key = k;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (k < root->key)
            insert(root->left, k);
        else
            insert(root->right, k);
    }
}

void print(BSTreeNode *n) {
    if (n != nullptr) {
        print(n->left);
        std::cout << n->key << "; ";
        print(n->right);
    }
}

int main() {
    std::vector<std::string> tree{"camel", "wind", "zero", "maya", "aim", "born", "xen"};

    BSTreeNode *root = nullptr;
    for (const auto &item: tree) {
        insert(root, item);
    }
    print(root);

    return 0;
}