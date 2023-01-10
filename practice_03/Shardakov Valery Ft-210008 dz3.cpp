#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(char c) {
        Node* newNode = new Node;
        newNode->data = c;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return '\0';
        }

        char c = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return c;
    }

    bool isEmpty() { return top == nullptr; }
};

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    }
    if (open == '[' && close == ']') {
        return true;
    }
    if (open == '{' && close == '}') {
        return true;
    }
    return false;
}

int main() {
    Stack stack;
    string input;

    while (true) {
        cin >> input;
        if (input == "0") {
            break;
        }

        for (char c : input) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }
            else if (c == ')' || c == ']' || c == '}') {
                char open = stack.pop();
                if (!isMatchingPair(open, c)) {
                    cout << "false" << endl;
                    return 0;
                }
            }
        }
    }

    cout << (stack.isEmpty() ? "true" : "false") << endl;
    return 0;
}
