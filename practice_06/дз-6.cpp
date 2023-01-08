#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node //задаём структуру дерева
{
    int data;
    Node* left;
    Node* right;
};

bool test(Node* root, int min, int max) // функция проверки правильности дерева
{
    if (root == nullptr) 
    {
        return true;
    }
    if (root->data < min || root->data > max) // проверка удовлетворения значения диапазону. в 1 ячейке можэет быть люое значение поддерживаемое форматом инт
    {
        return false;
    }
    return test(root->left, min, root->data - 1 ) && test(root->right, root->data + 1, max); // передаём новые границы границы в левого и правого потомка 
    //и рекурсивно проходим тест
}

int main() 
{
setlocale(LC_ALL, "Russian");
    Node cell1, cell2, cell3, cell4, cell5, cell6, cell7; // вводим узлы и их связи
    cell1.data = 10, cell2.data = 5, cell3.data = 15, cell4.data = 14, cell5.data = 20, cell6.data = 6, cell7.data = 1;
    cell1.left = &cell2;
    cell1.right = &cell3;
    cell3.left = &cell4;
    cell3.right = &cell5;
    cell2.left = &cell7;
    cell2.right = &cell6;
    cell7.right = cell7.left = cell6.right = cell6.left = cell5.left = cell5.right = cell4.left = cell4.right = nullptr; // задаём концы дерева
    if (test(&cell1, INT_MIN, INT_MAX)) // вызов функции теста дерева, которое вренёт либо тру либюо фолс
    {
        cout << "Дерево составлено корректно" << endl;
    }
    else
    {
        cout << "Дерево составлено не корректно" << endl;
    }
    return 0;
}