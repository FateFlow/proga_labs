#include <iostream>
using namespace std;

class circle {
    protected:
        double radius;
        double p = 3.14;
    public:
        circle(double r) : radius(r) {}

        double calculateArea() {
            return  p * radius * radius;
        }
        void printInfo() {
            cout << "Поле круга: " << radius << endl;
            cout << "Площадь куга: " << calculateArea() << endl;
        }
};

class shar : public circle {
public: 
    shar(double r) : circle(r) {}

    virtual double colculateVolum() {
        return 4 / (p * radius * radius * radius);
    }

    void printInfo() {
        cout << "Поле шаара: " << radius << endl;
        cout << "Объем шара: " << colculateVolum() << endl;
    }
};
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    circle circle(5.0);
    shar shar(3.0);

    cout << "info circle: " << endl;
    circle.printInfo();
 

    cout << "\ninfo circle: " << endl;
    shar.printInfo();
    

    return 0;
}
