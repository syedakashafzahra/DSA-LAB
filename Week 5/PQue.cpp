/*
* #include <iostream>
using namespace std;
template <class ItemType>
class Que {
private:
    int maxQue;
    int front;
    int rear;
    int count;
    ItemType* items;  
public:
   
    Que() {
        maxQue = 501;
        front = 0;
        rear = 0;
        count = 0;
        items = new ItemType[maxQue];
    }

    
    Que(int max) {
        maxQue = max + 1;
        front = 0;
        rear = 0;
        count = 0;
        items = new ItemType[maxQue];
    }
    ~Que() {
        delete[] items;  
    }
    int IsEmpty() const {
        return (count == 0);
    }
    int IsFull() const {
        return (count == maxQue);
    }

    
    void Insert(ItemType newItem) {
        if (IsFull()) {
            cout << "Queue Overflow" << endl;
        }
        else {
            items[rear] = newItem;
            rear = (rear + 1) % maxQue;
            ++count;
        }
    }
    void Remove(ItemType& item) {
        if (IsEmpty()) {
            cout << "Queue Underflow" << endl;
        }
        else {
            item = items[front];
            front = (front + 1) % maxQue;
            --count;
        }
    }
};
template<class ItemType>
class PQue {
public:
    PQue();
    int ISFull() const;
    int ISEmpty() const;
    void Insert(ItemType newItem, int p);
    void Remove(ItemType& item);

private:
    Que<ItemType> pQ[10];  
};
template<class ItemType>
PQue<ItemType>::PQue() {
}
template<class ItemType>
int PQue<ItemType>::ISFull() const {
    for (int i = 0; i < 10; i++) {
        if (!pQ[i].IsFull()) return 0; 

    }
    return 1;
}
template<class ItemType>
int PQue<ItemType>::ISEmpty() const {
    for (int i = 0; i < 10; i++) {
        if (!pQ[i].IsEmpty()) return 0; 
    }
    return 1; 
}
template<class ItemType>
void PQue<ItemType>::Insert(ItemType newItem, int p) {
    if (p < 0 || p > 9) {
        cout << "Invalid priority level. Must be between 0 and 9." << endl;
        return;
    }
    pQ[p].Insert(newItem);
}
template<class ItemType>
void PQue<ItemType>::Remove(ItemType& item) {
    for (int i = 0; i < 10; i++) {
        if (!pQ[i].IsEmpty()) {
            pQ[i].Remove(item);
            return;
        }
    }
    cout << "Priority Queue is empty, nothing to remove." << endl;
}
int main() {
    PQue<string> pq;

    
    pq.Insert("Task A (Priority 5)", 5);
    pq.Insert("Task B (Priority 1)", 1);
    pq.Insert("Task C (Priority 3)", 3);
    pq.Insert("Task D (Priority 0 - Highest)", 0);
    pq.Insert("Task E (Priority 7)", 7);
    pq.Insert("Task F (Priority 2)", 2);

    string item;

    cout << "\nRemoving items in priority order:\n";
    while (!pq.ISEmpty()) {
        pq.Remove(item);
        cout << "Removed: " << item << endl;
    }

    return 0;
}
*/
/*
* #include <iostream>
using namespace std;

template <class ItemType>
class Que {
private:
    int maxQue;
    int front;
    int rear;
    int count;
    ItemType* items;

public:
    Que(int max = 501) {
        maxQue = max + 1;
        front = 0;
        rear = 0;
        count = 0;
        items = new ItemType[maxQue];
    }

    ~Que() {
        delete[] items;
    }

    int IsEmpty() const {
        return (count == 0);
    }

    int IsFull() const {
        return (count == maxQue);
    }

    void Insert(ItemType newItem) {
        if (IsFull()) {
            cout << "Queue Overflow" << endl;
        }
        else {
            items[rear] = newItem;
            rear = (rear + 1) % maxQue;
            ++count;
        }
    }

    void Remove(ItemType& item) {
        if (IsEmpty()) {
            cout << "Queue Underflow" << endl;
        }
        else {
            item = items[front];
            front = (front + 1) % maxQue;
            --count;
        }
    }
};
template<class ItemType>
class PQue {
public:
    PQue(int numLevels);
    ~PQue();

    int ISFull() const;
    int ISEmpty() const;
    void Insert(ItemType newItem, int p);
    void Remove(ItemType& item);

private:
    Que<ItemType>* pQ;
    int numPriorities;
};

template<class ItemType>
PQue<ItemType>::PQue(int numLevels) {
    numPriorities = numLevels;
    pQ = new Que<ItemType>[numPriorities];
}

template<class ItemType>
PQue<ItemType>::~PQue() {
    delete[] pQ;
}
template<class ItemType>
int PQue<ItemType>::ISFull() const {
    for (int i = 0; i < numPriorities; i++) {
        if (!pQ[i].IsFull()) return 0;
    }
    return 1;
}
template<class ItemType>
int PQue<ItemType>::ISEmpty() const {
    for (int i = 0; i < numPriorities; i++) {
        if (!pQ[i].IsEmpty()) return 0;
    }
    return 1;
}


template<class ItemType>
void PQue<ItemType>::Insert(ItemType newItem, int p) {
    if (p < 0 || p >= numPriorities) {
        cout << "Invalid priority level. Must be between 0 and " << numPriorities - 1 << "." << endl;
        return;
    }
    pQ[p].Insert(newItem);
}
template<class ItemType>
void PQue<ItemType>::Remove(ItemType& item) {
    for (int i = 0; i < numPriorities; i++) {
        if (!pQ[i].IsEmpty()) {
            pQ[i].Remove(item);
            return;
        }
    }
    cout << "Priority Queue is empty, nothing to remove." << endl;
}
int main() {
    int levels;
    cout << "Enter the number of priority levels: ";
    cin >> levels;

    PQue<string> pq(levels);

    pq.Insert("Task A (Priority 5)", 5);
    pq.Insert("Task B (Priority 1)", 1);
    pq.Insert("Task C (Priority 3)", 3);
    pq.Insert("Task D (Priority 0 - Highest)", 0);
    pq.Insert("Task E (Priority 7)", 7);
    pq.Insert("Task F (Priority 2)", 2);

    string item;
    cout << "\nRemoving items in priority order:\n";
    while (!pq.ISEmpty()) {
        pq.Remove(item);
        cout << "Removed: " << item << endl;
    }

    return 0;
}
*/

