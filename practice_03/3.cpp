#include <iostream>
#include <string>
using namespace std;

int check(const string& instr, int i = 0)

{
    static const int len = instr.length();
    static const string open = "([{";
    static const string close = ")]}";
    while (i < len)
    {
        const size_t x = open.find_first_of(instr[i]);
        if (x != string::npos){
            i = check(instr, i + 1);
            if (i < 0 || i >= len || instr[i] != close[x]) return -1;
        }
        else
            if (close.find_first_of(instr[i]) != string::npos) return i;
        ++i;
    }
    return i;
}


int main()
{
    string text;
    cout << "Enter the sequence - ";
    getline(cin, text);

    if (check(text) == text.length()){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}