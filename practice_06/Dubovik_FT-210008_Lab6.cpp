#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Создаем узел
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Отсортированный (inorder) обход
void inorder(struct node *root) {
  if (root != NULL) {
    // Обходим лево
    inorder(root->left);

    // Обходим корень
    cout << root->key << " -> ";

    // Обходим право
    inorder(root->right);
  }
}

// Вставка узла
struct node *insert(struct node *node, int key) {
  // Возвращаем новый узел, если дерево пустое
  if (node == NULL) return newNode(key);

  // Проходим в нужное место и вставляет узел
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Поис inorder-преемника
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Ищем крайний левый лист — он и будет inorder-преемником
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Удаление узла
struct node *deleteNode(struct node *root, int key) {
  // Возвращаем, если дерево пустое
  if (root == NULL) return root;

  // Ищем узел, который хотим удалить
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // Если у узла один дочерний элемент или их нет
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // Если у узла два дочерних элемента
    struct node *temp = minValueNode(root->right);

    // Помещаем inorder-преемника на место узла, который хотим удалить
    root->key = temp->key;

    // Удаляем inorder-преемника
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Тестим функции
int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Отсортированный обход: ";
  inorder(root);

  cout << "\nПосле удаления 10 10\n";
  root = deleteNode(root, 10);

  cout << "Отсортированный обход: ";
  inorder(root);
}