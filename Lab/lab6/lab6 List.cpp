/*
 * List.cpp
 *
 *  Created on: Mar 10, 2020
 *      Author: vtn2
 */

#include "List.h"
#include <iostream>
#include <stdexcept>
using namespace std;

List::List() {
	mySize = 0;
	myFirst = myLast = nullptr;
}

List::List(const List & original) {
	mySize = 0;
	myFirst = myLast = nullptr;
	Node * curr = original.myFirst;
	for (int i = 0; i < original.mySize; i++) {
		this->append(curr->myItem);
		curr = curr->myNext;
	}
}

List::~List() {
	mySize = 0;
	delete myFirst;
	myFirst = myLast = nullptr;
}

List::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

List::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

List::Node::~Node() {
	// cout << "~Node() is deallocating the node containing item "
	//		<< myItem << endl;
	delete myNext;
	myNext = nullptr;
}

Item List::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("list is empty");
	}
	return myFirst->myItem;
}

Item List::getLast() const {
	if (mySize == 0) {
		throw underflow_error("list is empty");
	}
	return myLast->myItem;
}

void List::prepend(const Item &it) {
	Node *newNode = new Node(it, myFirst);
	myFirst = newNode;
	if (mySize == 0) {
		myLast = newNode;
	}
	mySize++;
}

void List::append(const Item &it) {
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

void List::writeTo(ostream &out) const {
	for (Node *curr = myFirst; curr != nullptr; curr = curr->myNext) {
		out << curr->myItem << " ";
	}
}

int List::getIndexOf(const Item &it) const {
	Node * curr = myFirst;
	for (int i = 0; i < mySize; i++) {
		if (curr->myItem == it) {
			return i;
		}
		curr = curr->myNext;
	}
	return -1;
}

bool List::operator==(const List &l2) const{
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
