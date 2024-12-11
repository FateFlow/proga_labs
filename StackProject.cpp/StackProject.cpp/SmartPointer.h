#pragma once

template <typename T>
class SmartPointer {
private:
    T* ptr;
public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}
    ~SmartPointer() { delete ptr; }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    T* get() const { return ptr; }
    void reset(T* p = nullptr) { delete ptr; ptr = p; }

    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;
};