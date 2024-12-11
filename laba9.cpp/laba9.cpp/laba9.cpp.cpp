#include <string>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <stack>
using namespace std;
struct Node
{
	int data;       //данные
	Node* next;          // указатель на следующий элемент
};
typedef Node * PNode;
void see(PNode);         // просмотреть стек
PNode butld(PNode);       // создать вершину стека
void exchange(PNode);       
PNode add(PNode);          // добавить элемент в стек
PNode gen(PNode);          // добавить n слцчайных элементов
PNode del(PNode);        // удалить элемент стека
void sort(PNode);        // соритровка стека
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
		//fflush(stdin);                     // Очищаем входной поток
		//switch (_getch())                  // Ждем ввод символа _getch() в отличие от getchar() берет символ без Entera
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
// функция создания и добавления элемента стека
PNode add(PNode s)
{
	PNode new_s;    
	new_s = new Node; // новый элемент вершины стека
	if (new_s == NULL) // Если память не выделилась выводим сообщение и выходим
	{
		cout << "Нет свободной памяти" << endl;
		return s;
	}
	// размещаем новый элемент на вершину стека
	cout << "Введите информацию в Data" << endl;
	cin >> new_s->data;
	new_s->next = s;         // указатель на предыдущий элемент стека
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
		new_s = new Node; // новый элемент вершины стека
		if (new_s == NULL) // Если память не выделилась выводим сообщение и выходим
		{
			cout << "Нет свободной памяти" << endl;
			return s;
		}
		// размещаем новый элемент на вершину стека
		new_s->data = rand() % 100;
		new_s->next = s;         // указатель на предыдущий элемент стека
		s = new_s;
	}
	return s;
}
//функция просмотра элементов стека
void see(PNode s)
{
	PNode s1;
	s1 = s;
	// текущая вершина стека
	if (s == NULL)
	{
		cout << "Стек " << endl;
		return;
	}
	do
	{
		cout << s1->data << endl;
		s1 = s1->next;                      // переход к предыдущему элементу стека
	}	while (s1 != NULL);
	cout << "вывод стека закончен" << endl;
}
// функция удаления последнего элемента стека
PNode del(PNode s)
{
	PNode s1;
	if (s == NULL)
	{
		cout << "Стек пуст" << endl;
		return 0;
	}
	s1 = s;            // запоминаем старый указатель на вершину стека
	s = s->next;        // передвигаем указатель на следующий элемент стека
	delete(s1);         // удаляем элемент с вершины стека
		cout << "последний элемент стека удален" << endl;
		return (s);     // возвращаем указатель на новую вершину стека
}
void exchange(PNode s)
{
	PNode tmp;
	tmp = s->next->next;
	s->next->next = s;
	s = tmp;
}
