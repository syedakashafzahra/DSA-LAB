#pragma once
#include <iostream>

template <typename T>
class Deque {
private:
    T* arr;
    int rear, front, count, maxDeque;

public:
    Deque(int max);
    ~Deque();
    bool isFull() const;
    bool isEmpty() const;
    void insertleft(T item);
    void removeleft(T& item);
    void insertright(T item);
    void removeright(T& item);
    void display() const;
};