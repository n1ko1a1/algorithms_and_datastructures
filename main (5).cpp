#include <iostream>

struct Node {
  Node* left;
  Node* right;
  int data;
};

// Функция для проверки является ли дерево поиска правильным
bool isBinarySearchTree(Node* node) {
  // Если узел пустой, то дерево является правильным деревом поиска
  if (node == nullptr) return true;

  // Проверяем условие для текущего узла:
  // значение в текущем узле больше значений в левом поддереве
  if (node->left != nullptr && node->left->data > node->data) return false;

  // значение в текущем узле меньше значений в правом поддереве
  if (node->right != nullptr && node->right->data < node->data) return false;

  // Проверяем оставшиеся поддеревья
  return isBinarySearchTree(node->left) && isBinarySearchTree(node->right);
}

int main() {
  // Пример использования функции:
  // Создаем дерево
  Node root;
  root.data = 5;
  root.left = new Node{nullptr, nullptr, 2};
  root.right = new Node{nullptr, nullptr, 7};

  // Проверяем, является ли дерево правильным деревом поиска
if (isBinarySearchTree(&root)) {
std::cout << "Дерево является правильным деревом поиска" << std::endl;
} else {
std::cout << "Дерево НЕ является правильным деревом поиска" << std::endl;
}

return 0;
}
