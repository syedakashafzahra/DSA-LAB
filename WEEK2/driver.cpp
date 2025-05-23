#include <iostream>
#include <string>
#include "stack.h"
using namespace std;
void reverseString(string& str) {
    Stack s;
    for (char ch : str) {
        if (!s.IsFull()) {
            s.Push(ch);
        }
        else {
            cout << "Stack is full, cannot push " << ch << endl;
            return;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        if (!s.IsEmpty()) {
            char ch;
            s.Pop(ch);
            str[i] = ch;
        }
        else {
            cout << "Stack is empty, cannot pop" << endl;
            return;
        }
    }
}

int main() {
    Stack s;
    int item;
    for (int i = 0; i < 10; i++)
        s.Push(i);
    cout << "Peek element is = " << s.Peek() << endl;
    for (int i = 0; i < 10; i++) {
        s.Pop(item);
        cout << item << endl;
    }
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Original String: " << str << endl;
    reverseString(str);
    cout << "Reversed String: " << str << endl;

    return 0;
}

