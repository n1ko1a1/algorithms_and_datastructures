#include <iostream>
using namespace std;
#include <list>


int main()
{
    setlocale(LC_ALL, "Russian");
    
    list<string> myList;
    string s;
    
    while (s != "0") 
    {
        cout << "Ввод: ";
        cin >> s;
        myList.push_back(s);
    }
    
    int r1 = 0;
    int l1 = 0;
    int r2 = 0;
    int l2 = 0;
    int r3 = 0;
    int l3 = 0;
    for (auto i = myList.begin(); i != myList.end(); i++)
    {
        if (*i == ")") {
            r1++;
        };
        if (*i == "(") {
            l1++;
        };
        if (*i == "]") {
            r2++;
        };
        if (*i == "[") {
            l2++;
        };
        if (*i == "}") {
            r3++;
        };
        if (*i == "{") {
            l3++;
        };
    }
    
    if (r1 == l1 && r1 != 0 && l1 != 0)
    {
        cout << "true" << endl;
    } else if (r2 == l2 && r2 != 0 && l2 != 0) 
    {
        cout << "true" << endl;
    } else if (r3 == l3 && r3 != 0 && l3 != 0) 
    {
        cout << "true" << endl;
    } else 
    {
       cout << "false" << endl; 
    }
    
    
    return 0;
}
