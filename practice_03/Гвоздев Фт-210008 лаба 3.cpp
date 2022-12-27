#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<char> st;

  char c;
  while (cin >> c) {
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
    } else {
      if (st.empty()) {
        cout << "false" << endl;
        return 0;
      }

      char top = st.top();
      st.pop();

      if ((c == ')' && top != '(') ||
          (c == ']' && top != '[') ||
          (c == '}' && top != '{')) {
        cout << "false" << endl;
        return 0;
      }
    }
  }


  cout << (st.empty() ? "true" :"false") << endl;
  return 0;
}



