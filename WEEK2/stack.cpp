#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

Stack::Stack() {
    top = -1;
}

int Stack::IsEmpty() const {
    return (top == -1);
}

int Stack::IsFull() const {
    return (top == Max_ITEMS - 1);
}

void Stack::Push(ItemType newItem) {
    if (IsFull()) {
        cout << "Stack is full" << endl;
        exit(1);
    }
    top++;
    items[top] = newItem;
}

void Stack::Pop(ItemType& item) {
    if (IsEmpty()) {
        cout << "Stack is empty, cannot pop an item.";
        return;
    }
    item = items[top];
    top--;
}

ItemType Stack::Peek() const {
    if (IsEmpty()) {
        cout << "Stack is empty, cannot peek an item.";
        exit(1);
    }
    return items[top];
}
