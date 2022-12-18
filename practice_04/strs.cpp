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
	cout << "Enter a text: ";
    string scobki;    
    getline(cin, scobki);
    if (checkPar(scobki) == scobki.length())
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }   
    return 0;
}
