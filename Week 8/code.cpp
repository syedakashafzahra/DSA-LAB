
//
//
//
//8.1 EXERCISE SOLUTION:
//
//#include<iostream>
//using namespace std;
//#define NUMNODES 100
////-------------using array--------------
//class BinaryTree {
//	struct Node {
//		int info;
//		int left, right, parent;
//	};
//	Node BT[NUMNODES];
//
//public:
//	BinaryTree() {
//		for (int i = 0; i < NUMNODES; i++) {
//			BT[i].info = -1;
//			BT[i].left = -1;
//			BT[i].right = -1;
//			BT[i].parent = -1;
//		}
//	}
//	void setRoot(int value) {
//		BT[1].info = value;
//	}
//	void insertLeft(int parentIndex, int value) {
//		int leftIndex = 2 * parentIndex;
//		if (leftIndex >= NUMNODES) {
//			cout << "Error: Left index out of bounds.\n";
//			return;
//		}
//		if (BT[leftIndex].info != -1) {
//			cout << "Left child already exists." << endl;
//			return;
//		}
//		BT[leftIndex].info = value;
//		BT[leftIndex].parent = parentIndex;
//		BT[parentIndex].left = leftIndex;
//	}
//	;	void insertR(int parentIndex, int value) {
//		int rightIndex = 2 * parentIndex + 1;
//		if (rightIndex >= NUMNODES) {
//			cout << "Error: Right index out of bounds.\n";
//			return;
//		}
//		if (BT[rightIndex].info != -1) {
//			cout << "Error: Right child already exists at index " << rightIndex << ".\n";
//			return;
//		}
//		BT[rightIndex].info = value;
//		BT[rightIndex].parent = parentIndex;
//		BT[parentIndex].right = rightIndex;
//	}
//	void inorder(int index) {
//		if (index <= 0 || index >= NUMNODES || BT[index].info == -1) return;
//
//		inorder(BT[index].left);
//		cout << BT[index].info << " ";
//		inorder(BT[index].right);
//	}
//	void preorder(int index) {
//		if (index <= 0 || index >= NUMNODES || BT[index].info == -1) return;
//
//		cout << BT[index].info << " ";
//		preorder(BT[index].left);
//		preorder(BT[index].right);
//	}
//	void postorder(int index) {
//		if (index <= 0 || index >= NUMNODES || BT[index].info == -1) return;
// 
//		postorder(BT[index].left);
//		postorder(BT[index].right);
//		cout << BT[index].info << " ";
//	}
//};
//
//int main() {
//	BinaryTree tree;
//	tree.setRoot(10);
//	tree.insertLeft(1, 20);
//	tree.insertRight(1, 30);
//	tree.insertLeft(2, 40);
//	tree.insertRight(2, 50);
//	tree.insertLeft(3, 60);
//	tree.insertRight(3, 70);
//
//	cout << "Inorder: ";
//	tree.inorder(1); //1st index: root
//	cout << endl;
//
//	cout << "Preorder: ";
//	tree.preorder(1);
//	cout << endl;
//
//	cout << "Postorder: ";
//	tree.postorder(1);
//	cout << endl;
//}


//---------------linked list approach -----------SOLUTION -8.2:


//
//
//
//#include<iostream>
//using namespace std;
//class BinaryTree {
//public:
//	struct Treenode {
//		int info;
//		 Treenode* left;
//		 Treenode* right;
//		 Treenode* parent;
//	};
//	typedef Treenode* NODEPTR;
//	NODEPTR root;
//
//
//	BinaryTree() {
//		root = nullptr;
//	}
//	NODEPTR getRoot() {
//		return root;
//	}
//	bool isEmpty() const {
//		return root == nullptr;
//	}
//	NODEPTR makeTree(int x) {
//		NODEPTR temp = new Treenode;
//		temp->info = x;
//		temp->right = nullptr;
//		temp->left = nullptr;
//		temp->parent = nullptr;
//		return temp;
//		// returns pointer to that new node created
//	}
//	bool isLeft(NODEPTR p) { //checks whether the node pointed by p is left child or not{
//		if (isEmpty() || p == nullptr) return false;
//		return (p->parent->left == p);
//	}
//	bool isRight(NODEPTR p) { //checks whether the node pointed by p is right child or not
//		if (isEmpty() || p == nullptr) return false;
//		return (p->parent->right == p);
//	}
//	void setRoot(int x) {
//		if (!isEmpty()) {
//			cout << "Root already exists. " << endl;
//			return;
//		}
//		else {
//			root = makeTree(x);
//		}
//	}
//	void setLeft(NODEPTR p, int x) {
//		if (p == nullptr) {
//			cout << "Cannot insert left child. Parent does not exist." << endl;
//			return;
//		}
//		if (p->left != nullptr) {
//			cout << "Left child already exists." << endl;
//			return;
//		}
//		NODEPTR child = makeTree(x);
//		child->parent = p;
//		p->left = child;
//	}
//
//	void setRight(NODEPTR p, int x) {
//		if (p == nullptr) {
//			cout << "Cannot insert right child. Parent does not exist." << endl;
//			return;
//		}
//		if (p->right != nullptr) {
//			cout << "Right child already exists." << endl;
//			return;
//		}
//		NODEPTR child = makeTree(x);
//		child->parent = p;
//		p->right = child;
//	}
//
//	void pretrav(NODEPTR p) { // root, left, right
//		if (p != nullptr) {
//			cout << p->info << " ";
//			pretrav(p->left);
//			pretrav(p->right);
//		}
//	}
//	void posttrav(NODEPTR p) { // left, right, root
//		if (p != nullptr) {
//			posttrav(p->left);
//			posttrav(p->right);
//			cout << p->info << " ";
//		}
//	}
//	void intrav(NODEPTR p) { // left, root, right
//		if (p != nullptr) {
//			intrav(p->left);
//			cout << p->info << " ";
//			intrav(p->right);
//		}
//	}
//};
//int main() {
//	BinaryTree bt;
//	bt.setRoot(10);
//	BinaryTree::NODEPTR root = bt.getRoot();
//	bt.setLeft(root, 5);
//	bt.setRight(root, 15);
//	bt.setLeft(root->left, 2);
//	bt.setRight(root->left, 7);
//
//	cout << "Preorder: ";
//	bt.pretrav(root);
//	cout << "\nInorder: ";
//	bt.intrav(root);
//	cout << "\nPostorder: ";
//	bt.posttrav(root);
//}
