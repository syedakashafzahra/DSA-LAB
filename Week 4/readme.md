# Queue and Deque Implementation in C++

## Overview
This project provides an implementation of both a Queue and a Deque (Double-Ended Queue) in C++ using arrays. The Queue is implemented with both a fixed-size array and a dynamic array using templates, while the Deque allows insertions and deletions from both ends.

## Features
- **Queue Implementation:**
  - Fixed-size array-based queue
  - Template-based queue supporting different data types
  - Circular queue mechanism to optimize space usage
- **Deque Implementation:**
  - Supports insertion and deletion from both front and rear
  - Uses a dynamic array

## Files Included
- `queue1.h` - Header file for the fixed-size queue implementation
- `queue1.cpp` - Implementation file for the fixed-size queue
- `queue2.h` - Header file for the template-based queue implementation
- `queue2.cpp` - Implementation file for the template-based queue
- `queue3.h` - Header file for the deque implementation
- `queue3.cpp` - Implementation file for the deque
- `main.cpp` - Test program for Queue (fixed-size)
- `main2.cpp` - Test program for Queue (template-based)
- `main3.cpp` - Test program for Deque

## Queue Implementation Details
### Fixed-Size Queue (`queue1.h`, `queue1.cpp`)
- Uses an array of size `maxQue`.
- Implements basic queue operations:
  - `insert(itemtype newitem)` - Adds an item to the rear of the queue.
  - `remove(itemtype& item)` - Removes an item from the front.
  - `Isempty()` - Checks if the queue is empty.
  - `Isfull()` - Checks if the queue is full.

### Template-Based Queue (`queue2.h`, `queue2.cpp`)
- Supports different data types using templates.
- Dynamically allocates memory for queue storage.
- Implements same queue operations as the fixed-size version.

## Deque Implementation Details (`queue3.h`, `queue3.cpp`)
- Supports insertion and deletion from both front and rear:
  - `insertleft(T item)`, `insertright(T item)` - Add elements from either end.
  - `removeleft(T& item)`, `removeright(T& item)` - Remove elements from either end.
  - `display()` - Prints elements in the deque.