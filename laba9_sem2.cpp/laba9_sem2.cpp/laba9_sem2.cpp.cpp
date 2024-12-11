#include <iostream>
#include <cmath>

class Prisma_Inscrebed_Rectilineal_Triangular {
private:
    double R; // радиус окружности
    double H; // высота призмы
    double a; // сторона треугольника

public:
    Prisma_Inscrebed_Rectilineal_Triangular(double R, double H) : R(R), H(H) {
        a = R * sqrt(3); // сторона треугольника равна двум радиусам окружности
        std::cout << a;
    }

    double base_area() {
        return (a * a) * sqrt(0.75); // S(осн) =a^2*√ 3/4
    }

    double lateral_area() {
        return 3 * a * H; // S(бок) = 3a*H
    }

    double total_area() {
        return 2 * base_area() + lateral_area(); // S(полн)=2S(осн)+S(бок)
    }

    double volume() {
        return base_area() * H; // объем призмы
    }

    double weight(double density) {
        return volume() * density; // вес призмы
    }
};
#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    double R = 5.0; // радиус окружности
    double H = 10.0; // высота призмы
    double density = 7.0; // плотность металла (например, стали)

    Prisma_Inscrebed_Rectilineal_Triangular prisma(R, H);

    std::cout << "Площадь основания: " << prisma.base_area() << std::endl;
    std::cout << "Боковая площадь: " << prisma.lateral_area() << std::endl;
    std::cout << "Полная площадь: " << prisma.total_area() << std::endl;
    std::cout << "Объем: " << prisma.volume() << std::endl;
    std::cout << "Вес: " << prisma.weight(density) << std::endl;

    return 0;
}
