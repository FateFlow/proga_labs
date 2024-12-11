	#include <iostream>
	#include <cstdio>
	#include <math.h>
    #include <iomanip>
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
	int zadanie3()
	{
		int minutes, cod;
		//  Написать программу, вычисляющую стоимость междугороднего
		//  телефонного разговора(цена одной минуты определяется расстоянием до
		//  города, в котором находится абонент).Исходными данными для программы
		//	являются код города и продолжительность разговора.Ниже представлен
		//	рекомендуемый вид экрана во время работы программы(данные, введенные
		//	пользователем, и коды некоторых городов выделены полужирным шрифтом).
		//	Вычисление стоимости разговора по телефону.
		//	Город              Код          Цена минуты, руб.
		//	Владивосток        423          2, 2
		//	Москва             095          1, 0
		//	Мурманск           815          1, 2
		//	Самара             846          1, 4
		//	Длительность(целое количество минут) —-> 3
		//	по введенному коду города программа должна выводить сообщение :
	    //  Город: Владивосток Цена минуты : 2.20 руб.Стоимость разговора : 6.60
		//  руб.
		setlocale(LC_ALL, "Russian");
		std::cout << std::setw(19) << std::left << "Город"
			<< std::setw(13) << "Код"
			<< "Цена минуты, руб." << std::endl;
		std::cout << std::setw(19) << "Владивосток"
			<< std::left
			<< std::setw(13) << "423"
			<< "2.2 " << std::endl;
		std::cout << std::setw(19) << "Москва"
			<< std::left
			<< std::setw(13) << "095"
			<< "1.0 " << std::endl;
		std::cout << std::setw(19) << "Мурманск"
			<< std::left
			<< std::setw(13) << "815"
			<< "1.2" << std::endl;
		std::cout << std::setw(19) << "Самара"
			<< std::left
			<< std::setw(13) << "846"
			<< "1.4" << std::endl;
		std::cout << "Длительность(целое количество минут) —-> ";
		std::cin >> minutes;
		std::cout << "Код города --> ";
		std::cin >> cod;
		std::cout << std::setprecision(2); //количество нулей после точки
		switch (cod)
		{
		case 423:
			std::cout << "Город: Владивосток; Цена минуты: 2.2 руб. Стоимость разговора: " 
				<< (minutes * 2.2) << " руб."; break;
		case 95:
			std::cout << "Город: Москва; Цена минуты: 1.0 руб. Стоимость разговора: " 
				<< (minutes * 1.0) << " руб."; break;
		case 815:
			std::cout << "Город: Мурманск; Цена минуты: 1.2 руб. Стоимость разговора: " 
				<< (minutes * 1.2) << " руб."; break;
		case 846:
			std::cout << "Город: Самара; Цена минуты: 1.4 руб. Стоимость разговора: " 
				<< (minutes * 1.4) << " руб."; break;
		default: std::cout << " wrong number! ";
			break;
		}
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
		case 3: zadanie3(); break;
		default: std::cout << " wrong number! ";
		}
	}