#include "stackT.h"
#include <iostream>
using namespace std;

template <class ItemType>
Stack<ItemType>::Stack() {
    maxStack = 500;
    top = -1;
    items = new ItemType[maxStack](); 
}

template <class ItemType>
Stack<ItemType>::Stack(int max) {
    if (max <= 0) {  
        cout << "Invalid stack size!" << endl;
        exit(1);
    }
    maxStack = max;
    top = -1;
    items = new ItemType[maxStack]();
}

template <class ItemType>
Stack<ItemType>::~Stack() {
    delete[] items;
    items = nullptr; 
}

template <class ItemType>
bool Stack<ItemType>::IsEmpty() const {
    return top < 0; 
}

template <class ItemType>
bool Stack<ItemType>::IsFull() const {
    return top >= maxStack - 1; 
}

template <class ItemType>
void Stack<ItemType>::Push(ItemType newItem) {
    if (IsFull()) {
        cout << "Stack is full, cannot push " << newItem << endl;
        exit(1);
    }
    items[++top] = newItem;
}

template <class ItemType>
void Stack<ItemType>::Pop(ItemType& item) {
    if (IsEmpty()) {
        cout << "Stack is empty, cannot pop an item." << endl;
        exit(1);
    }
    item = items[top--];
}

template <class ItemType>
ItemType Stack<ItemType>::Top() const {
    if (IsEmpty()) {
        cout << "Stack is empty." << endl;
        exit(1);
    }
    return items[top];
}
template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
