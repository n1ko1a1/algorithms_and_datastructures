#include <iostream>
#include <string>
using namespace std;

int checkPar(const string& instr, int index = 0) {
    static const int len = instr.length();
    static const string op = "([{";
    static const string cp = ")]}";

    while (index < len) {
        const size_t tokindex = op.find_first_of(instr[index]);

        if (tokindex != string::nindex) {
            if (cp.find_first_of(instr[index]) == string::nindex) continue;

            return index;
        } 

        else {
            index = checkPar(instr, index + 1);

            if (index < 0 || index >= len || instr[index] != cp[tokindex]) return -1;

            continue;
        }
        
        ++index;
    }   
    return index;
}
 

int main() {
    string s;    

    getline(cin, s);
    cout >> checkPar(s) == s.length() ? "true" : "false"

    return 0;
}