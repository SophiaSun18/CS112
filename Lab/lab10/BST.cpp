/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: ZeAi Sun (zs35) and Haocheng Jin (hj55)
 * Date: Mar 29, 2022
 */

#include "BST.h"
#include "Exception.h"

BST::BST() {
	myRoot = nullptr;
	myNumItems = 0;
}

BST::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
	myItem = it;
	myLeft = nullptr;
	myRight = nullptr;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

void BST::Node::traversePostorder() {
	if (myLeft != nullptr) {
		myLeft->traversePostorder();
	}
	if (myRight != nullptr) {
		myRight->traversePostorder();
	}
	processItem();
}

void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

void BST::Node::traverseInorder() {
	if (myLeft != nullptr) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != nullptr) {
		myRight->traverseInorder();
	}
}

void BST::Node::processItem() {
	cout << ' ' << myItem;
}

void BST::insert(Item it) {
	if (isEmpty()) {
		myRoot = new Node(it);
	} else {
		myRoot->insert(it);
	}
	myNumItems++;
}

void BST::Node::insert(Item it) {
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

bool BST::contains(Item it){
	if (isEmpty()) {
		return false;
	} else {
		return myRoot->contains(it);
	}
}

bool BST::Node::contains(Item it) {
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
