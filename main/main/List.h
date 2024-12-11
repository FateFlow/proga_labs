#pragma once

#include <initializer_list>
#include "Node.h"
#include "SmartPointer.h"
#include "Exception.h"

template <typename T>
class List {
private:
    SmartPointer<Node<T>> head;
    SmartPointer<Node<T>> tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    List(std::initializer_list<T> init_list) : List() {
        for (const T& value : init_list) {
            push_back(value);
        }
    }

    List(const List& other) : List() {
        Node<T>* current = other.head.get();
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }

    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            Node<T>* current = other.head.get();
            while (current) {
                push_back(current->value);
                current = current->next;
            }
        }
        return *this;
    }

    List(List&& other) noexcept : head(std::move(other.head)), tail(std::move(other.tail)), size(other.size) {
        other.size = 0;
    }

    List& operator=(List&& other) noexcept {
        if (this != &other) {
            clear();
            head = std::move(other.head);
            tail = std::move(other.tail);
            size = other.size;
            other.size = 0;
        }
        return *this;
    }

    ~List() { clear(); }

    void push_back(const T& value) {
        SmartPointer<Node<T>> new_node(new Node<T>(value));
        if (!tail.get()) {      //если список пуст то 
            // узел становится и головой, и хвостом списка.

            head = std::move(new_node);
            tail = head;
        }
        else {
            tail->next = new_node.get();
            new_node->prev = tail.get();
            tail = std::move(new_node);
        }
        ++size;
    }

    void pop_back() {
        if (!tail.get()) throw Exception("List is empty");
        if (tail->prev) {
            tail = SmartPointer<Node<T>>(tail->prev);
            tail->next = nullptr;
        }
        else {
            tail.reset();       //Сбрасывается указатель tail (становится nullptr).
            head.reset();
        }
        --size;
    }

    T& back() {
        if (!tail.get()) throw Exception("List is empty");
        return tail->value;
    }

    const T& back() const {
        if (!tail.get()) throw Exception("List is empty");
        return tail->value;
    }

    bool isEmpty() const { return size == 0; }
    size_t getSize() const { return size; }

    void clear() {
        while (tail.get()) {
            pop_back();
        }
    }
};