#include <iostream>
#include <list>

using namespace std;

bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') {
        return true;
    }
    else if (character1 == '[' && character2 == ']') {
        return true;
    }
    else if (character1 == '{' && character2 == '}') {
        return true;
    }
    else {
        return false;
    }
}

bool checkBrackets(string brackets) {
    list<char> stack;

    for (int i = 0; i < brackets.length(); i++) {
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            stack.push_back(brackets[i]);
        }
        else if (brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '}') {
            if (stack.empty() || !isMatchingPair(stack.back(), brackets[i])) {
                return false;
            }
            else {
                stack.pop_back();
            }
        }
    }

    return stack.empty();
}

int main() {
    while (true) {
        string brackets;
        cin >> brackets;

        if (brackets == "0") {
            break;
        }

        cout << checkBrackets(brackets) << endl;
    }

    return 0;
}