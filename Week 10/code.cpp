#include<iostream>
using namespace std;
#include<string>
template<class T>
struct TreeNode {
	T info;
	struct TreeNode* left;
	struct TreeNode* right;
};
template<class T>
class BinarySearchTree {
private:
	TreeNode<T>* root;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void destructorHelper(TreeNode<T>* node);
	bool isEmpty() const;
	void insertItem(T item);
	void insertHelper(TreeNode<T>*& node, T item);
	void PrintTree();
	void PrintHelper(TreeNode<T>* node);
	void RetrieveItem(T& item, bool& found);
	void RetrieveHelper(TreeNode<T>* node, T& item, bool& found);
	void DeleteItem(T& item);
	void DeleteHelper(TreeNode<T>*& node, T& item);
	int NumberOfNodes();
	int CountHelper(TreeNode<T>* node);
};
template<class T>
int BinarySearchTree<T>::NumberOfNodes() {
	return CountHelper(root);
}

template<class T>
int BinarySearchTree<T>::CountHelper(TreeNode<T>* node) {
	if (node == nullptr) return 0;
	return 1 + CountHelper(node->left) + CountHelper(node->right);
}

template<class T>
void BinarySearchTree<T>::DeleteItem(T& item) {
	DeleteHelper(root, item);
}

template<class T>
void BinarySearchTree<T>::DeleteHelper(TreeNode<T>*& node, T& item) {
	if (node == nullptr) {
		cout << "Item not found. Nothing to delete." << endl;
	}
	else if (item < node->info) {
		DeleteHelper(node->left, item);
	}
	else if (item > node->info) {
		DeleteHelper(node->right, item);
	}
	else { // Found the node to delete
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
		else if (node->left == nullptr) {
			TreeNode<T>* temp = node;
			node = node->right;
			delete temp;
		}
		else if (node->right == nullptr) {
			TreeNode<T>* temp = node;
			node = node->left;
			delete temp;
		}
		else {
			TreeNode<T>* successor = node->right;
			while (successor->left != nullptr) {
				successor = successor->left;
			}
			node->info = successor->info;
			DeleteHelper(node->right, successor->info);
		}
	}
}

template<class T>
void BinarySearchTree<T>::RetrieveItem(T& item, bool& found) {
	RetrieveHelper(root, item, found);
}
template<class T>
void BinarySearchTree<T>::RetrieveHelper(TreeNode<T>* node, T& item, bool& found) {
	if (node == nullptr) {
		found = false;
	}
	else if (item < node->info) {
		RetrieveHelper(node->left, item, found);
	}
	else if (item > node->info) {
		RetrieveHelper(node->right, item, found);
	}
	else {
		item = node->info;
		found = true;
	}
}
template<class T>
void BinarySearchTree<T>::PrintTree() {
	PrintHelper(root);
}
template<class T>
void BinarySearchTree<T>::PrintHelper(TreeNode<T>* node) {
	if (node != nullptr) {
		PrintHelper(node->left);
		cout << node->info << " ";
		PrintHelper(node->right);
	}
}
template<class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
	destructorHelper(root);
}
template<class T>
void BinarySearchTree<T>::destructorHelper(TreeNode<T>* node) {
	if (node != nullptr) {
		destructorHelper(node->left);
		destructorHelper(node->right);
		delete node;
	}
}
template<class T>
bool BinarySearchTree<T>::isEmpty() const {
	return root == nullptr;
}
template<class T>
void BinarySearchTree<T>::insertItem(T item) {
	insertHelper(root, item);
}
template<class T>
void BinarySearchTree<T>::insertHelper(TreeNode<T>*& node, T item) {
	if (node == nullptr) {
		node = new TreeNode<T>;
		node->info = item;
		node->left = node->right = nullptr;
	}
	else if (item < node->info) {
		insertHelper(node->left, item);
	}
	else if (item > node->info) {
		insertHelper(node->right, item);
	}
}
int main() {
	BinarySearchTree<int> bst;

	bst.insertItem(10);
	bst.insertItem(5);
	bst.insertItem(15);
	bst.insertItem(3);
	bst.insertItem(7);

	cout << "In-order Traversal: ";
	bst.PrintTree();
	cout << endl;

	cout << "Total nodes: " << bst.NumberOfNodes() << endl;

	int item = 7;
	bool found = false;
	bst.RetrieveItem(item, found);
	cout << (found ? "Item found" : "Item not found") << endl;

	bst.DeleteItem(item);
	cout << "After deleting 7, in-order: ";
	bst.PrintTree();
	cout << endl;
	BinarySearchTree<char> BST;
	cout << "------------------------------------------------------" << endl;
	cout << "EXERCISE 9.1 " << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "Enter a string :";
	string str;
	getline(cin, str);
	for (char ch : str) {
		BST.insertItem(ch);
	}
	cout << "Sorted string: ";
	BST.PrintTree();
	cout << endl;
	return 0;
}