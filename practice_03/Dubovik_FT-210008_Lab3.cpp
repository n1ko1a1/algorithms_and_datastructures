#include <bits/stdc++.h>

using namespace std;

int main() {
    stack <int> p;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='(' || s[i] == '{'){
            p.push(s[i]);
        }
        else{
            if(s[i] == ')' && !p.empty() && p.top() == '(') {
                p.pop();
            }
            else if (s[i] == '}' && !p.empty() && p.top() == '{') {
                p.pop();
            }
            else if ((s[i] == '}' || s[i] == ')') && p.empty()) {
                p.push(i);
                break;
            }
        }
    }
    if(p.empty()){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}