#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int zadanie1()
{
    //В матрице порядка n найти седловую точку
    //(элемент, максимальный в строке и минимальный в столбце).
    int** a, i, j, n, m, imin, jmax;
    cout << "Введите размер матрицы: n, m" << endl;
    cin >> n >> m;
    a = new int* [n];
    for (i = 0; i < n; i++)
    // Выделение памяти под массив указателей
    // Выделение памяти под соответствующие
    a[i] = new int[m]; // этим указателям строки матрицы
    // Ввод двумерного массива
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "Vvedite a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
            //a[i][j] = rand() % 20 + (-10);
        }
    }
    cout << "Massiv A:" << endl; // Вывод двумерного массива
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << setw(9) << a[i][j] << " ";
        }
            cout << endl;
    } 
    for (i = 0; i < n; i++)
    { 
        imin = jmax = 0;
        // Поиск индексов максимального элемента массива
        for (j = 0; j < m; j++)
        {
            if (a[i][j] > a[i][jmax])
            {
                jmax = j; 
            }
        }
        //cout << "максимальный элемент в строке " << i << " с индексом " << jmax << " = " << a[i][jmax] << endl;
        // jmax - найденый номер столбца
        for (int i = 0; i < n; i++)
        {
            if (a[i][jmax] < a[imin][jmax])
            {
                imin = i;  //номер строки в которой найден минимальный элемент
            }
        }
        //cout << "минимальный элемент в столбце " << jmax << " с индексом " << imin << " = " << a[imin][jmax] << endl;
            if (i == imin)
                cout << "седловая точка - a[" << i << "][" << jmax << "] = " << a[i][jmax] << endl;
    }
    for (i = 0; i < n; i++)
        // Освобождение выделенной памяти
        delete[] a[i];
    delete[]a; //освобождение массива
    //delete a;
    return 0;
}
int zadanie2()
{
        //Объявить динамический массив A из n(n < 10) числа целочисленных
        //положительных элементов.Инициализацию массива выполнить с помощью
        //генератора случайных чисел.После инициализации должна быть возможность
        //добавления элемента массива со значением X перед i - м элементом.Для
        //обращение к элементам массива использовать указатель.
    int *a, n, w;
    cout << "Введите размер массива: n" << endl;
    cin >> n;
    a = new int [n];
    for (int i = 0; i < n; i++)
    {
            a[i] = rand() % 10;
    }
    cout << "Исходный массив: " << endl; // Вывод массива
    for (int i = 0; i < n; i++)
    {
            cout << a[i] << " ";  
    }
    cout << endl;
    cout << "хотите добавить элемент массива(1 - да, 0 - нет): ";
    cin >> w;
    if (w == 1)
    {
        cout << "Введите перед каким элементом хотите вставить: ";
        int index, x, *new_array;
        cin >> index;
        if (index < 0)
            index = 0;
        if (index > n + 1)
        {
            index = n;
        }
        cout << "Введите значение: ";
        cin >> x;
        new_array = new int[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            if (i == index)
                new_array[i] = x;
            if (i < index)
                new_array[i] = a[i];
            if (i > index)
                new_array[i] = a[i - 1];
        }
        cout << "Конечный массив: " << endl; // Вывод массива
        for (int i = 0; i < n + 1; i++)
        {
            cout << new_array[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
int main()
{
    while (1)
    {
        setlocale(LC_ALL, "Russian");
        int x;
        cout << "введите номер упражнения (1-2): ";
        cin >> x;
        switch (x)
        {
        case 1: zadanie1(); break; // break выходит за фигурные скобки (обрывает цикл)
        case 2: zadanie2(); break; // break выходит за фигурные скобки (обрывает цикл)
        default: return 0;
        }
    }
}