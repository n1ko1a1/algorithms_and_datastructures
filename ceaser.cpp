#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char Substitute (char letter, int key, char vibor)
{
    int new_ind;
    char x;
    const int n=26;
    char Alfavit[n]={'a','b','c','d','e','f','g','h','i','j','k','l',
    'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i=0; i<n; i++)
    {
        if (letter==Alfavit[i])
        {
            if (vibor=='e')
            {
                new_ind=i+key;
                while (new_ind>(n-1))
               {
                  new_ind=new_ind-n;
               }
            }
            if (vibor=='d')
            {
                new_ind=i-key;
                while (new_ind<0)
               {
                  new_ind=new_ind+n;
               }
            }
            x=Alfavit[new_ind];         
        }
    }
    return x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
    const int N=256;
    char Str[N];
    cout<<"Введите текст: "<<endl;
    gets(Str);
    int length=strlen(Str);
    char vibor;
    cout<<"Если вы хотите зашифровать текст, нажмите e"<<
    endl<<"Если вы хотите расшифровать текст, нажмите d"<<endl;
    cin>>vibor;
    if (vibor!='d' && vibor!='e' )
    {
    	cout<<"Вы неправильно ввели данные"<<endl;
		return 0;
    }
    int key;
    cout<<"Введите шаг сдвига(от 1 до 26): ";
    cin>>key;
    if (key < 1 || key > 26 )
    {
    	cout<<"Вы неправильно ввели шаг сдвига"<<endl;
		return 0;
    }
    for (int i=0; i<length; i++)
    {
        if (Str[i]==' ')
        {
            Str[i]=Str[i];
        }
        else
        {
            Str[i]=Substitute (Str[i], key,vibor);
        }
    }
    cout<<"Новый текст: "<<endl<<Str;
    return 0;
    
}
