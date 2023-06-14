/*
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 28, 2022
 */

#include "PalindromeDetector.h"
#include <cstring>
#include <stdio.h>
#include <ctype.h>

PalindromeDetector::PalindromeDetector() {
	myStack = new Stack<char>(1);
	myQueue = new ArrayQueue<char>(1);
}

void PalindromeDetector::detectPalindromes(string inputFile, string outputFile) {
	myInput = inputFile;
	myOutput = outputFile;

	ifstream fin(myInput);
	ofstream fout(myOutput);
	string aLine;

	while (getline(fin, aLine)) {
		fout << aLine;
		if (isPalindrome(aLine) == true) {
			fout << "***" << endl;
		} else {
			fout << endl;
		}
	}
	fout.close();
}

bool PalindromeDetector::isPalindrome(string aString) {
	// Create new stack and new queue for the new check.
	myStack = new Stack<char>(1);
	myQueue = new ArrayQueue<char>(1);
	// Load all characters in the string into myStack and myQueue.
	for (int i = 0; i < aString.length(); i++) {
		if ( isalpha(aString[i]) == true) {
			char a = tolower(aString[i]);
			try {
				myStack->push(a);
			} catch (const StackException& se) {
				myStack->setCapacity(2 * myStack->getCapacity());
				myStack->push(a);
			}
			try {
				myQueue->append(a);
			} catch (const QueueException& se) {
				myQueue->setCapacity(2 * myQueue->getCapacity());
				myQueue->append(a);
			}
		}
	}
	// If the line is empty, it is not a palindrome.
	if (myStack->getSize() == 0 or myQueue->getSize() == 0) {
		return false;
	}
	// Compare each item in myStack and myQueue.
	while (myStack->getSize() != 0 and myQueue->getSize() != 0) {
		char ch1 = myStack->pop();
		char ch2 = myQueue->remove();
		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}
