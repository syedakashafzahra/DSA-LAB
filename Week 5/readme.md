In this **Priority Queue Lab**, we explore the implementation of **queues** and **priority queues** using **templates** in C++. The lab demonstrates how to create a **generic queue class** (`Que<ItemType>`) that supports dynamic allocation and circular queue functionality. The queue allows basic operations such as **insertion (enqueue), removal (dequeue), checking if the queue is full or empty**.

Building upon this, the **priority queue (`PQue<ItemType>`)** is implemented using an array of queues, where each queue represents a different **priority level**. The priority queue ensures that elements with **higher priority (lower index)** are processed before lower-priority elements. Two implementations are provided: one with a **fixed number of priority levels (10)** and another where the user can define the number of priority levels dynamically. 

Through this lab, we learn about:
1. **Queue Data Structure** – Circular queue operations with dynamic memory allocation.
2. **Priority Queue Implementation** – Managing multiple queues based on priority.
3. **Templates in C++** – Writing generic code that works with different data types.
4. **Dynamic Memory Management** – Using `new` and `delete` for memory allocation.
5. **Real-world Applications** – Task scheduling, job processing, and handling priority-based requests.

The lab enhances our understanding of **efficient data handling using queues** and how **priority-based processing** can be implemented in real-world systems.