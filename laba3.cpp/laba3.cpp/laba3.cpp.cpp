#include <iostream>
#include <iomanip>
#define M_E    2.71828182845904523536
#define M_PI 3.14159265358979323846
#include <cmath>
using namespace std;
int zadanie1()
{
        // Дано вещественное число — цена 1 кг конфет.Вывести стоимость
        // 1.2, 1.4, ..., 2 кг конфет.
    setlocale(LC_ALL, "Russian");
    double x;
    std::cout << "введите цену за 1 кг: " << '\n';
    std::cin >> x;
    double c;   //конечная цена
    for (double i = 1.2; i < 2.1; i += 0.2)     //Оператор сложения с присваиванием ( += )
    {
        c = x * i;
        std::cout << "Стоимость " << i << " кг конфет: " << c << '\n';
    }
    return 0;
}
int zadanie2()
{
    // Даны целые положительные числа N и K. Используя только
    // операции сложения и вычитания, найти частное от деления на цело N на K, а
    // так же остаток от этого деления.
    int n, k, c, count = 0;
    cout << "ввеедите n: ";
    cin >> n;
    cout << "введите k: ";
    cin >> k;
    c = n;
    while (c > k)  // while - цикл пока, выполняется бесконечно (пока в условии истино)
    {
        c -= k;    // (c -= k) тоже, что с = с - k      
        count++;   // (count++) тоже, что count = count + 1

    }
    cout << "частное от делния: " << count << '\n';
    cout << "остаток от деления: " << c;
    return 0;
}
int zadanie3()
{
    // Дано целое число N(N > 0).Используя операции деления на цело и
    // взятия остатка от деления, найти число, полученное при прочтении числа N
    // справа налево.
    int n;
    cout << "введите целое число n(n > 0): ";
    cin >> n;
    while (n > 0)
    {
        cout << n % 10 ;
        n /= 10;
    }
    return 0;
}
long double fact(int ii)
{
    long double s = 1;
    for (int i = 1; i <= ii; i++) s *= i;
    return s;
}
int zadanie4()
{
    char fill = '|';
    double a, b, x, s, h, y, n, z;
    a = 0.1; b = 1; n = 120;
    h = (b - a) / 10;
    cout << setw(56) << setfill(fill) << "" << endl;
    cout << setw(15) << "x" << setw(15) << "y" << setw(15) << "s" << string(11, fill) << '\n';
    cout << setw(56) << setfill(fill)  << "" << endl;
    for (x = a; x <= b; x += h)
    {
        z = x * sqrt(2) / 2;
        y = pow(M_E, z) * cos(z);
        s = 1.0;
       
        for (int i = 1; i <= n; i++)
        { 
            s += cos(i * M_PI / 4) / fact(i) * pow(x, i); 
        }
        cout << setw(15) << x << setw(15) << y << setw(15) << s << string(11, fill) << '\n'; //(setw)ширина столбца
    }
    cout << setw(56) << setfill(fill) << "" << endl;
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