#include "stdafx.h"
#include <iostream>
using namespace std;
 
void Eratosthenes(bool massiv[], int N)
{
int i, j;
for (j=2; j<=N; j++) massiv[j]=true;
j=2;
while (j*j<=N)
{
i=j*j;
if (massiv[j])
while (i<=N)
{
massiv[i]=false;
i=i+j;
}
j=j+1;
}
cout<<"Список простых чисел: ";
for (j=2; j<=N; j++)
{
if (massiv[j]==true) cout<<" "<<j;
}
}
 
void main()
{
setlocale(LC_ALL,"Rus");
int N;
cout<<"Введите размерность массива"<<endl;
cin>>N;
bool *massiv=new bool[N];
Eratosthenes(massiv, N);
cout<<endl;
system("pause");
}
