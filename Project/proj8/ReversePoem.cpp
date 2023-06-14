/*
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 21, 2022
 */

#include "ReversePoem.h"
#include <fstream>

ReversePoem::ReversePoem(string poemFile) {
	myStack = new Stack<string>(1);
	ifstream fin(poemFile);
	string aLine;
	// Read poem from the file and push all lines into the stack.
	while (getline(fin, aLine)) {
		try {
			myStack->push(aLine);
		} catch (const StackException& se) {
			myStack->setCapacity(2 * myStack->getCapacity());
			myStack->push(aLine);
		}
	}
	// Store the poem in a string.
	for (int i = 3; i < myStack->mySize; i++) {
		myBody = myBody + myStack->myArray[i] + "\n";
	}
	// Store the reverse of the poem in a string.
	for (int i = myStack->mySize - 1; i > 2; i--) {
		myBodyReverse = myBodyReverse + myStack->pop() + "\n";
	}
}

string ReversePoem::getTitle() {
	return myStack->myArray[0];
}

string ReversePoem::getAuthor() {
	return myStack->myArray[1];
}

string ReversePoem::getBody() {
	return myBody;
}

string ReversePoem::getBodyReversed() {
	return myBodyReverse;
}
