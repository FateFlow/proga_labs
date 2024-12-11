#include <iostream>
#include <cmath> 
using namespace std;

class Double {
private:
    int integer;
    int fraction;

public:
    Double(int integer = 0, int fraction = 0) {
        this->integer = integer;
        this->fraction = fraction;
    }

    int getinteger() const {
        return integer;
    }

    int getfraction() const {
        return fraction;
    }

    void setinteger(int new_integer) {
        integer = new_integer;
    }

    void setfraction(int new_fraction) {
        fraction = new_fraction;
    }

    void init(int integer, int fraction) {
        this->integer = integer;
        this->fraction = fraction;
    }

    void read() {
        cout << "Введите целую часть: ";
        cin >> integer;
        cout << "Введите дробную часть: ";
        cin >> fraction;
    }

    void display() {
        cout << integer << "." << fraction << endl;
    }

    Double add(Double& other) const {
        int new_integer = this->integer + other.getinteger();
        int new_fraction = this->fraction + other.getfraction();
        if (new_fraction >= 100) {
            new_integer += new_fraction / 100;
            new_fraction %= 100;
        }
        return Double(new_integer, new_fraction);
    }

    Double subtract(Double& other) const {
        int new_integer = this->integer - other.getinteger();
        int new_fraction = this->fraction - other.getfraction();
        if (new_fraction < 0) {
            new_integer--;
            new_fraction += 100;
        }
        return Double(new_integer, new_fraction);
    }

    //Double power(int exponent) const {
    //    double value = this->integer + this->fraction / 100.0;
    //    value = pow(value, exponent);
    //    int new_integer = (int)value;
    //    int new_fraction = (value - new_integer) * 100;
    //    return Double(new_integer, new_fraction);
    //}
};

int main() {
    setlocale(LC_ALL, "RUS");
    Double num1, num2;
    num1.read();
    num2.read();
    Double sum = num1.add(num2);
    Double difference = num1.subtract(num2);

   //int temp;
   //cout << "Введите степень для возведения: ";
   //cin >> temp;
   //Double result = num1.power(temp);
   
    cout << "Сумма: ";
    sum.display();

    cout << "Разность: ";
    difference.display();

   //cout << "Число, возведенное в степень " << temp << ": ";
   //result.display();

    return 0;
}
