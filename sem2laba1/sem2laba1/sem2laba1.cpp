//Создать класс Double, имитирующий стандартный тип double.
//Помимо метода инициализации init(), методов ввода read() и вывода display(),
//реализовать методы сложения и вычитания, а также метод возведения в
//произвольную степень.
#include <iostream>
#include <cmath> 
using namespace std;
class Double {
private:
    double value; 

public:
    Double(double initialValue = 0.0) {
        value = initialValue;
    }
    double get()
    {
        return value;
    }
    void set(double new_value)
    {
        value = new_value;
    }
    //void init() {
    //    cout << "Введите значение: ";
    //    cin >> value;
    //}
   
    //void display() {
    //    cout << "Значение: " << value << std::endl;
    //}

    Double add(Double& other) const {
        return Double(value + other.get());
    }

    Double subtract(Double& other) const {
        return Double(value - other.get());
    }

    Double power(double exponent) const {
        return Double(std::pow(value, exponent));
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    //Double num1, num2;
    //num1.init();
    //num2.init();
    double temp;
    cout << "Введите значение первого числа: ";
    cin >> temp;
    Double num1(temp);
    cout << "Введите значение второго числа: ";
    cin >> temp;
    Double num2(temp);
    Double sum = num1.add(num2);
    Double difference = num1.subtract(num2);

    cout << "Введите степень для возведения: ";
    cin >> temp;
    Double result = num1.power(temp);

    cout << "Сумма: " << sum.get() << endl;

    cout << "Разность: " << difference.get() << endl;

    cout << "Число, возведенное в степень " << temp << ": " << result.get() << endl;

    return 0;
}
