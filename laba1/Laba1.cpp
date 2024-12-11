#include <iostream>

int zadanie5()
{
	int a, b;
	std::cout << "input a:";
	std::cin >> a;
	std::cout << "input b:";
	std::cin >> b;
	std::cout << std::boolalpha << ((a >= 0) || (b < -2));
	return 0;
}
int zadanie4()
{
	int x;
	std::cout << "input two-digit number: ";
	std::cin >> x;
	//if ((x > 9) && (x < 100)) 
	std::cout << x << "-->" << (x % 10) << (x / 10) << '\n';
	//else
	//std::cout << x << "is not two-digit number!\n";
	return 0;
}
int zadanie2()
{
	int x = 2, y = 1;
	std::cout << "(!(x*y <0) && (y>x)) where x = 2, y = 1 is ";
	std::cout << std::boolalpha << (!(x * y < 0) && (y > x));
	x = 2;
	y = -2;
	std::cout << "\n((x >= 2) || (y*2 !=5)) where x = 2, y = -2 is ";
	std::cout << std::boolalpha << ((x >= 2) || (y * 2 != 5));
	return 0;
}
int zadanie1()
{
	float a = 0., b = 0.;
	std::cout << "input a: ";
	std::cin >> a;
	std::cout << "input b: ";
	std::cin >> b;
	std::cout << "a= " << a << "\tb= " << b << '\n';
	std::cout << "a + b = " << a + b << '\n';
	std::cout << "a - b = " << a - b << '\n';
	std::cout << "a * b = " << a * b << '\n';
	if (b)
		std::cout << "a / b = " << a / b << '\n';
	else
	    std::cout << "can't divide by zero!";
		return 0;
}
int zadanie3()
{
	const float p = 3.14;
	float R;
	std::cout << "input R: ";
	std::cin >> R;
	std::cout << "Circumference: " << 2 * p * R << '\n';
	std::cout << "Area: " << p * pow(R, 2) << '\n';
	return 0;
}
int main()
{
	int x;
	std::cout << "input exercize number (1-5): ";
	std::cin >> x;
	switch (x)
	{
		case 1: zadanie1(); break; // break выходит за фигурные скобки (обрывает цикл)
		case 2: zadanie2(); break;
		case 3: zadanie3(); break;
		case 4: zadanie4(); break;
		case 5: zadanie5(); break;
		default: std::cout << "wrong number! ";
	}

}