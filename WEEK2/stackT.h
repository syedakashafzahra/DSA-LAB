template<class ItemType>
class Stack {
private:
	int top;
	ItemType* items;
	int maxStack;
public:

	Stack();
	Stack(int max);
	~Stack();
	int IsEmpty() const;
	int IsFull() const;
	void Push(ItemType item);
	void Pop(ItemType& item);
	ItemType Top() const;
};

#pragma once
