﻿#include <string>
#include <iostream>
#include <algorithm>
#include <conio.h>
#include <Windows.h>
using namespace std;
struct marks
{
    int mark;
    marks* next = NULL;
};
struct Student 
{
    string surname; 
    int group; 
    marks* marks;
};
// Определяем узел очереди, содержащий указатель на структуру Student
struct Node 
{
    Student* data; 
    Node* next; 
    Node* prev; // указатель на предыдущий элемент (для двунаправленной очереди)
};
// Определяем тип PNode для удобства
typedef Node* PNode;
// Объявляем функции для работы с очередью
void add(PNode& h, PNode& t, Student* s); 
void del(PNode& h, PNode& t); // удаление элемента из начала очереди
void see(PNode h); 
void sort(PNode& h, PNode& t, int mode); // сортировка очереди по фамилии или по номеру группы
void remove(PNode& h, PNode& t); // удаление информации по учащимся, получившим три и более неудовлетворительные оценки
PNode find(PNode h, string surname); 
void edit(PNode p, Student* s); // редактирование информации в очереди
int main(void) {
    setlocale(0, "ru");
    char number;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PNode h, t; // указатели на начало и конец очереди
    h = t = NULL; // инициализируем пустой очередью
    while (1) 
    {
        cout << "вид операции:             1 - добавить элемент в очередь" << endl;
        cout << "                          2 - вывод содержимого очереди" << endl;
        cout << "                          3 - удаление элемента из начала очереди" << endl;
        cout << "                          4 - сортировка очереди" << endl;
        cout << "                          5 - удаление информации по неудовлетворительным оценкам" << endl;
        cout << "                          6 - поиск информации по фамилии" << endl;
        cout << "                          7 - редактирование информации в очереди" << endl;
        cout << "                          0 - окончить" << endl;
        cin >> number;
        switch (number) 
        {
            case '1': 
            {
                // Создаем структуру Student и заполняем ее данными
                Student* s = new Student;
                cout << "Введите фамилию: ";
                cin >> s->surname;
                cout << "Введите номер группы: ";
                cin >> s->group;
                cout << "Введите количество оценок: ";
                int n;
                cin >> n;
                cout << "Введите оценки: ";
                s->marks = new marks;
                marks* cur;
                cur = s->marks;
                for (int i = 0; i < n; i++) 
                {
                    int mark;
                    cin >> mark;
                    cur->mark = mark; // добавляем оценку 
                    cur->next = new marks;
                    cur = cur->next;
                }
                // Добавляем структуру в очередь
                add(h, t, s);
                break;
            }
            case '2': see(h); break; 
            case '3': if (h) del(h, t); break; // удаляем элемент из начала очереди, если очередь не пуста
            case '4': 
            {
                cout << "Введите режим сортировки: 1 - по фамилии, 2 - по номеру группы" << endl;
                int mode;
                cin >> mode;
                // Сортируем очередь
                sort(h, t, mode);
                break;
            }
            case '5': remove(h, t); break; // удаляем информацию по неудовлетворительным оценкам
            case '6': 
            {
                cout << "Введите фамилию для поиска: ";
                string surname;
                cin >> surname;
                // Ищем информацию по фамилии
                PNode p = find(h, surname);
                if (p) 
                {
                    cout << "Найдена информация по учащемуся: " << endl;
                    cout << "Фамилия: " << p->data->surname << endl;
                    cout << "Номер группы: " << p->data->group << endl;
                    cout << "Оценки: ";
                    marks* nextmark;
                    nextmark = p->data->marks;
                    do 
                    {
                        cout << nextmark->mark << " ";
                        nextmark = nextmark->next;
                    } 
                    while (nextmark->next != NULL);
                    cout << endl;
                }
                else 
                {
                    // Сообщаем, что информация не найдена
                    cout << "Информация по учащемуся с фамилией " << surname << " не найдена." << endl;
                }
                break;
            }
            case '7': 
            {
                cout << "Введите фамилию для редактирования: ";
                string surname;
                cin >> surname;
                // Ищем информацию по фамилии
                PNode p = find(h, surname);
                if (p) 
                {
                    Student* s = new Student;
                    cout << "Введите новую фамилию: ";
                    cin >> s->surname;
                    cout << "Введите новый номер группы: ";
                    cin >> s->group;
                    cout << "Введите новое количество оценок: ";
                    int n;
                    cin >> n;
                    cout << "Введите новые оценки: ";
                    s->marks = new marks;
                    marks* cur;
                    cur = s->marks;
                    for (int i = 0; i < n; i++)
                    {
                        int mark;
                        cin >> mark;
                        cur->mark = mark; // добавляем оценку 
                        cur->next = new marks;
                        cur = cur->next;
                    }
                    // Редактируем информацию в очереди
                    edit(p, s);
                }
                else 
                {
                    cout << "Информация по учащемуся с фамилией " << surname << " не найдена." << endl;
                }
                break;
            }
            case '0': case 'E': return 0; 
            default: printf("Ошибка, повторите \n"); 
        }
    }
    return 0;
}

// Функция для добавления элемента в конец очереди
void add(PNode& h, PNode& t, Student* s) 
{
    // Создаем новый узел и заполняем его данными
    PNode p = new Node;
    p->data = s;
    p->next = NULL;
    p->prev = t; // для двунаправленной очереди
    // Если очередь пуста, то новый узел становится началом и концом
    if (h == NULL) 
    {
        h = t = p;
    }
    else 
    {
        // добавляем новый узел в конец очереди
        t->next = p;
        // обновляем указатель на конец очереди
        t = p;
    }
}

// Функция для удаления элемента из начала очереди
void del(PNode& h, PNode& t) 
{
    // указатель на 1 элемент
    PNode p = h;
    // Перемещаем указатель на начало очереди на следующий элемент
    h = h->next;
    if (h == NULL) 
    {
        t = NULL;
    }
    else 
    {
        // Иначе обнуляем указатель на предыдущий элемент (для двунаправленной очереди)
        h->prev = NULL;
    }
    // p - первы элемент
    delete p;
}

// Функция для вывода содержимого очереди
void see(PNode h) 
{
    // Проходим по всем элементам очереди
    while (h != NULL) 
    {
        cout << "Фамилия: " << h->data->surname << endl;
        cout << "Номер группы: " << h->data->group << endl;
        cout << "Оценки: ";
        marks* nextmark;
        nextmark = h->data->marks;
        do
        {
            cout << nextmark->mark << " ";
            nextmark = nextmark->next;
        } 
        while (nextmark->next != NULL);
        cout << endl << endl;
        h = h->next;
    }
}

// Функция для сортировки очереди по фамилии или по номеру группы
void sort(PNode& h, PNode& t, int mode) 
{
    // Если очередь пуста или содержит один элемент, то ничего не делаем
    if (h == NULL || h == t) 
    {
        return;
    }
    // Иначе создаем новую пустую очередь
    PNode nh, nt;
    nh = nt = NULL;
    // h - исходная очередь
    while (h != NULL) 
    {
        // Извлекаем первый элемент из исходной очереди
        PNode p = h;
        h = h->next;
        if (h == NULL) 
        {
            t = NULL;
        }
        else 
        {
            h->prev = NULL;
        }
        // Вставляем его в новую очередь в нужное место
        // В зависимости от режима сортировки
        if (mode == 1) 
        {
            // Сортировка по фамилии
            // Ищем место для вставки
            PNode q = nh;
            while (q != NULL && q->data->surname < p->data->surname) 
            {
                q = q->next;
            }
            // Если новая очередь пуста или элемент должен быть в начале
            if (q == NULL || q == nh) 
            {
                // Добавляем элемент в начало новой очереди
                p->next = nh;
                p->prev = NULL;
                if (nh == NULL) 
                {
                    nt = p;
                }
                else 
                {
                    nh->prev = p;
                }
                nh = p;
            }
            else {
                // Иначе добавляем элемент перед найденным элементом
                p->next = q;
                p->prev = q->prev;
                q->prev->next = p;
                q->prev = p;
            }
        }
        else if (mode == 2) 
        {
            // Сортировка по номеру группы
            // Ищем место для вставки
            PNode q = nh;
            while (q != NULL && q->data->group < p->data->group) 
            {
                q = q->next;
            }
            // Если новая очередь пуста или элемент должен быть в начале
            if (q == NULL || q == nh) 
            {
                // Добавляем элемент в начало новой очереди
                p->next = nh;
                p->prev = NULL;
                if (nh == NULL) 
                {
                    nt = p;
                }
                else 
                {
                    nh->prev = p;
                }
                nh = p;
            }
            else 
            {
                // Иначе добавляем элемент перед найденным элементом
                p->next = q;
                p->prev = q->prev;
                q->prev->next = p;
                q->prev = p;
            }
        }
    }
    // Обновляем указатели на начало и конец очереди
    h = nh;
    t = nt;
}

// Функция для удаления информации по учащимся, получившим три и более неудовлетворительные оценки
void remove(PNode& h, PNode& t) 
{
    // Проходим по всем элементам очереди
    PNode p = h;
    while (p != NULL) 
    {
        // Считаем количество неудовлетворительных оценок
        int bad = 0;
        marks* marks = p->data->marks; // копируем стек оценок
        while (marks != NULL) 
        {
            if (marks->mark < 4) 
            {
                bad++; // увеличиваем счетчик неудовлетворительных оценок
            }
            marks = marks->next;
        }
        // Если неудовлетворительных оценок три и более
        if (bad >= 3) 
        {
            // Удаляем элемент из очереди
            // Сохраняем указатель на следующий элемент
            PNode q = p->next;
            // Если элемент в начале очереди
            if (p == h) 
            {
                // Перемещаем указатель на начало очереди на следующий элемент
                h = h->next;
                if (h == NULL) 
                {
                    t = NULL;
                }
                else {
                    // Иначе обнуляем указатель на предыдущий элемент (для двунаправленной очереди)
                    h->prev = NULL;
                }
            }
            // t - конец очереди
            else if (p == t) 
            {
                // Перемещаем указатель на конец очереди на предыдущий элемент
                t = t->prev;
                t->next = NULL;
            }
            // Если элемент в середине очереди
            else 
            {
                // Переставляем указатели на предыдущем и следующем элементах
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            // Удаляем элемент
            delete p;
            // Переходим к следующему элементу
            p = q;
        }
        else 
        {
            // Иначе переходим к следующему элементу
            p = p->next;
        }
    }
}

// Функция для поиска информации по фамилии
PNode find(PNode h, string surname) 
{
    // Проходим по всем элементам очереди
    while (h != NULL) 
    {
        // Если фамилия совпадает, то возвращаем указатель на элемент
        if (h->data->surname == surname) 
        {
            return h;
        }
        // Иначе переходим к следующему элементу
        h = h->next;
    }
    // Если не нашли совпадения, то возвращаем NULL
    return NULL;
}

// Функция для редактирования информации в очереди
void edit(PNode p, Student* s) 
{
    // р - указатель на элемент
    if (p != NULL) 
    {
        // Удаляем старую структуру Student
        delete p->data;
        // Присваиваем новую структуру Student
        p->data = s;
    }
}