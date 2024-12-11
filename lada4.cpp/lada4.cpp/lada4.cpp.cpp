#include <iostream>
using namespace std;
int zadanie1()
{
        // Ввести одномерный массив из n элементов.Вычислить сумму всех  отрицательных чисел,
        // их количество и сумму всех положительных чисел.
    int  n, sum1, sum2, k;
    cout << "Введите размер массива a: " << endl;
    cout << "n = ";
    cin >> n;
    int *a = new int[n];                    // int *a -- (*)-указатель размером int[n]
    cout << "Введите массив a:" << endl;
    sum1 = sum2 = k = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        
        if (a[i] < 0)
        {
            sum1 += a[i];
            k++;
        }
        if (a[i] > 0)
            sum2 += a[i];
    }
    
    cout << "Сумма отрицательных чисел: " << sum1 << endl;
    cout << "Количество отрицательных чисел: " << k << endl;
    cout << "Сумма положительных чисел: " << sum2 << endl;
    delete[] a;     //чистит память
    return 0;
}
int zadanie2()
{
        // Напечатать слово, образованное четными элементами каждой строки  массива.
    int a[1];
    char size[32] = {'а','п','з','р','б','о','л','г','п','р','с','а','в','м','й','м','г','и','о','р','ф','о','с','в','я','а','ч','н','л','и','д','е'};
    cout << endl;
    for (int i = 0; i < 32; i++)
    {
        cout << size[i] << ',';
    }
    cout << endl;
    for (int i = 1; i < 32; i += 2)
        cout << size[i];
    cout << endl;
    return 0;
}
int zadanie3()
{
    //Необходимо заполнить двухмерный массив из 0 и 1. 
    //А после его  вывода – массив должен иметь следующий вид :
        //0 1 0 1
        //1 0 1 0
        //0 1 0 1
        //1 0 1 0
    //При изменении размеров массива принцип его заполнения должен сохраняться
    int  N = 4;
    cout << "Введите размер массива a: " << endl;
    cout << "N = ";
    cin >> N;
    int** a{ new int* [N] {} };  // выделяем память под двухмерный массив (создаю динамический массив каждыйй элемент которого является массивом с указателями) 
    for (unsigned i{}; i < N; i++) //заполняю каждый элемент массива с указателем 
    {
        a[i] = new int[N] {};   //присваюваю новый массив каждому элеманту (a)
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if ((i + j) % 2 == 0)
                a[i][j] = 0;
            else
                a[i][j] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    for (unsigned i{}; i < N; i++) //unsigned это int без отрцатльных значений
    {
        delete[] a[i];
    }
    delete[] a;     //убираю рзервирование опративной памяти
    return 0;
}
int zadanie4()
{
    //Задан массив из k чисел.Найти число, наиболее часто встречающееся в этом массиве.
    int n, max = 0, c;
    cout << "Введите размер массива a: " << endl;
    cout << "n = ";
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) 
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j]) 
            {
                count++;
            }
            
        }   
        if (count > max) 
        {
            max = count; 
            c = a[i];
        }
    }
    cout << "the most common number: " << c << " -- " << max << " times" << endl;
    delete[] a;
    return 0;
}
int main()
{
    while (1)
    {
        setlocale(LC_ALL, "Russian");
        int x;
        cout << "введите номер упраднения (1-4): ";
        cin >> x;
        switch (x)
        {
        case 1: zadanie1(); break; // break выходит за фигурные скобки (обрывает цикл)
        case 2: zadanie2(); break;
        case 3: zadanie3(); break;
        case 4: zadanie4(); break;
        default: return 0;
        }
    }
}