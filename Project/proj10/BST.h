/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: ZeAi Sun (zs35)
 * Date: Apr 3rd, 2022
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == nullptr ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template <class Item>

class BST {
public:
	BST<Item>();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

	void insert(Item it);
	bool contains(Item it);
	int getHeight();

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();

            void insert(Item it);
            bool contains(Item it);
            int getHeight();
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

#endif /*BST_H_*/

template <class Item>
BST<Item>::BST() {
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
BST<Item>::Node::Node(const Item& it) {
	myItem = it;
	myLeft = nullptr;
	myRight = nullptr;
}

template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

template <class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != nullptr) {
		myLeft->traversePostorder();
	}
	if (myRight != nullptr) {
		myRight->traversePostorder();
	}
	processItem();
}

template <class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != nullptr) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != nullptr) {
		myRight->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::processItem() {
	cout << ' ' << myItem;
}

template <class Item>
void BST<Item>::insert(Item it) {
	if (isEmpty()) {
		myRoot = new Node(it);
	} else {
		myRoot->insert(it);
	}
	myNumItems++;
}

template <class Item>
void BST<Item>::Node::insert(Item it) {
	if (myItem == it) {
		throw Exception("insert()", "Item in the BST.");
	} else if (myItem > it) {
		if (myLeft == nullptr) {
			myLeft = new Node(it);
		} else {
			myLeft->insert(it);
		}
	} else if (myItem < it){
		if (myRight == nullptr) {
			myRight = new Node(it);
		} else {
			myRight->insert(it);
		}
	}
}

template <class Item>
bool BST<Item>::contains(Item it){
	if (isEmpty()) {
		return false;
	} else {
		return myRoot->contains(it);
	}
}

template <class Item>
bool BST<Item>::Node::contains(Item it) {
	if (myItem == it) {
		return true;
	} else if (myItem > it) {
		if (myLeft == nullptr) {
			return false;
		} else {
			return myLeft->contains(it);
		}
	} else if (myItem < it) {
		if (myRight == nullptr) {
			return false;
		} else {
			return myRight->contains(it);
		}
	}
}

template <class Item>
int BST<Item>::getHeight() {
	if (isEmpty()) {
		return 0;
	} else {
		return myRoot->getHeight();
	}
	return 0;
}

template <class Item>
int BST<Item>::Node::getHeight() {
	int leftHt;
	int rightHt;
	int largerHt;

	if (myLeft == nullptr) {
		leftHt = 0;
	} else {
		leftHt = myLeft->getHeight();
	}

	if (myRight == nullptr) {
		rightHt = 0;
	} else {
		rightHt = myRight->getHeight();
	}

	largerHt = (leftHt > rightHt) ? leftHt : rightHt;
	return largerHt + 1;
}
