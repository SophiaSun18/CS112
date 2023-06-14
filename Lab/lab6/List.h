/*
 * List.h
 * Student name: ZeAi Sun (zs35)
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>
using namespace std;

template <class Item>

class List {
public:
	List();
	List(const List<Item> &original);
	virtual ~List();
	unsigned getSize() const { return mySize; }
	Item getFirst() const;
	Item getLast() const;
	void prepend(const Item &it);
	void append(const Item &it);
	void writeTo(ostream &out) const;
	int getIndexOf(const Item &it) const;
	bool operator==(const List<Item> &l2) const;

private:
	struct Node {
		Node();
		Node(Item it, Node* next);
		virtual ~Node();
		Item myItem;
		Node *myNext;
	};
	unsigned mySize;
	Node *myFirst;
	Node *myLast;

	friend class ListTester;
};

#endif /* LIST_H_ */

template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = nullptr;
}

template <class Item>
List<Item>::List(const List<Item> & original) {
	mySize = 0;
	myFirst = myLast = nullptr;
	Node * curr = original.myFirst;
	for (int i = 0; i < original.mySize; i++) {
		this->append(curr->myItem);
		curr = curr->myNext;
	}
}

template <class Item>
List<Item>::~List() {
	mySize = 0;
	delete myFirst;
	myFirst = myLast = nullptr;
}

template <class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

template <class Item>
List<Item>::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

template <class Item>
List<Item>::Node::~Node() {
	// cout << "~Node() is deallocating the node containing item "
	//		<< myItem << endl;
	delete myNext;
	myNext = nullptr;
}

template <class Item>
Item List<Item>::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("list is empty");
	}
	return myFirst->myItem;
}

template <class Item>
Item List<Item>::getLast() const {
	if (mySize == 0) {
		throw underflow_error("list is empty");
	}
	return myLast->myItem;
}

template <class Item>
void List<Item>::prepend(const Item &it) {
	Node *newNode = new Node(it, myFirst);
	myFirst = newNode;
	if (mySize == 0) {
		myLast = newNode;
	}
	mySize++;
}

template <class Item>
void List<Item>::append(const Item &it) {
	Node *newNode = new Node(it, nullptr);
	myLast = newNode;
	if (mySize == 0) {
		myFirst = newNode;
	} else {
		Node * curr = myFirst;
		for (int i = 0; i < mySize; i++) {
			if (curr->myNext == nullptr) {
				curr->myNext = myLast;
			}
			curr = curr->myNext;
		}
	}
	mySize++;
}

template <class Item>
void List<Item>::writeTo(ostream &out) const {
	for (Node *curr = myFirst; curr != nullptr; curr = curr->myNext) {
		out << curr->myItem << " ";
	}
}

template <class Item>
int List<Item>::getIndexOf(const Item &it) const {
	Node * curr = myFirst;
	for (int i = 0; i < mySize; i++) {
		if (curr->myItem == it) {
			return i;
		}
		curr = curr->myNext;
	}
	return -1;
}

template <class Item>
bool List<Item>::operator==(const List<Item> &l2) const{
	if (mySize != l2.mySize) {
		return false;
	} else {
		Node * curr = myFirst;
		Node * curr2 = l2.myFirst;
		for (int i = 0; i < mySize; i++) {
			if (curr->myItem != curr2->myItem) {
				return false;
			}
			curr = curr->myNext;
			curr2 = curr2->myNext;
		}
	}
	return true;
}
