#include "Que3.h"
using namespace std;

template <typename T>
Deque<T>::Deque(int max) {
    maxDeque = max;
    arr = new T[maxDeque];
    front = -1;
    rear = -1;
    count = 0;
}

template <typename T>
Deque<T>::~Deque() {
    delete[] arr;
}

template <typename T>
bool Deque<T>::isFull() const {
    return count == maxDeque;
}

template <typename T>
bool Deque<T>::isEmpty() const {
    return count == 0;
}

// Insert element at left end (Front)
template <typename T>
void Deque<T>::insertleft(T item) {
    if (isFull()) {
        cout << "Deque Overflow! Cannot insert " << item << endl;
        return;
    }
    if (front == -1) {  // First element insertion
        front = rear = 0;
    }
    else if (front == 0) {
        front = maxDeque - 1;  // Wrap around
    }
    else {
        front--;
    }
    arr[front] = item;
    count++;
}

// Insert element at right end (Rear)
template <typename T>
void Deque<T>::insertright(T item) {
    if (isFull()) {
        cout << "Deque Overflow! Cannot insert " << item << endl;
        return;
    }
    if (rear == -1) {  // First element insertion
        front = rear = 0;
    }
    else if (rear == maxDeque - 1) {
        rear = 0;  // Wrap around
    }
    else {
        rear++;
    }
    arr[rear] = item;
    count++;
}

// Remove element from left end (Front)
template <typename T>
void Deque<T>::removeleft(T& item) {
    if (isEmpty()) {
        cout << "Deque Underflow! Cannot remove from left.\n";
        return;
    }
    item = arr[front];
    if (front == rear) {  // Only one element
        front = rear = -1;
    }
    else if (front == maxDeque - 1) {
        front = 0;  // Wrap around
    }
    else {
        front++;
    }
    count--;
}

// Remove element from right end (Rear)
template <typename T>
void Deque<T>::removeright(T& item) {
    if (isEmpty()) {
        cout << "Deque Underflow! Cannot remove from right.\n";
        return;
    }
    item = arr[rear];
    if (front == rear) {  // Only one element
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = maxDeque - 1;  // Wrap around
    }
    else {
        rear--;
    }
    count--;
}

// Display deque contents
template <typename T>
void Deque<T>::display() const {
    if (isEmpty()) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Deque elements: ";
    int index = front;
    for (int i = 0; i < count; i++) {
        cout << arr[index] << " ";
        index = (index + 1) % maxDeque;
    }
    cout << endl;
}

// Explicit instantiation of the template for int type
template class Deque<int>;