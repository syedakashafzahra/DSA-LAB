Binary Search Tree in C++

Description:
This C++ program implements a generic Binary Search Tree (BST) using templates. It supports key operations such as inserting, deleting, searching for an item, printing the tree in order, and counting the number of nodes. The program includes a demonstration using both integers and characters from a user-entered string.

Features:

Templated implementation to support various data types (like int and char)

Insert, delete, and retrieve items

In-order traversal for sorted display

Function to count total number of nodes

Recursive destructor for proper memory management

Demonstration of sorting characters in a string using BST

Files:

main.cpp: Contains the complete implementation and test cases

How to Compile and Run:

Open a terminal or command prompt.

Use a C++ compiler like g++.

To compile:
g++ -o bst main.cpp

To run:
./bst

Program Flow:

Insert integer nodes: 10, 5, 15, 3, 7

Print in-order traversal (sorted output)

Search for item 7

Delete item 7 and reprint the tree

Prompt the user to enter a string

Insert each character of the string into a BST

Print characters in sorted order