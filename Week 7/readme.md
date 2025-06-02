README
Double Linked List Implementation in C++

Overview

This project implements a doubly linked list using C++ templates. The class supports dynamic insertion and deletion of elements at both the front and back of the list.

Features

Template-based implementation for flexibility with different data types.
Insertion Operations:
push_front(T data): Inserts an element at the front.
push_back(T data): Inserts an element at the back.
Deletion Operations:
pop_front(): Removes and returns the first element.
pop_back(): Removes and returns the last element.
Array-based Initialization:
Allows creating a doubly linked list from an array.
Automatic Memory Management:
Destructor ensures proper cleanup of allocated memory.
Files

main.cpp: Contains the implementation of the doubly linked list and a test program.
Compilation & Execution

To compile the program, use the following command:

g++ -o double_linked double_linked.cpp
To run the program:

./double_linked
Example Usage

long long arr[] = { 1000000000001, 2000000000002, 3000000000003, 4000000000004 };
double_linked<long long> dlist(arr);

dlist.push_back(5000000000005);
dlist.push_front(9999999999999);

cout << "List after insertions: ";
while (dlist)
    cout << dlist.pop_front() << " ";
cout << endl;
Example Output

List after insertions: 9999999999999 1000000000001 2000000000002 3000000000003 4000000000004 5000000000005
Dependencies

C++ Compiler (g++)
Standard Library
Author

This project was developed as part of a C++ exercise to demonstrate a doubly linked list implementation using templates.