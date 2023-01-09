#include <iostream>
#include <string>

using namespace std;

int checkPar(const string& instr, int pos = 0)
{
    static const int len = instr.length();
    static const string light = "([{";
    static const string right = ")]}";
    while (pos < len)
    {
        const size_t tokpos = light.find_first_of(instr[pos]);
        if (tokpos != string::npos)
        {
            pos = checkPar(instr, pos + 1);
            if (pos < 0 || pos >= len || instr[pos] != right[tokpos]) return -1;
        }
        else
            if (right.find_first_of(instr[pos]) != string::npos) return pos;       
        ++pos;
    }   
    return pos;
}

int main()
{
    cout << "insert text: ";
    string staples;    
    getline(cin, staples);
    if (checkPar(staples) == staples.length())
    {
        cout << "True";
    }
        else
    {
        cout << "False";
    }   
    return 0;
}