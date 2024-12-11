//Создать класс Time для работы со временем в формате
//«час : минута:секунда».Класс должен включать в себя три конструктора
//инициализации : числами, строкой(например, «23:59 : 59»), секундами.
//Конструктор инициализации тремя числами должен присваивать значения по
//умолчанию минутам и секундам.Реализовать операции вычисления разницы
//между двумя моментами времени в секундах, сложения времени и заданного
//количества секунд, вычитания из времени заданного количества секунд,
//сравнения моментов времени.Реализовать функцию преобразования в строку
//toStrlng().Метод вычисления разности двух моментов времени реализовать как
//перегруженную операцию operator-, а метод, вычисляющий время через
//заданное количество минут, — как перегруженную операцию сложения
//operator+.Для вывода значения времени на экран реализовать дружественную
//функцию operators.
#include <iostream>
#include <string>
#include <sstream>

class Time {
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    // Конструктор, который принимает строку времени в формате "hh:mm:ss"
    Time(const std::string& time) {
        std::stringstream ss(time);
        char ignore;
        ss >> hours >> ignore >> minutes >> ignore >> seconds;
    }

    // Статическая функция для создания объекта Time из общего количества секунд
    static Time fromSeconds(int totalSeconds) {
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }

    // Функция для преобразования времени в секунды
    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // Функция для преобразования времени в строку
    std::string toString() const {
        std::stringstream ss;
        ss << hours << ":" << minutes << ":" << seconds;
        return ss.str();
    }

    // Оператор минус для вычитания двух объектов Time
    Time operator-(const Time& other) const {
        int diff = this->toSeconds() - other.toSeconds();
        return Time(diff);
    }

    // Оператор плюс для добавления секунд к объекту Time
    Time operator+(int extraSeconds) const {
        int total = this->toSeconds() + extraSeconds;
        return Time(total);
    }

    // Оператор минус для вычитания секунд из объекта Time
    Time operator-(int lessSeconds) const {
        int total = this->toSeconds() - lessSeconds;
        return Time(total);
    }

    // Дружественная функция для вывода объекта Time
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

// Функция для вывода объекта Time
std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.toString();
    return os;
}

int main() {
    setlocale(LC_ALL, "RUSSAIN");
    Time t1(23, 59, 59);
    Time t2("12:34:56");
    Time t3 = t1 - t2;
    Time t4 = t2 + 3600;
    Time t5 = t2 - 3600; 
    Time t6 = Time::fromSeconds(3600); // Создание объекта Time из секунд


    std::cout << "t1: " << t1 << "\n";
    std::cout << "t2: " << t2 << "\n";
    std::cout << "t3 (t1 - t2): " << t3 << "\n";
    std::cout << "t4 (t2 + 3600 seconds): " << t4 << "\n";
    std::cout << "t6 (t2 - 3600 seconds): " << t5 << "\n";  

    if (t4.toSeconds() > t5.toSeconds()) {
        std::cout << "t4 > t5.\n";
    }
    else if (t4.toSeconds() < t5.toSeconds()) {
        std::cout << "t4 < t5.\n";
    }
    else {
        std::cout << "t4 = t5.\n";
    }

    return 0;
}
