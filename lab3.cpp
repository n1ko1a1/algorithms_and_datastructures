#include <iostream>
#include <stack>

struct stack
{
    int x;
    stack *next;
} *top, *cur;

void push(int i, char *str1)
{
    top = new stack;
    top->next = NULL;
    cur = top;
    cur = new stack;
    cur->x = str1[i];
    cur->next = top;
    top = cur;
}
int ControlOfThesis(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))

            push(i, str);

        else{
            stack *temp = top;
            if (temp->next) return 0;
            char t = top->x;
            delete temp;

            if ((t == '(' && str[i] != ')') ||  // если тип последней открывающей скобки 
                (t == '{' && str[i] != '}') ||  // не совпадает с текущей закрывающей скобкой 
                (t == '[' && str[i] != ']'))    // значит скобки в неправильном порядке
                return 0;

        }

    }
    return 1;
}

int main()
{
    char *str = "({[]})";
    if (ControlOfThesis(str)) cout << "YES\n";
    else cout << "NO!\n";
    system("pause");
    return 0;

}
