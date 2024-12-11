﻿#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;

// Функция, которая проверяет, является ли символ оператором
bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Функция, которая выполняет арифметическую операцию над двумя операндами
double perform_operation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default: return 0; // Недопустимый оператор
    }
}

// Функция, которая возвращает приоритет оператора
int priority(char c) {
    switch (c) {
    case '^': return 3; // возведение в степень имеет наивысший приоритет
    case '*': case '/': return 2; // умножение и деление имеют средний приоритет
    case '+': case '-': return 1; // сложение и вычитание имеют наименьший приоритет
    default: return 0; // скобки имеют нулевой приоритет
    }
}

// Функция, которая преобразует инфиксную запись в ОПЗ
string infix_to_postfix(string infix) {
    string postfix = ""; // строка для хранения ОПЗ
    stack<char> s; // стек для хранения операторов
    for (char c : infix) { // для каждого символа в исходном выражении
        if (isdigit(c) || c == ',') { // если символ является цифрой или точкой
            postfix += c; // добавить его в конец строки ОПЗ
        }
        else if (c == '(') { // если символ является открывающей скобкой
            s.push(c); // поместить его в стек
        }
        else if (c == ')') { // если символ является закрывающей скобкой
            postfix += ' '; // добавить пробел в конец строки ОПЗ
            while (!s.empty() && s.top() != '(') { // пока стек не пуст и на вершине не открывающая скобка
                postfix += s.top(); // добавить оператор на вершине стека в конец строки ОПЗ
                postfix += ' '; //x += y __ x = x + y
                s.pop(); // удалить оператор из стека
            }
            if (!s.empty() && s.top() == '(') { // если стек не пуст и на вершине открывающая скобка
                s.pop(); // удалить ее из стека
            }
        }
        else if (is_operator(c)) { // если символ является оператором
            postfix += ' '; // добавить пробел в конец строки ОПЗ
            while (!s.empty() && priority(c) <= priority(s.top())) { // пока стек не пуст и приоритет текущего оператора не выше приоритета оператора на вершине стека
                postfix += s.top(); // добавить оператор на вершине стека в конец строки ОПЗ
                postfix += ' ';
                s.pop(); // удалить оператор из стека
            }
            s.push(c); // поместить текущий оператор в стек
        }
    }
    while (!s.empty()) { // пока стек не пуст
        postfix += ' '; // добавить пробел в конец строки ОПЗ
        postfix += s.top(); // добавить оператор на вершине стека в конец строки ОПЗ
        s.pop(); // удалить оператор из стека
    }
    return postfix; // вернуть строку ОПЗ
}
// Функция, которая вычисляет значение выражения в ОПЗ
    double evaluate_rpn(string rpn) {
    stack<double> stack; // Стек для хранения операндов
    stringstream ss(rpn); // Поток для чтения ОПЗ
    string token; // Строка для хранения очередного токена
    while (ss >> token) {
        // Читаем очередной токен из ОПЗ
        if (is_operator(token[0])) {
            // Если токен - оператор, то выталкиваем два операнда из стека
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            // Выполняем операцию и кладем результат в стек
            stack.push(perform_operation(a, b, token[0]));
        }
        else {
            // Если токен - операнд, то преобразуем его в число и кладем в стек
            stack.push(stod(token)); //stod - string_to_double
        }
    }
    return stack.top(); // Возвращаем результат из стека
}

// Функция, которая заменяет переменные в выражении на их значения
string substitute_variables(string expression, double a, double b, double c, double d, double e) {
    string result = "";
    for (char h : expression) {
        switch (h) {
        case 'a': result += to_string(a); break;
        case 'b': result += to_string(b); break;
        case 'c': result += to_string(c); break;
        case 'd': result += to_string(d); break;
        case 'e': result += to_string(e); break;
        default: result += h; break;
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Вводим выражение в инфиксной нотации
    string expression = "a-(b+c*d)/e";
    // Вводим значения переменных
    double a = 3.1, b = 5.4, c = 0.2, d = 9.6, e = 7.8;
    // Заменяем переменные на их значения
    expression = substitute_variables(expression, a, b, c, d, e);
    // Преобразуем выражение в ОПЗ
    string rpn = infix_to_postfix(expression);
    // Вычисляем значение выражения в ОПЗ
    double value = evaluate_rpn(rpn);
    cout << "Выражение в инфиксной нотации: " << expression << endl;
    cout << "Выражение корректно" << endl;
    cout << "Выражение в обратной польской записи: " << rpn << endl;
    cout << "Значение выражения: " << value << endl;
    return 0;
}