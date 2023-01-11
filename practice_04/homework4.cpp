#include <iostream>
#include <typeinfo>
#include <list>
#include <algorithm>

using namespace std;


int main()
{
  
	char alphabet[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	setlocale(LC_ALL, "Rus");
	char s;
	int n;
	string message;
	cout << "Для раскодировки введите - d, кодировки - e";
	cin >> s;
	cout << "Введите размер сдвига";
	cin >> n;

	if (n > 26)
	{
    
		n = n % 26;
    
	}

	cout << "Введите слово для шифровки/дешифровки";
	cin >> message;
  
	while (true)
	{
    
		if ((s != 'e') && (s != 'd'))
		{
			
      cout << "Ошибка ввода! Для раскодировки введите - d, кодировки - e";
      
		}
    
		if (n == 0)
		{
      
			cout << "Введите размер сдвига числом";
      
		}
    
		else
		{
      
			break;
      
		}
    
	}
  
	if (s == 'e')
	{
    
		list<char> sh;
    
		for (char d : message)
		{
      
			int index = 0;
      
			for (char f : alphabet)
			{

				if (d == f)
				{
          
					int nn = index + n;
          
					if (nn > 25)
					{
            
						nn = nn % 26;
            
					}
          
					char ne_w = alphabet[nn];
					sh.push_back(ne_w);
          
				}
				else
        {
          
          index += 1;
          
        }
        
			}
      
		}
    
		for (char f : sh)
		{
			
      cout << f;
      
		}
    
	}
  
	if (s == 'd')
	{
		
    list<char> sh;
    
		for (char d : message)
		{
      
			int index = 0;
      
			for (char f : alphabet)
			{

				if (d == f)
				{
          
					int nn = index - n;
          
					if (nn < 0)
					{
            
						nn = 26 + nn;
            
					}
          
					char ne_w = alphabet[nn];
					sh.push_back(ne_w);
          
				}
				else
        {
          
          index += 1;
          
        }
        
			}
      
		}
    
		for (char f : sh)
		{
      
			cout << f;
      
		}
    
	}
  
	return 0;
  
}
