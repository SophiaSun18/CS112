/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 21, 2022
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

template <class Item>

class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack<Item>& original);
	~Stack();
	Stack<Item>& operator=(const Stack<Item>& original);
	
	bool isEmpty();
	bool isFull();
	Item peekTop();
	void push(Item it);
	Item pop();

	unsigned getSize();
	unsigned getCapacity();
	void setCapacity(unsigned newCapacity);

protected:
	void makeCopyOf(const Stack<Item>& original);
	
private:
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	friend class StackTester;
	friend class ReversePoem;
};

#endif

template <class Item>
Stack<Item>::Stack(unsigned capacity) {
	if ( capacity == 0 ) {
		throw StackException("Stack(capacity)", "capacity must be positive!");
	} else {
		mySize = 0;
		myCapacity = capacity;
		myArray = new Item[capacity];
	}
}

template <class Item>
Stack<Item>::Stack(const Stack<Item>& original) {
	makeCopyOf(original);
}

template <class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; ++i) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

template <class Item>
Stack<Item>::~Stack() {
	delete [] myArray;
	myArray = nullptr;
	myCapacity = 0;
	mySize = 0;
}

template <class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

template <class Item>
bool Stack<Item>::isEmpty() {
	return (mySize == 0);
}

template <class Item>
bool Stack<Item>::isFull() {
	return (mySize == myCapacity);
}

template <class Item>
Item Stack<Item>::peekTop() {
	if ( isEmpty() ) {
		throw StackException("peekTop()", "stack is empty!");
	}
	return myArray[mySize - 1];
}

template <class Item>
void Stack<Item>::push(Item it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full!");
	} else {
		myArray[mySize] = it;
		mySize ++;
	}
}

template <class Item>
Item Stack<Item>::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty!");
	} else {
		mySize --;
		return myArray[mySize];
	}
}

template <class Item>
unsigned Stack<Item>::getSize() {
	return mySize;
}

template <class Item>
unsigned Stack<Item>::getCapacity() {
	return myCapacity;
}

template <class Item>
void Stack<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity == 0 or newCapacity < getSize()) {
		throw StackException("setCapacity()", "bad new capacity!");
	} else {
		Item* newArray = new Item[newCapacity];
		for (unsigned i = 0; i < mySize; i++) {
			newArray[i] = myArray[i];
		}
		delete [] myArray;
		myArray = newArray;
		myCapacity = newCapacity;
	}
}
