#include<iostream>
#include<string>
  using namespace std;
  int main()
  {

  int* p,*e,*n,*r,j,k,m,l,t,ind,max,rm;
  string s;
  char c;
  cout << "Введите текст: "; getline(cin,s);
  cout << s << endl;
  for(m=0,c=' ',j=0;j < s.size();c=s[j++]) if(s[j]!=' '&&c==' ') m++;
  cout << "Количество слов в тексте: " << m << endl;
  p=new int[m];
  e=new int[m];
  n=new int[m];
  r=new int[m];
  for(j=0;j < m;n[j++]=0);
  for(k=0,c=' ',j=0;j < s.size();c=s[j++])

    {

  if(s[j]!=' '&&c==' ') p[k++]=j;
  if(s[j]==' '&&c!=' ') e[k-1]=j;

    }

  if(c!=' ') e[k-1]=j;
  for(j=0;j < m;j++)

    {

  if(n[j]) continue;
  n[j]=1;
  for(k=j+1;k < m;k++)

    {

  if(n[k]) continue;
  if(e[k]-p[k]==e[j]-p[j])

    {

  for(ind=1,t=p[j],l=p[k];l < e[k];l++,t++)
  if(s[t]!=s[l]) { ind=0; break; }
  if(ind) n[k]=-1,n[j]++;

    }

  } 

  }

  for(max=j=0;j < m;j++) if(n[j]>max) max=n[j];
  for(rm=j=0;j < m;j++) if(max==n[j]) r[rm++]=j;
  cout << "Максимальное количество раз: " << max << "\nвстречаются следующие слова: \n";
  for(k=0;k < rm;k++,cout << "\"\n") for(cout << '\"',j=p[r[k]];j < e[r[k]];j++) cout << s[j];
  delete [] p,e,n,r;
  return 0;

    }
