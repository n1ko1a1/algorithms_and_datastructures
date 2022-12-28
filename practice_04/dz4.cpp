#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() 
{
    string message; 
    int x;
    int step;
    cout<<"Введите 1 для шифровки и 2 для расшифровки сообщения"<<endl;
    cin>>x;
    if (x == 1)
    {
        cout<<"Введите сообщение"<<endl;
        cin >> message;
        cout<<"Введите шаг шифровки"<<endl;
        cin >> step;

        for (auto & alphabet : message) 
        {
            if (alphabet >= 'a' && alphabet <= 'z') 
                alphabet = ((alphabet - 'a' + step) % 26) + 'a';
        }
    }

    else if (x == 2)
    {
        cout<<"Введите сообщение"<<endl;
        cin >> message;
        cout<<"Введите шаг шифровки"<<endl;
        cin >> step;

        for (auto & alphabet : message) 
        {
            if (alphabet >= 'a' && alphabet <= 'z') 
                alphabet = ((alphabet - 'a' - step) % 26) + 'a';
        }        
    }
    cout << message << endl;
}