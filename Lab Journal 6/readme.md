# README

## Linked List and Stack Implementation in C++

### Overview
This project implements linked list and stack operations using templates in C++. It provides basic functionalities such as insertion, deletion, push, pop, and reversing a string using a stack.

### Features
1. **Template-Based Linked List (Exercises 6.1 & 6.2)**
   - Implements a singly linked list using templates.
   - Supports insertion, deletion, push, and pop operations.
   - Reverses a string using a stack (linked list-based).

2. **Integer Linked List (Exercise 6.3)**
   - Implements a linked list with integer values.
   - Supports creating a linked list, displaying elements, and removing elements (first, last, and a specific value).

### Files
- **main.cpp**: Contains the implementation of both the template-based and integer-based linked lists along with the main function.

### Compilation & Execution
To compile the program, use the following command:
```
g++ -o linked_list linked_list.cpp
```
To run the program:
```
./linked_list
```

### Usage
1. **Reversing a String (Stack)**
   - Enter a string when prompted.
   - The program will reverse and display the string.

2. **Linked List Operations**
   - Push elements onto the list.
   - Insert elements after a specific value.
   - Delete elements from the list.
   - Display the linked list.

3. **Integer Linked List Operations**
   - Create a linked list with user-input values.
   - Display the linked list.
   - Remove the first, last, or a specific element from the list.

### Example Output
```
Enter a string: hello
Reversed string: olleh

Enter 5 elements: 1 2 3 4 5
Linked List: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

After removing first element:
Linked List: 4 -> 3 -> 2 -> 1 -> NULL

After removing last element:
Linked List: 4 -> 3 -> 2 -> NULL

After removing 3:
Linked List: 4 -> 2 -> NULL
```

### Dependencies
- C++ Compiler (g++)
- Standard Library

### Author
This project was developed as part of a C++ exercise to demonstrate linked list and stack implementations.
