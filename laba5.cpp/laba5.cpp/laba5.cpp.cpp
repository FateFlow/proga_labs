#include <iostream>
using namespace std;
int zadanie1()
{
    int t, n, m;
    cout << "введите размерность матрицы a(n*m): " << endl;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    for (t = 1; t > 0; t++)
    {
        t = n * m;
        cout << "разметроность матрицы a: " << t << endl;
        break;
    }
    int* a = new int[t];
    for (int i = 0; i < t; i++)
    {
        a[i] = rand() % 20 + (-10);
        cout << a[i] << ", ";
    }
    cout << endl;
    delete[] a;
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
        default: return 0;
        }
    }
}