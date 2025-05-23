#include "Que2.h"
template <typename T>
Queue<T>::Queue() {
    maxQue = 501;
    items = new T[maxQue];
    front = 0;
    rear = 0;
    count = 0;
}
template <typename T>
Queue<T>::Queue(int max) {
    maxQue = max + 1;
    front = 0;
    rear = 0;
    count = 0;
    items = new T[maxQue];
}
template <typename T>
Queue<T>::~Queue() {
    delete[] items;
}
template <typename T>
bool Queue<T>::Isempty() const {
    return count == 0;
}
template <typename T>
bool Queue<T>::Isfull() const {
    return count == maxQue;
}

template <typename T>
void Queue<T>::insert(T newitem) {
    if (Isfull()) {
        cout << "over flow;"
    }
    items[rear] = newitem;
    rear = (rear + 1) % maxQue;
    ++count;
}
template <typename T>
void Queue<T>::remove(T& item) {
    if (Isempty()) {
        cout << "Under flow";

    }
    else {
        item = items[front];
        front = (front + 1) % maxQue;
        --count;
    }
}