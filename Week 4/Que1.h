#define maxQue 100
typedef int itemtype;
class Queue {
private:
    itemtype items[maxQue];
    int front, rear, count;
public:
    Queue();
    int Isempty();
    int Isfull();
    void insert(itemtype newitem);
    void remove(itemtype& item);
};