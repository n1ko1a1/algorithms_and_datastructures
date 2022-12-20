#include <iostream>
#include <string>
#include <iterator>

using namespace std;
int main()
{
    string stroka;
    cout << "Enter a string consisting of parentheses and put 0 at the end" << endl;
    cin >> stroka;
    int oBraces = 0;
    int cBraces = 0;
    int oSquareBrackets = 0;
    int cSquareBrackets = 0;
    int oRoundBrackets = 0;
    int cRoundBrackets = 0;
    int dlina = stroka.size() - 1;
    if (dlina % 2 != 0)
    {
        cout << "False";
    }
    else
    {
        for (string::size_type i = 0, len = stroka.size() - 1; i < len; ++i)
        {
            if (stroka[i] == '{')
                oBraces++;
            else if (stroka[i] == '}')
                cBraces++;
            else if (stroka[i] == '[')
                oSquareBrackets++;
            else if (stroka[i] == ']')
                cSquareBrackets++;
            else if (stroka[i] == '(')
                oRoundBrackets++;
            else cRoundBrackets++;
        }
        if ((oBraces == cBraces) & (oSquareBrackets == cSquareBrackets) & (oRoundBrackets == cRoundBrackets))
            cout << "true";
        else cout << "false";
    }
}