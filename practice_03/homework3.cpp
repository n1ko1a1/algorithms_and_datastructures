#include <iostream>

using namespace std;

int main() {
    int symbols[3][2] = {};
    char symbol;
    while (true) {
        cin >> symbol;
        switch (symbol) {
            case '(':
                symbols[0][0] += 1;
                break;
            case ')':
                symbols[0][1] += 1;
                break;
            case '[':
                symbols[1][0] += 1;
                break;
            case ']':
                symbols[1][1] += 1;
                break;
            case '{':
                symbols[2][0] += 1;
                break;
            case '}':
                symbols[2][1] += 1;
                break;
        }
        if (symbol == '0') break;
    }
    if(symbols[0][0] == symbols[0][1] && symbols[1][0] == symbols[1][1] && symbols[2][0] == symbols[2][1]){
        cout << "True";
    } else {
        cout << "False";
    }
}