#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() 
{
    string stroka; 
    string bukva;
    int k;
    cout<<"Введите d для расшифровки и e для шифровки"<<endl;
    cin>>bukva;
    if (bukva=="d")
    {
        cout<<"введите строку, которую нужно расшифровать"<<endl;
        cin>>stroka;
        cout<<"введите шаг сдвига"<<endl;
        cin >> k;

        for (auto & alf : stroka) 
        {
            if (alf >= 'a' && alf <= 'z') 
                alf = ((alf - 'a' + k) % 26) + 'a';
        }
    }

    else if (bukva=="e")
    {
        cout<<"введите строку, которую нужно зашифровать"<<endl;
        cin>>stroka;
        cout<<"введите шаг сдвига"<<endl;
        cin >> k;

        for (auto & alf : stroka) 
        {
            if (alf >= 'a' && alf <= 'z') 
                alf = ((alf - 'a' - k) % 26) + 'a';
        }        
    }
    cout << stroka << endl;
}
