#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
    //В лабораторной работе нужно разработать два приложения.В первом
    //приложении исходные данные вводят с клавиатуры(количество объектов, заданных
    //структурным типом, заранее неизвестно) и сохраняют в файле.Во втором
    //приложении данные, сохраненные в первом приложении в файле, читают из файла и
    //выводят на экран.В зависимости от варианта данные можно сохранять в файле как в
    //текстовом, так и в двоичном режиме.
    //Ф.И.О., группа, номер зачетной книжки, массив
    //четырех оценок за сессию
struct student
{
    char full_name[30];
    int group;
    int record_book_number;
    int grade[4];
};
int print_students(student* students_array, int count)
{
    int cw[4] = { 30, 15, 15, 12 };
    cout << setw(cw[0]) << "Ф.И.О.";
    cout << setw(cw[1]) << "Номер группы";
    cout << setw(cw[2]) << "Номер зачётки";
    cout << setw(cw[3]) << "Оценки" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << setw(cw[0]) << students_array[i].full_name;
        cout << setw(cw[1]) << students_array[i].group;
        cout << setw(cw[2]) << students_array[i].record_book_number;
        for (int d = 0; d < 4; d++)
        {
            cout << setw(cw[3]/4) << students_array[i].grade[d];
        }
        cout << endl;
    }
    return 0;
}
char names[20][30] =
{
     "Emily Johnson",
     "Nathan Smith",
     "Olivia Brown",
     "Liam Davis",
     "Sophia Miller",
     "Jacob Wilson",
     "Ava Jones",
     "Ethan Taylor",
     "Isabella Martinez",
     "Aiden Anderson",
     "Mia Thomas",
     "Noah Garcia",
     "Charlotte Clark",
     "James Rodriguez",
     "Amelia Lee",
     "Benjamin White",
     "Harper Perez",
     "William Lewis",
     "Grace Hall",
     "Samuel Scott"
};
int read_file();
int write_file();

int main()
{
    setlocale(LC_ALL, "Russian");
    while (1)
    {
        int x, error = 0;
        cout << "считать файл - 1, записать файл - 2 ";
        cin >> x;
        switch (x)
        {
        case 1:error = read_file(); break;
        case 2:error = write_file(); break;
        default:return 0;
        }
        if (error)
            return error;
    }
}
int write_file()
{
    int number_of_students = 0;
    cout << "введите кол-во студентов: ";
    cin >> number_of_students;
    student* students_array = new student[number_of_students];
    for (int i = 0; i < number_of_students; i++)
    {
        strcpy_s(students_array[i].full_name , names[rand() % 20]);
        students_array[i].group = 2323;
        students_array[i].record_book_number = rand() % 1000 + 23230000;
        for (int d = 0; d < 4; d++)
        {
            students_array[i].grade[d] = rand() % 7 + 3;
        }
    }
    print_students(students_array, number_of_students);
    FILE *pf;
    int error;
    error = fopen_s(&pf, "students.dat", "w");
    if (error)
    {
        cout << "ошибка открытия файла";
        return error;
    }
    int count = fprintf(pf, "%i\n", number_of_students); //возвращает коло-во записаных символов
    if (count < 0)
    {
        cout << "ошибка записи в файл.";
        return count;
    }
    for (int i = 0; i < number_of_students; i++)
    {
        count = fprintf(pf, "%s;%i;%i;%i;%i;%i;%i\n", students_array[i].full_name, students_array[i].group,
            students_array[i].record_book_number, students_array[i].grade[0], students_array[i].grade[1],
            students_array[i].grade[2], students_array[i].grade[3]); //возвращает коло-во блоков
        if (count < 0)
        {
            cout << "ошибка записи в файл.";
            return count;
        }
    }
    error = fclose(pf);
    if (error)
    {
        cout << "ошибка закрытия файла";
        return error;
    }
    delete[] students_array;
    return 0;
}
int read_file()
{
    int number_of_students = 0;
    FILE *pf;
    int error;
    
    error = fopen_s(&pf, "students.dat", "rt");
    if (error)
    {
        cout << "ошибка открытия файла";
        return error;
    }
     error = fscanf(pf, "%i\n", &number_of_students);
    if (error == EOF) //если наткнулся на конец файла значит не всё считал
    {
        cout << "ошибка чтения файла."; //возвращает кол-во считаных блоков
        return -1;
    }
    student* students_array = new student[number_of_students];
    for (int i = 0; i < number_of_students; i++)
    {
        error = fscanf(pf, "%30[^;];%i;%i;%i;%i;%i;%i\n", students_array[i].full_name, &students_array[i].group, // %i - шаблон для строки
            &students_array[i].record_book_number, &students_array[i].grade[0], &students_array[i].grade[1],
            &students_array[i].grade[2], &students_array[i].grade[3]); //возвращает коло-во блоков
        if (error == EOF)
        {
            cout << "ошибка записи в файл.";
            return -1;
        }
    }
    error = fclose(pf);
    if (error)
    {
        cout << "ошибка закрытия файла";
        return error;
    }
    print_students(students_array, number_of_students);
    delete[] students_array;
    return 0;
}