#include "exercises.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Queue<string> q;
    string name;
    q.insert("almas");
    q.insert("ayesha");
    q.insert("Rabia");
    q.insert("bushra");
    q.insert("Iqra");
    q.insert("Aqsa");
    q.insert("Zahid");
    q.insert("fatima");
    q.insert("shabana");
    q.insert("onija");

    cout << "Removed names: ";
    while (!q.Isempty()) {
        q.remove(name);
        cout << name << " ";
    }

    cout << endl;
    return 0;
}