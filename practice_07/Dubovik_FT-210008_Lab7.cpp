#include <iostream>
using namespace std;
struct coord{
  int x;
  int y;
};
int main()
{
    int n;
    cout <<"Введите количество точек:"<<endl;
    cin >> n;
    struct coord s[n];
    for(int i=0; i<n; i++){
        cout <<"Введите координаты "<<i+1<<" точки."<<endl;
        cout <<"Введите x:"<<endl;
        cin >> s[i].x;
        cout <<"Введите y:"<<endl;
        cin >> s[i].y;
    }
    for(int i=0; i<n; i++){
        for(int k=i+1; k<n; k++){
        if(s[i].x == s[k].x){
            cout <<"Параллельно оси ординат находится прямая "<<"проведенная по координатами ("<<s[i].x<<"; "<<s[i].y<<") и ("<<s[k].x<<"; "<<s[k].y<<")"<< endl;
        }
        else if(s[i].y ==s[k].y){
            cout <<"Параллельно оси абсцисс находится прямая "<<"проведенная по координатами ("<<s[i].x<<"; "<<s[i].y<<") и ("<<s[k].x<<"; "<<s[k].y<<")"<< endl;
        }
    }
}
return 0;
}