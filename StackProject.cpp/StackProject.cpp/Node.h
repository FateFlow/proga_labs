#pragma once

template <typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
    Node(const T& val) : value(val), next(nullptr), prev(nullptr) {}
};
