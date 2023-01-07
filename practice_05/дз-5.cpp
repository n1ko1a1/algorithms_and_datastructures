#include <iostream>
#include <string>
#include <algorithm> 
#include <map>
using namespace std;
int main()
{ 
    setlocale(LC_ALL, "Russian");
    
	map<string, int> word_num; // создаем пару ключа - слова и его значения - счётчика
    string text="", line;
    string word = "";
    cout << "Введите текст для подсчёта слов: "<<endl;
    cout << "Для завершения ввода строк необходимо ввести строку 'Конец'."<<endl;
    while (line!="Конец") // цикл для ввода текста по строкам
    {
        cin >> line;
        if (line!="Конец")
        {
            text = text + line + " ";
        }
    }
    
    for (char c : text) // перебираем текст посимвольно, если встречаем знаки припенания или пробел - считаем что слово закончено и увеличиваем его счётчик
    {
        if (c == ' ' || c == '!' || c == '.' || c == '?' || c == ',')
        {
            if (!word.empty()) // Если в слове ничего нет,  то счётчик не трогаем
            {
                word_num[word]++;
            }
            word = "";
            
        }
        else 
        {
            word += c;
        }
    }

    word_num[word]++;
    string wordComm="";
    int wordComm_num = 0;
    for (const auto& pair : word_num) // Сравниваем каждую пару в map c наибольшими величинами
    {
        if (pair.second > wordComm_num)
        {
            wordComm = pair.first;
            wordComm_num = pair.second;
        }
    }

    cout << wordComm << " " << wordComm_num << endl;


    return 0;
}
