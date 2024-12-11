#pragma once

template <typename T>
class SmartPointer {
private:
    T* ptr;
public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}
    ~SmartPointer() { delete ptr; }

    // Конструктор копирования
    SmartPointer(const SmartPointer& other) {
        ptr = other.ptr ? new T(*other.ptr) : nullptr;
    }

    // Оператор присваивания копированием
    SmartPointer& operator=(const SmartPointer& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr ? new T(*other.ptr) : nullptr;
        }
        return *this;
    }

    // Конструктор перемещения
    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Оператор присваивания перемещением
    SmartPointer& operator=(SmartPointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    T* get() const { return ptr; }
    void reset(T* p = nullptr) { delete ptr; ptr = p; }
};
