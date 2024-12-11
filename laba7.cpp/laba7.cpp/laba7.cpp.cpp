#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
	//Определите структуру «Студент», поля структуры : Ф.И.О., массив
	//элементов структуры «Дисциплина»(не менее четырех элементов, результаты
	//сдачи сессии); при необходимости можно использовать дополнительные поля
	//(например, число элементов в массиве дисциплин).Структура «Дисциплина»
	//включает в себя поля : название, оценка.
	//Определите средний балл группы по заданной дисциплине.
struct discipline
{
	string name;
	int grade;
};
struct student
{
	string full_name;
	discipline dis[4]; //dis название переменной в структуре 
};
const string disciplince_name[4] =
{
	"Прикладная информатика",
	"Экономическая теория",
	"Современаая политэкономия",
	"Менеджмент"
};
const string names[20] =
{
	"Самойлова Анастасия Егоровна",
	"Минаева Тамара Егоровна",
	"Кузьмина Юлия Ильинична",
	"Дьяконов Михаил Александрович",
	"Степанова Александра Артёмовна",
	"Кузнецов Иван Кириллович",
	"Воробьев Михаил Артёмович",
	"Кузнецов Глеб Тимофеевич",
	"Лазарев Пётр Дмитриевич",
	"Успенский Кирилл Даниэльевич",
	"Макарова Амелия Александровна",
	"Демин Егор Егорович",
	"Молчанова Ксения Денисовна",
	"Дмитриев Григорий Лукич",
	"Осипова Алина Артёмовна",
	"Щеглова София Александровна",
	"Никитин Георгий Богданович",
	"Марков Михаил Артурович",
	"Федоров Али Константинович",
	"Константинова Мария Александровна"
};
int main()
{
	setlocale(LC_ALL, "Russian");
	student students_array[5];
	for (int i = 0; i < 5; i++)
	{
		students_array[i].full_name = names[rand() % 19];
		for (int d = 0; d < 4; d++)
		{
			students_array[i].dis[d].name = disciplince_name[d];
			students_array[i].dis[d].grade = rand() % 7 + 3 ;
		}
	}
	cout << setw(40) << "Ф.И.О.";
	cout << setw(30) << "Название дисциплины";
	cout << setw(10) << "Оценка" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int d = 0; d < 4; d++)
		{
			if (!d)cout <<  setw(40) << students_array[i].full_name;
			if (d)cout <<  setw(40) << " ";
			cout <<  setw(30) << students_array[i].dis[d].name;
			cout <<  setw(10) << students_array[i].dis[d].grade << endl;
		}
	}
	cout << "По какой дициплине посчитать средний бал?" << endl;
	for (int k = 0; k < 4; k++)
	{
		cout << k << " - " << disciplince_name[k] << endl;
	}
	int p;
	cin >> p;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int d = 0; d < 4; d++)
		{
			if (students_array[i].dis[d].name == disciplince_name[p])
			 sum += students_array[i].dis[d].grade;
		}
	}
	cout << "Средний бал - " << sum / 5.;
}