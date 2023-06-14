/*
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 28, 2022
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_
#include "Stack.h"
#include "ArrayQueue.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class PalindromeDetector {
public:
	PalindromeDetector();
	void detectPalindromes(string inputFile, string outputFile);
	bool isPalindrome(string aString);

private:
	Stack<char> *myStack;
	ArrayQueue<char> *myQueue;
	string myInput;
	string myOutput;
	friend class PalindromeTester;
};

#endif /* PALINDROMEDETECTOR_H_ */
