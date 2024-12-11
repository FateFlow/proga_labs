#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

double celsiusToFahrenheit(double celsius) {
    return celsius * 1.8 + 32;
}

int main() {
    setlocale (LC_ALL, "RUSSIAN");
    std::string input;
    std::cout << "Введите температуру (например, 59 F или 15 C): ";
    std::getline(std::cin, input);

    std::stringstream ss(input);
    double value;
    char unit;
    ss >> value >> unit;

    if (unit == 'F' || unit == 'f') {
        double celsius = fahrenheitToCelsius(value);
        std::cout << std::fixed << std::setw(10) << std::setprecision(4) << std::setfill('\\') << celsius << " C" << std::endl;
    }
    else if (unit == 'C' || unit == 'c') {
        double fahrenheit = celsiusToFahrenheit(value);
        std::cout << std::fixed << std::setw(10) << std::setprecision(4) << std::setfill('\\') << fahrenheit << " F" << std::endl;
    }
    else {
        std::cerr << "Некорректная единица измерения!" << std::endl;
    }

    return 0;
}
