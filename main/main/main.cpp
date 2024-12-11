#include <iostream>
#include "List.h"
#include <string>

template <typename T>
void menu() {
    List<T> list;
    int choice;
    T value;

    do {
        std::cout << "1. Push Back\n2. Pop Back\n3. Peek Back\n4. Check if Empty\n5. Get Size\n6. Clear List\n7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to push: ";
            std::cin >> value;
            list.push_back(value);
            break;
        case 2:
            try {
                list.pop_back();
                std::cout << "Popped successfully.\n";
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 3:
            try {
                std::cout << "Top element: " << list.back() << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << (list.isEmpty() ? "List is empty." : "List is not empty.") << std::endl;
            break;
        case 5:
            std::cout << "List size: " << list.getSize() << std::endl;
            break;
        case 6:
            list.clear();
            std::cout << "List cleared.\n";
            break;
        case 7:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
}

int main() {
    int type_choice;
    std::cout << "Select type of list:\n1. int\n2. double\n3. std::string\n";
    std::cin >> type_choice;

    switch (type_choice) {
    case 1:
        menu<int>();
        break;
    case 2:
        menu<double>();
        break;
    case 3:
        menu<std::string>();
        break;
    default:
        std::cout << "Invalid choice.\n";
    }

    return 0;
};