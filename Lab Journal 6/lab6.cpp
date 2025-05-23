// // //EXAMPLE+ EXERCISE  6.1,6.2
// // #include <iostream>
// // #include <string>
// // 	using namespace std;

// // 	template<class ItemType>
// // 	class list {
// // 	protected:
// // 		struct node {
// // 			ItemType info;
// // 			node* next;
// // 		};

// // 		typedef node* NODEPTR;
// // 		NODEPTR listptr;

// // 	public:
// // 		list();
// // 		~list();
// // 		bool emptyList();
// // 		void insertafter(ItemType oldvalue, ItemType newvalue);
// // 		void deleteItem(ItemType oldvalue);
// // 		void push(ItemType newvalue);
// // 		void reversestring(string& s);
// // 		ItemType pop();
// // 	};


// // 	template<class ItemType>
// // 	list<ItemType>::list() {
// // 		listptr = nullptr;
// // 	}
// // 	template<class ItemType>
// // 	list<ItemType>::~list() {
// // 		NODEPTR p = listptr, q;
// // 		while (p != nullptr) {
// // 			q = p->next;
// // 			delete p;
// // 			p = q;
// // 		}
// // 	}


// // 	template<class ItemType>
// // 	bool list<ItemType>::emptyList() {
// // 		return (listptr == nullptr);
// // 	}


// // 	template<class ItemType>
// // 	void list<ItemType>::push(ItemType newvalue) {
// // 		NODEPTR p = new node();
// // 		p->info = newvalue;
// // 		p->next = listptr;
// // 		listptr = p;
// // 	}

	
// // 	template<class ItemType>
// // 	void list<ItemType>::insertafter(ItemType oldvalue, ItemType newvalue) {
// // 		NODEPTR p;
// // 		for (p = listptr; p != nullptr && p->info != oldvalue; p = p->next);

// // 		if (p == nullptr) {
// // 			cout << "Error: Value " << oldvalue << " not found in the list.\n";
// // 			return;
// // 		}

// // 		NODEPTR q = new node();
// // 		q->info = newvalue;
// // 		q->next = p->next;
// // 		p->next = q;
// // 	}

// // 	// Delete a node
// // 	template<class ItemType>
// // 	void list<ItemType>::deleteItem(ItemType oldvalue) {
// // 		NODEPTR p = listptr, q = nullptr;

// // 		while (p != nullptr && p->info != oldvalue) {
// // 			q = p;
// // 			p = p->next;
// // 		}

// // 		if (p == nullptr) {
// // 			cout << "Error: Value " << oldvalue << " not found in the list.\n";
// // 			return;
// // 		}

// // 		if (q == nullptr) { 
// // 			listptr = p->next;
// // 		}
// // 		else {
// // 			q->next = p->next;
// // 		}

// // 		delete p;
// // 	}


// // 	template<class ItemType>
// // 	ItemType list<ItemType>::pop() {
// // 		if (emptyList()) {
// // 			cout << "Error: List is empty.\n";
// // 			exit(1);
// // 		}

// // 		NODEPTR p = listptr;
// // 		ItemType x = p->info;
// // 		listptr = p->next;
// // 		delete p;
// // 		return x;
// // 	}

// // 	// Reverse a string using stack (linked list)
// // 	template<class ItemType>
// // 	void list<ItemType>::reversestring(string& s) {
// // 		list<char> reversedstring;

// // 		for (char ch : s) {
// // 			reversedstring.push(ch);
// // 		}

// // 		cout << "Reversed string: ";
// // 		while (!reversedstring.emptyList()) {
// // 			cout << reversedstring.pop();
// // 		}
// // 		cout << endl;
// // 	}


// // 	int main() {
// // 		// Reverse String Example (Exercise 6.2)
// // 		list<char> s;
// // 		string si;
// // 		cout << "Enter a string: ";
// // 		getline(cin, si);
// // 		s.reversestring(si);

// // 		// Linked List Operations (Exercise 6.1)
// // 		list<int> l;
// // 		l.push(86);
// // 		cout << "Popped value: " << l.pop() << endl;

		
// // 		l.push(10);
// // 		l.push(20);
// // 		l.push(30);
// // 		l.insertafter(20, 25);
// // 		l.deleteItem(30);

// // 		return 0;
// // 	}


// //----------------------------------------------------	//6.3----------------------------------------------------
// #include <iostream>
// 	using namespace std;

// 	class LinkedStr {
// 		struct Node {
// 			int info;
// 			Node* next;
// 			Node(int val, Node* nxt = NULL) : info(val), next(nxt) {}
// 		};

// 		Node* ptr; 

// 	public:
// 		LinkedStr() : ptr(NULL) {}

	
// 		~LinkedStr() {
// 			while (ptr) {
// 				Node* temp = ptr;
// 				ptr = ptr->next;
// 				delete temp;
// 			}
// 		}


// 		void makeStr(int len) {
// 			if (len <= 0) return;
// 			cout << "Enter " << len << " elements: ";

// 			for (int i = 0; i < len; i++) {
// 				int val;
// 				cin >> val;
// 				ptr = new Node(val, ptr); 
// 			}
// 		}

		
// 		void displayStr() const {
// 			Node* temp = ptr;
// 			if (!temp) {
// 				cout << "List is empty!" << endl;
// 				return;
// 			}
// 			cout << "Linked List: ";
// 			while (temp) {
// 				cout << temp->info << " -> ";
// 				temp = temp->next;
// 			}
// 			cout << "NULL" << endl;
// 		}

		
// 		void removeFirst() {
// 			if (!ptr) return;

// 			Node* temp = ptr;
// 			ptr = ptr->next;
// 			delete temp;
// 		}


// 		void removeLast() {
// 			if (!ptr) return;
// 			if (!ptr->next) {
// 				delete ptr;
// 				ptr = NULL;
// 				return;
// 			}
// 			Node* temp = ptr;
// 			while (temp->next->next)
// 				temp = temp->next;
// 			delete temp->next;
// 			temp->next = NULL;
// 		}

	
// 		void remove(int k) {


// 			if (!ptr) return;      
// 			if (ptr->info == k) {
// 				removeFirst();
// 				return;
// 			}
// 			Node* temp = ptr;
// 			while (temp->next && temp->next->info != k)
// 				temp = temp->next;
// 			if (temp->next) {
// 				Node* delNode = temp->next;
// 				temp->next = delNode->next;
// 				delete delNode;
// 			}                  
// 		}
// 	};

	
// 	int main() {
// 		LinkedStr list;
// 		list.makeStr(5);
// 		list.displayStr();

// 		list.removeFirst();
// 		cout << "After removing first element: ";
// 		list.displayStr();

// 		list.removeLast();
// 		cout << "After removing last element: ";
// 		list.displayStr();

// 		list.remove(3); 
// 		cout << "After removing 3: ";
// 		list.displayStr();

// 		return 0;
// 	}