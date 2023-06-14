/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 15, 2022
 */

#include "Stack.h"

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
Stack::Stack(unsigned capacity) {
	if ( capacity == 0 ) {
		throw StackException("Stack(capacity)", "capacity must be positive!");
	} else {
		mySize = 0;
		myCapacity = capacity;
		myArray = new Item[capacity];
	}
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; ++i) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
Stack::~Stack() {
	delete [] myArray;
	myArray = nullptr;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

bool Stack::isEmpty() {
	return (mySize == 0);
}

bool Stack::isFull() {
	return (mySize == myCapacity);
}

Item Stack::peekTop() {
	if ( isEmpty() ) {
		throw StackException("peekTop()", "stack is empty!");
	}
	return myArray[mySize - 1];
}

void Stack::push(Item it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full!");
	} else {
		myArray[mySize] = it;
		mySize ++;
	}
}

Item Stack::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty!");
	} else {
		mySize --;
		return myArray[mySize];
	}
}

unsigned Stack::getSize() {
	return mySize;
}

unsigned Stack::getCapacity() {
	return myCapacity;
}

void Stack::setCapacity(unsigned newCapacity) {
	if (newCapacity == 0 or newCapacity < getSize()) {
		throw StackException("setCapacity()", "bad new capacity!");
	} else {
		Item* newArray = new Item[newCapacity];
		for (unsigned i = 0; i < mySize; i++) {
			newArray[i] = myArray[i];
		}
		myArray = newArray;
		myCapacity = newCapacity;
//		delete[] newArray;
	}
}
