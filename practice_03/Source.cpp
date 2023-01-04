#include <iostream>
#include <string>

using namespace std;
int main()
{
    int OpenBraces = 0, CloseBraces = 0, OpenSquareBrackets = 0, CloseSquareBrackets = 0, OpenRoundBrackets = 0, CloseRoundBrackets = 0;
    string string;
    cout << "Vvedite stroku s {} () [] skobkami, i  v konce postav'te 0: " << endl;
    cin >> string;
    int lenght = string.size() - 1;
    if (lenght % 2 != 0)
    {
        cout << "False";
    }
    else
    {
        for (string::size_type i = 0, len = string.size() - 1; i < len; ++i)
        {
            if (string[i] == '{')
                OpenBraces++;
            else if (string[i] == '}')
                CloseBraces++;
            else if (string[i] == '[')
                OpenSquareBrackets++;
            else if (string[i] == ']')
                CloseSquareBrackets++;
            else if (string[i] == '(')
                OpenRoundBrackets++;
            else CloseRoundBrackets++;
        }
        if ((OpenBraces == CloseBraces) & (OpenSquareBrackets == CloseSquareBrackets) & (OpenRoundBrackets == CloseRoundBrackets)) {
            cout << "true";
        }
        else {
            cout << "false";
        }
    }
}