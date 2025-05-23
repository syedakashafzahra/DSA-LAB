#define Max_ITEMS 100
typedef int ItemType;
class Stack
{
public:
	Stack();
	int IsEmpty() const;
	int IsFull() const;
	void Push(ItemType item);
	void Pop(ItemType& item);
	ItemType Peek() const;

private:
	int top;
	ItemType items[Max_ITEMS];
};

#pragma once
