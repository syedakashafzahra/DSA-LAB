int Queue::Isempty() {
    return (count == 0);
}
int Queue::Isfull() {
    return (count == maxQue);
}
void Queue::insert(itemtype newitem) {
    if (Isfull()) {
        cout << "over flow";
    }
    else {
        items[rear] = newitem;
        rear = (rear + 1) % maxQue;
        ++count;
    }
}
void Queue::remove(itemtype& item) {
    if (Isempty()) {
        cout << "under flow";
    }
    else {
        item = items[front];
        front = (front + 1) % maxQue;
        --count;
    }
}