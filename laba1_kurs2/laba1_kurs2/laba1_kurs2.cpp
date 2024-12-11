#include <iostream>
#include <cmath>
#include <string>
#include <exception>

// Класс для пользовательского исключения
class CustomException : public std::exception {
private:
    std::string error_message;
    double value;
    int code;
public:
    CustomException(const std::string& msg, double val, int errCode)
        : error_message(msg), value(val), code(errCode) {}

    const char* what() const noexcept override {
        return error_message.c_str();
    }

    double getValue() const {
        return value;
    }

    int getCode_of_error() const {
        return code;
    }
};

// Функция для вычисления Z1
void calculate_z1(double& z1, double m) {
    try {
        if (m < 0) {
            throw CustomException("Ошибка: m не может быть отрицательным.", m, 1);
        }
        double numerator = sqrt(pow((3 * m + 2), 2) - (24 * m));
        double denominator = (3 * sqrt(m)) - (2 / sqrt(m)); 
        if (denominator == 0) {
            throw CustomException("Ошибка: деление на ноль.", denominator, 2);
        }
        z1 = numerator / denominator;
    }
    catch (const CustomException& e) {
        std::cerr << "Исключение: " << e.what() << " Значение: " << e.getValue() << " Код ошибки: " << e.getCode_of_error() << std::endl;
        z1 = NAN; // Устанавливаем z1 в NaN в случае ошибки
    }
}

// Функция для вычисления Z2
void calculate_z2(double& z2, double m) {
    try {
        if (m < 0) {
            throw CustomException("Ошибка: m не может быть отрицательным.", m, 1);
        }
        z2 = -sqrt(m);
    }
    catch (const CustomException& e) {
        std::cerr << "Исключение: " << e.what() << " Значение: " << e.getValue() << " Код ошибки: " << e.getCode_of_error() << std::endl;
        z2 = NAN; // Устанавливаем z2 в NaN в случае ошибки
    }
}

int main() {
    setlocale(0, "russian");
    double m = 4.0; // Положительное значение m
    double z1, z2;
    calculate_z1(z1, m);
    calculate_z2(z2, m);
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;
    return 0;
}
