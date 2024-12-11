//Создать класс LongInteger с двумя полями : high и low, 
//представляющими собой старшую и младшую части числа.Реализовать 
//конструкторы инициализации целым любого типа со значениями по умолчанию 
//и строкой цифр.Реализовать методы сравнения на больше и на равенство, а 
//также метод сложения.Реализовать функцию преобразования в строку 
//toString(). 
#include <iostream> 
#include <string> 
#include <format> 
using namespace std;
class LongInteger {
private:
	int high;
	int low;

public:
	// Конструктор по умолчанию 
	LongInteger(int h = 0, int l = 0) : high(h), low(l) {
		if (h < 0 || l < 0) {
			throw std::invalid_argument("Значения должны быть неотрицательными");
		}
		if (l >= 100000)
		{
			throw std::invalid_argument("Младшая часть должна быть меньше 100000");
		}
	}

	int gethigh() const {
		return high;
	}
	int getlow() const {
		return low;
	}

	void sethigh(int new_high) {
		high = new_high;
	}

	void setlow(int new_low) {
		low = new_low;
	}

	void init(int integer, int fraction) {
		this->high = integer;
		this->low = fraction;
	}

	// Метод для чтения данных с клавиатуры 
	void Read() {
		cout << "Введите старшую часть числа: ";
		cin >> high;
		cout << "Введите младшую часть числа: ";
		cin >> low;
	}

	// Метод для вывода данных на экран 
	void Display() const {
		cout << "Старшая часть числа: " << high << std::endl;
		cout << "Младшая часть числа: " << low << std::endl;
	}

	// Метод для сравнения двух чисел 
	bool operator==(const LongInteger& other) const {
		return high == other.high && low == other.low;
	}

	bool operator>(const LongInteger& other) const {
		if (high == other.high) {
			return low > other.low;
		}
		return high > other.high;
	}

	// Метод для сложения двух чисел  
	LongInteger operator+(const LongInteger& other) const {
		int new_high = this->high + other.gethigh();
		int new_low = this->low + other.getlow();
		if (new_low >= 100000)
		{
			new_high += new_low / 100000;
			new_low %= 100000;
		}
		return LongInteger(new_high, new_low);
	}


	// Метод для преобразования числа в строку 
	std::string toString() const {
		return std::to_string(high) + (std::format("{:05}",  low)); //дополняет нулями(переменную переделывает в строку)
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	// Создаем два объекта класса LongInteger 
	LongInteger num1(143, 6);
	LongInteger num2( 34, 84);

	// Выводим их на экран 
	cout << "Первое число. ";
	num1.Display();
	cout << endl;
	cout << "Второе число. ";
	num2.Display();
	cout << endl;

	//LongInteger num1, num2; 

	// Вводим значения с клавиатуры 
	//std::cout << "Введите первое число:\n"; 
	//num1.Read(); 
	//std::cout << "Введите второе число:\n"; 
	//num2.Read(); 
	// 
	//// Выводим их на экран 
	//std::cout << "Первое число: "; 
	//num1.Display(); 
	//cout << endl; 
	//std::cout << "Второе число: "; 
	//num2.Display(); 
	//cout << endl; 

	if (num1 == num2) {
		cout << "Числа равны.\n";
	}
	else if (num1 > num2) {
		cout << "Первое число больше второго.\n" << endl;
	}
	else {
		cout << "Второе число больше первого.\n" << endl;
	}

	// Преобразуем их в строки 
	cout << "Первое число в виде строки: " << num1.toString() << std::endl;
	cout << "Второе число в виде строки: " << num2.toString() << std::endl;
	cout << endl;

	LongInteger sum = num1 + num2;
	cout << "Сумма чисел: ";
	cout << sum.toString();
	cout << endl;

	return 0;
}