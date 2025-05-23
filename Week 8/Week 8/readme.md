
### 📄 `README.md`

```markdown
# Binary Tree Implementations in C++

This project contains two different implementations of a Binary Tree in C++:

---

## ✅ Solution 8.1: Array-Based Binary Tree

### 🔹 Description:
- Uses a fixed-size array (`BT[NUMNODES]`) to simulate tree nodes.
- Each node contains:
  - `info`: node value
  - `left`, `right`: indices of left and right children
  - `parent`: index of the parent node

### 🔹 Key Functions:
- `setRoot(int value)`: Sets the root node at index 1.
- `insertLeft(int parentIndex, int value)`: Inserts left child using formula `2 * parentIndex`.
- `insertRight(int parentIndex, int value)`: Inserts right child using `2 * parentIndex + 1`.
- Traversals: `inorder()`, `preorder()`, and `postorder()` starting from index 1.

### 🔹 Notes:
- The structure is based on Complete Binary Tree indexing rules.
- Boundary checks are done to avoid out-of-bounds access.

---

## ✅ Solution 8.2: Linked List–Based Binary Tree

### 🔹 Description:
- Uses dynamic memory allocation (`new`) to create nodes.
- Each node contains:
  - `info`: data value
  - `left`, `right`: pointers to children
  - `parent`: pointer to parent node

### 🔹 Key Functions:
- `makeTree(int x)`: Creates a new node and returns its pointer.
- `setRoot(int x)`: Creates root node.
- `setLeft(NODEPTR p, int x)`: Inserts a left child under given parent pointer.
- `setRight(NODEPTR p, int x)`: Inserts a right child under given parent pointer.
- Traversals: `pretrav()`, `intrav()`, and `posttrav()` for preorder, inorder, and postorder respectively.

### 🔹 Notes:
- Proper checks are implemented to avoid duplicate child insertions.
- The tree is dynamically expandable, unlike the fixed-size array version.

---

## 🛠 How to Run

Compile using any standard C++ compiler:

```bash
g++ filename.cpp -o tree
./tree
```

Replace `filename.cpp` with the actual file containing the code.

---

## 📌 Output Example (from linked list version):

```
Preorder: 10 5 2 7 15 
Inorder: 2 5 7 10 15 
Postorder: 2 7 5 15 10 
```

---

## 📚 Learning Objective

- Understand two different data structure approaches for binary trees.
- Practice tree traversal methods.
- Learn pointer-based dynamic memory usage versus static array usage.

