#include <iostream>
#include "example1.h"

using namespace std;

int main() {
    Queue q;
    itemtype num;
    q.insert(5);
    q.remove(num);
    cout << "Removed: " << num << endl;
    return 0;
}