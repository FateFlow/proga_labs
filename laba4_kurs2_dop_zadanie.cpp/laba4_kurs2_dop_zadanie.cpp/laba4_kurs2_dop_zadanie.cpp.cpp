#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void generateInputFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Не удалось открыть файл для записи!" << std::endl;
        return;
    }

    std::srand(std::time(0));
    for (int i = 0; i < 100; ++i) {
        int randomNum = std::rand() % 101 - 50;
        outFile << randomNum << std::endl;
    }

    outFile.close();
}

void processFiles(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inFile(inputFilename);
    if (!inFile) {
        std::cerr << "Не удалось открыть входной файл!" << std::endl;
        return;
    }

    std::vector<int> numbers;
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }
    inFile.close();

    int maxNumber = *std::max_element(numbers.begin(), numbers.end());

    std::ofstream outFile(outputFilename);
    if (!outFile) {
        std::cerr << "Не удалось открыть выходной файл!" << std::endl;
        return;
    }

    for (int number : numbers) {
        outFile << (number - maxNumber) << std::endl;
    }

    outFile.close();
}

int main() {
    setlocale (LC_ALL, "RUSSIAN");
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    generateInputFile(inputFilename);
    processFiles(inputFilename, outputFilename);

    std::cout << "Файлы обработаны." << std::endl;

    return 0;
}
