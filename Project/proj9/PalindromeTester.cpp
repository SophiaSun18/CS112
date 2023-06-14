/*
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 28, 2022
 */

#include "PalindromeTester.h"
#include "PalindromeDetector.h"
#include <fstream>

void PalindromeTester::runTests() {
	cout << "Testing PalindromeDetector class..." << endl;
	testConstructor();
	testDetectPalindromes();
	testIsPalindrome();
	cout << "All tests passed!" << endl;
}

void PalindromeTester::testConstructor() {
	cout << "Testing Constructor...";
	PalindromeDetector p1;
	assert(p1.myStack->getSize() == 0);
	assert(p1.myStack->getCapacity() == 1);
	assert(p1.myStack->isEmpty());
	assert(!p1.myStack->isFull());
	cout << " 0 " << flush;

	try {
		p1.myStack->peekTop();
		cerr << "\npeekTop() worked on empty stack (size 1)\n";
	} catch (const StackException& se ){
		cout << " 1 " << flush;
	}

	assert(p1.myQueue->getSize() == 0);
	assert(p1.myQueue->getCapacity() == 1);
	assert(p1.myQueue->isEmpty());
	assert(!p1.myQueue->isFull());
	cout << " 2 " << flush;

	try {
		p1.myQueue->getFirst();
		cerr << "\ngetFirst() worked on empty queue\n";
	} catch (EmptyQueueException& eqe) {
		cout << " 3 " << flush;
	}

	try {
		p1.myQueue->getLast();
		cerr << "\ngetLast() worked on empty queue\n";
	} catch (EmptyQueueException& eqe) {
		cout << " 4 " << flush;
	}

	cout << "Passed!" << endl;
}

void PalindromeTester::testDetectPalindromes() {
	cout << "Testing detectPalindromes...";
	PalindromeDetector p1;
	p1.detectPalindromes("test/1.txt", "test/1-result.txt");
	ifstream fin1("test/1-result.txt");
	string aLine1;
	getline(fin1, aLine1);
	assert(aLine1 == "eve***");
	getline(fin1, aLine1);
	assert(aLine1 == "adam");
	cout << " 0 " << flush;

	p1.detectPalindromes("test/try.txt", "test/try-result.txt");
	ifstream fin2("test/try-result.txt");
	string aLine2;
	getline(fin2, aLine2);
	assert(aLine2 == "Was it a car or a cat I saw ?***");
	getline(fin2, aLine2);
	assert(aLine2 == "");
	cout << " 1 " << flush;

	p1.detectPalindromes("test/poem.txt", "test/poem-result.txt");
	ifstream fin3("test/poem-result.txt");
	string aLine3;
	getline(fin3, aLine3);
	assert(aLine3 == "Drawn Onward***");
	getline(fin3, aLine3);
	assert(aLine3 == "");
	getline(fin3, aLine3);
	assert(aLine3 == "by Felicia Lamport");
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void PalindromeTester::testIsPalindrome() {
	cout << "Testing isPalindrome...";
	PalindromeDetector p1;
	assert(p1.isPalindrome("Madam, I'm Adam."));
	assert(p1.isPalindrome("A man, a plan, a canal, Panama!"));
	assert(p1.isPalindrome("Drawn Onward"));
	assert(p1.isPalindrome("Eve"));
	assert(p1.isPalindrome("Eve damned Eden; mad Eve"));
	assert(p1.isPalindrome("Cain, a maniac,"));
	assert(p1.isPalindrome("He lived as a devil, eh?"));
	assert(p1.isPalindrome("we panic in a pew,"));
	assert(p1.isPalindrome("-- dumb mobs -- bomb mud."));
	assert(p1.isPalindrome("I prefer PI"));
	assert(p1.isPalindrome("Able was I, ere I saw Elba,"));
	cout << " 0 " << flush;

	assert(!p1.isPalindrome("cat"));
	assert(!p1.isPalindrome("Happy Christmas!"));
	assert(!p1.isPalindrome("how are you?"));
	assert(!p1.isPalindrome("\n")); // assert that empty line is not palindrome.
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}
