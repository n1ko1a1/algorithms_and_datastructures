#include <iostream>
#include <sstream>
#include <map>
#include <cstdlib>

using namespace std;

//Максимальная длина строки
int main() {
  
    setlocale(LC_ALL, "Rus");
    const int N = 256;                                             
    map <int, string> mp;

    string S;
    cout << "Введите строку = ";
    getline(cin, S);

//Считывание строки
    char word[N] = {};                                             
    stringstream x;                                                
    x << S; 
    int i = 1;
  
    while (x >> word)
    {
      
        mp[i] = word;
        i += 1;
      
    }


    map <int, string> ::iterator it = mp.begin();
    map <int, string> ::iterator it2 = mp.begin();

    int itog1[256] = {};
    string itog2[256] = {};

    
    for (int i = 0; it != mp.end(); it++, i++)
    {
        
        itog2[i] = it->first;
      
        for (int x = 0; it2 != mp.end(); it2++, x++)
        {

            if (it->second == it2->second)
            {
             
                itog2[i] = it2->second;
                itog1[i] += 1;
              
            }
            
        }
      
        it2 = mp.begin();
      
    }

    int max = 0;
  
    for (int i = 0; i < 256; i++)
    {
      
        if (itog1[i] > max)
        {
          
            max = itog1[i];
          
        }
    }

    int ii = 0;
    int index = 0;

    for (int b : itog1)
    {
      
        if (b == max)
        {
          
            index = ii;
            break;
          
        }
        ii += 1;
      
    }
  
    

   
    cin.get();
    return 0;
  
} 
