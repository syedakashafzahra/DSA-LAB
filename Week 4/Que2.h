#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* items;
    int front, rear, count, maxQue;
public:
    Queue();
    Queue(int max);
    ~Queue();
    bool Isempty() const;
    bool Isfull() const;
    void insert(T newitem);
    void remove(T& item);
    void display() const;
}