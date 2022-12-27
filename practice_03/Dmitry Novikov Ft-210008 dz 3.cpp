#include <iostream>
#include <string>

struct Node {
  char data;
  Node* next;
};

class Stack {
public:
  Stack() : head_(nullptr) {}

  void Push(char c) {
    Node* new_node = new Node;
    new_node->data = c;
    new_node->next = head_;
    head_ = new_node;
  }

  char Pop() {
    if (IsEmpty()) {
      // Обработка ошибки, если стек пуст
      return '\0';
    }
    Node* temp = head_;
    head_ = head_->next;
    char c = temp->data;
    delete temp;
    return c;
  }

  bool IsEmpty() {
    return head_ == nullptr;
  }

private:
  Node* head_;
};

bool IsBalanced(const std::string& str) {
  Stack stack;
  for (char c : str) {
    if (c == '(' || c == '[' || c == '{') {
      stack.Push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      char top = stack.Pop();
      if ((c == ')' && top != '(') ||
          (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        return false;
      }
    }
  }
  return stack.IsEmpty();
}

int main() {
  std::string str;
  while (std::getline(std::cin, str)) {
    if (str == "0") {
      break;
    }
    std::cout << std::boolalpha << IsBalanced(str) << std::endl;
  }
  return 0;
}
