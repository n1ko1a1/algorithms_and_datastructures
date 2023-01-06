#include <iostream>
#include <string>
#include <stack>


bool Check(std::string s) {
	std::stack<char> openBrackets;
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '(':
		case '[':
		case '{':
			openBrackets.push(s[i]);
			break;
		case ')':
			if (openBrackets.empty()) return false;
			if (openBrackets.top() != '(') {
				return false;
			}
			else {
				openBrackets.pop();
			}
			break;
		case ']':
			if (openBrackets.empty()) return false;
			if (openBrackets.top() != '[') {
				return false;
			}
			else {
				openBrackets.pop();
			}
			break;
		case '}':
			if (openBrackets.empty()) return false;
			if (openBrackets.top() != '{') {
				return false;
			}
			else {
				openBrackets.pop();
			}
			break;
		}
	}
	return openBrackets.empty();
}

int main()
{
	std::string brackets = "[([({})])]";
	std::cout << Check(brackets);
}
