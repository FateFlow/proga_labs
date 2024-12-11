#include <iostream>
#include <initializer_list>

namespace containers {

    template <typename T>
    class DList {
    private:
        struct Node {
            T value;
            Node* prev;
            Node* next;

            Node(const T& val, Node* p = nullptr, Node* n = nullptr)
                : value(val), prev(p), next(n) {}
        };

        Node* head;
        Node* tail;
        size_t size;

    public:
        // Конструктор по умолчанию
        DList() : head(nullptr), tail(nullptr), size(0) {}

        // Конструктор от std::initializer_list<T>
        DList(std::initializer_list<T> initList) : DList() {
            for (const T& item : initList) {
                addToEnd(item);
            }
        }

        // Конструктор копирования
        DList(const DList& other) : DList() {
            Node* current = other.head;
            while (current) {
                addToEnd(current->value);
                current = current->next;
            }
        }

        // Копирующий оператор присваивания
        DList& operator=(const DList& other) {
            if (this != &other) {
                clear();
                Node* current = other.head;
                while (current) {
                    addToEnd(current->value);
                    current = current->next;
                }
            }
            return *this;
        }

        // Конструктор перемещения
        DList(DList&& other) noexcept : head(other.head), tail(other.tail), size(other.size) {
            other.head = other.tail = nullptr;
            other.size = 0;
        }

        // Перемещающий оператор присваивания
        DList& operator=(DList&& other) noexcept {
            if (this != &other) {
                clear();
                head = other.head;
                tail = other.tail;
                size = other.size;
                other.head = other.tail = nullptr;
                other.size = 0;
            }
            return *this;
        }

        // Деструктор
        ~DList() {
            clear();
        }

        // Операция индексирования
        T& operator[](size_t index) {
            Node* current = head;
            for (size_t i = 0; i < index && current != nullptr; ++i) {
                current = current->next;
            }
            if (current) {
                return current->value;
            }
            throw std::out_of_range("Index out of range");
        }

        // Метод добавления элемента в конец
        void addToEnd(const T& value) {
            Node* newNode = new Node(value, tail, nullptr);
            if (tail) {
                tail->next = newNode;
            }
            else {
                head = newNode;
            }
            tail = newNode;
            ++size;
        }

        // Метод удаления элемента из конца
        void removeFromEnd() {
            if (tail) {
                Node* toDelete = tail;
                tail = tail->prev;
                if (tail) {
                    tail->next = nullptr;
                }
                else {
                    head = nullptr;
                }
                delete toDelete;
                --size;
            }
        }

        // Очистка списка
        void clear() {
            while (head) {
                removeFromEnd();
            }
        }

        // Получение размера списка
        size_t getSize() const {
            return size;
        }

        // Вывод списка
        void print() const {
            Node* current = head;
            while (current) {
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    };

} // namespace containers

int main() {
    containers::DList<int> intList = { 1, 2, 3, 4, 5 };
    intList.print();
    intList.addToEnd(6);
    intList.print();
    intList.removeFromEnd();
    intList.print();

    containers::DList<double> doubleList = { 1.1, 2.2, 3.3 };
    doubleList.print();

    containers::DList<std::string> stringList = { "Hello", "World" };
    stringList.print();
    stringList.addToEnd("!");
    stringList.print();

    return 0;
}
