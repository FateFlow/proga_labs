	#include <iostream>
	#include <cstdio>
	#include <math.h>
	int zadanie1()
	{
		//Вычислить стоимость покупки с учетом скидки. Скидка в 10%
		//предоставляется, если сумма покупки превышает 1000 рублей.
		 float a, b = (10.0/100);
		std::cout << "input the purchase amount: ";
		std::cin >> a;
		if ((a < 1000))
			std::cout << "you don't get a discount!\n";
		else
		{
			std::cout << "your discounted purchase price: " << a - (a * b);
		}
		return 0;
	}
	int zadanie2()
	{
		//3. Для двух веденных чисел R и a определить, может ли
		//равносторонний треугольник со стороной a быть описан окружностью с
		//радиусом R
		int R, a;
		std::cout << "input R: ";
		std::cin >> R;
		std::cout << "input a: ";
		std::cin >> a;
		if  (R > a / sqrt(3))
			std::cout << "can ";
		else 
			std::cout << "can not ";
		return 0;
	}
	int main()
	{
		int x;
		std::cout << "input exercize number (1-5): ";
		std::cin >> x;
		switch (x)
		{
		case 1: zadanie1(); break;
		case 2: zadanie2(); break;
		default: std::cout << " wrong number! ";
		}
	}