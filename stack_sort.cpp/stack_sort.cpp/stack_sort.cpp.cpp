#include <string>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
typedef Node* PNode;
void see(PNode);
PNode butld(PNode);
void exchange(PNode);
PNode add(PNode);
PNode gen(PNode);
PNode del(PNode);
void sort(PNode);
int main(void)
{
    setlocale(0, "ru");
    char number;
    Node* s;
    s = NULL;
    //system("cls");
    while (1)
    {
        cout << "вид операции:             A - создать / добавить" << endl;
        cout << "                          D - удалить" << endl;
        cout << "                          S - просмотреть" << endl;
        cout << "                          E - закончить" << endl;
        cout << "                          G - добавить n случайных элементов" << endl;
        cout << "                          O - сортировка по убыванию" << endl;
        cin >> number;
        switch (number)
        {
        case 'a': case 'A': s = add(s); break;
        case 'd': case 'D': s = del(s); break;
        case 's': case 'S': see(s); break;
        case 'g': case 'G': s = gen(s); break;
        case 'o': case 'O': sort(s); break;
        case 'e': case 'E': return 0;
        default: printf("Ошибка, повторите \n");
        }
    }
    return 0;
}
PNode add(PNode s)
{
    PNode new_s;
    new_s = new Node;
    if (new_s == NULL)
    {
        cout << "Нет свободной памяти" << endl;
        return s;
    }
    cout << "Введите информацию в Data" << endl;
    cin >> new_s->data;
    new_s->next = s;
    return new_s;
}
void sort(PNode s)
{
    // Создаем временный стек, в котором будут отсортированы элементы
    PNode temp = NULL;
    // Пока исходный стек не пуст, выполняем следующее
    while (s != NULL)
    {
        // Запоминаем верхний элемент исходного стека
        PNode top = s;
        // Удаляем его из исходного стека
        s = s->next;
        // Пока временный стек не пуст и верхний элемент временного стека больше запомненного элемента
        while (temp != NULL && temp->data > top->data)
        {
            // Перемещаем верхний элемент временного стека в исходный стек
            PNode tmp = temp;
            temp = temp->next;
            tmp->next = s;
            s = tmp;
        }
        // Помещаем запомненный элемент в временный стек на нужную позицию
        top->next = temp;
        temp = top;
    }
    // Возвращаем временный стек в качестве отсортированного стека
    s = temp;
}
PNode gen(PNode s)
{
    cout << "введите кол-во элементов: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        PNode new_s;
        new_s = new Node;
        if (new_s == NULL)
        {
            cout << "Нет свободной памяти" << endl;
            return s;
        }
        new_s->data = rand() % 100;
        new_s->next = s;
        s = new_s;
    }
    return s;
}
void see(PNode s)
{
    PNode s1;
    s1 = s;
    if (s == NULL)
    {
        cout << "Стек " << endl;
        return;
    }
    do
    {
        cout << s1->data << endl;
        s1 = s1->next;
    } while (s1 != NULL);
    cout << "вывод стека закончен" << endl;
}
PNode del(PNode s)
{
    PNode s1;
    if (s == NULL) {
        cout << "Стек пуст" << endl;
        return 0;
    }
    s1 = s;    s = s->next;
    delete(s1);
    cout << "последний элемент стека удален" << endl;
    return (s);
}
void exchange(PNode s)
{
    PNode tmp;
    tmp = s->next->next;
    s->next->next = s;
    s = tmp;
}