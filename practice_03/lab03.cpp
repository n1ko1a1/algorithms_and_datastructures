#include <iostream>
#include <string>

using namespace std;
int main()
{
    int OStaples = 0, CStaples = 0, OSquareStaples = 0, CSquareStaples = 0, ORoundStaples = 0, CRoundStaples = 0;
    string string;
    cout << "Введите строку состоящую из - {} () [] , последний символ - 0: " << endl;
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
                OStaples++;
            else if (string[i] == '}')
                CStaples++;
            else if (string[i] == '[')
                OSquareStaples++;
            else if (string[i] == ']')
                CSquareStaples++;
            else if (string[i] == '(')
                ORoundStaples++;
            else CRoundStaples++;
        }
        if ((OStaples == CStaples) & (OSquareStaples == CSquareStaples) & (ORoundStaples == CRoundStaples)) {
            cout << "true";
        }
        else {
            cout << "false";
        }
    }
}