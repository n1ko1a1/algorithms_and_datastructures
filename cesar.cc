/*Программа шифрования кодом Цезаря*/
#include <stdio.h>//необходимо для printf
#include <conio.h>//необходимо для getch
#include <string.h>//необходимо для puts
int main()
{
/*инициализируем переменные*/
int i=0, n=0, k;
int d;
char alf[] = "abcedfghijklmnopqrstuvwxyz0123456789#!@$%^&*-+=";//словарь
char buf[10];//массив для ввода сообщения
char decod[10];//массив для ввода сообщения
/*вывод названия программы*/
printf("\nBorland C++ 3.1");
printf("\nProgramma shifrovanija kodom Tsezarja\n");
/*Процедура шифрования ввод*/
printf("\n***Shifrovanie***");
printf("\nVvedite slovo ili tsifrj :");
scanf("%s",&buf);//ввод слова или цифр
printf("\nVvedite tzifrovoj cluch, (shag ot 1 do 10):  ");
scanf("%i",&k);//вводим ключ
for (n=0; n < 10; n++)
{
for (i = 0; i < 47; i++)
{
if (buf[n] == alf[i])
{
if (i >= 47)
buf[n] = alf[i-47];
else
buf[n] = alf[i+k];//сдвигаем вправо на показания шага ключа
break;//принудительно выходим из цикла
}
}
}
printf("\nVash shefr= %s\n", buf);//выводим полученный шифр
/*Процедура дешифрования ввод*/
printf("\n--Deshifrovanie---\n");
printf("\nVvedite vash shifr : ");
scanf("%s",&decod);//вводим шифр
printf("\nVvedite tzifrovoj cluch, (shag ot 1 do 10): ");
scanf("%i",&d);//вводим ключ
for (n=0; n < 10; n++)
{
for (i = 0; i < 47; i++)
{
if (decod[n] == alf[i])
{
if (i >= 47)
decod[n] = alf[i-47];
else
decod[n] = alf[i-d];//сдвигаем влево на показания шага ключа
break;//принудительно выходим из цикла
}
}
}
printf("\nShefr= ");
puts (decod);//выводим код
getch();//задержка программы
return 0;
}//конец
