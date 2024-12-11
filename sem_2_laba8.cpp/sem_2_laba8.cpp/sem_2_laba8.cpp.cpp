//Создать базовый класс «Квадрат».Элементы класса : поле, задающее
//длину стороны(статус доступа protected); конструктор для инициализации
//поля; функция для вычисления площади квадрата; функция для печати поля и
//площади квадрата.Создать производный класс «Куб».Элементы класса :
//конструктор для инициализации поля; функция для вычисления 
// объема(вместо площади) куба.Создать по одному объекту
//каждого из классов.Показать вызов созданных функций.При переопределении
//функций обеспечить динамический полиморфизм, показать его особенности в
//программе.
#include <iostream>
using namespace std;
class Square {
protected:
    double side;

public:
    Square(double s) : side(s) {}

    double calculateArea() {
        return side * side;
    }

    void printInfo() {
        cout << "Длина стороны квадрата: " << side << endl;
        cout << "Площадь квадрата: " << calculateArea() << endl;
    }
};

class Cube : public Square {
public:
    Cube(double s) : Square(s) {}

    virtual double calculateVolume() {
        return side * side * side;
    }

    void printInfo()  {
        cout << "Длина стороны куба: " << side << endl;
        cout << "Объем куба: " << calculateVolume() << endl;
    }
};

int main() {
    setlocale (LC_ALL, "RUS");

    Square square(5.0);
    Cube cube(3.0);

    cout << "Информация о квадрате:" << endl;   
    square.printInfo();

    cout << "\nИнформация о кубе:" << endl;
    cube.printInfo();



    return 0;
}
