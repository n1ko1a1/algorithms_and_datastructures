#include <iostream>
#include <string>
using namespace std;
int checkPar(const string & instr, int pos = 0)
{
    static const int stroka = instr.length();
    static const string op = "([{";
    static const string cp = ")]}";
    while (pos < stroka)
    {
        const size_t tokpos = op.find_first_of(instr[pos]);
        if (tokpos != string::npos)
        {
            pos = checkPar(instr, pos + 1);
            if (pos < 0 || pos >= stroka || instr[pos] != cp[tokpos]) return -1;
        }
        else
            if (cp.find_first_of(instr[pos]) != string::npos) return pos;       
        ++pos;
    }   
    return pos;
}

int main()
{
    string vivod;    
    getline(cin, vivod);
    if (checkPar(vivod) == vivod.length())
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }   
    return 0;
}
