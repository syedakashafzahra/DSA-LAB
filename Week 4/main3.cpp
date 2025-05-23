#include "exercise4.h"

int main() {
    Deque<int> dq(5);

    dq.insertleft(1);
    dq.insertright(2);
    dq.insertleft(3);
    dq.insertright(4);
    dq.insertleft(5);

    dq.display();

    int rItem;
    dq.removeleft(rItem);
    std::cout << "Removed from left: " << rItem << std::endl;

    dq.removeright(rItem);
    std::cout << "Removed from right: " << rItem << std::endl;

    dq.display();

    return 0;
}