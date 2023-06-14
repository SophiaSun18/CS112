/*
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 21, 2022
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_
#include "Stack.h"
#include <string>
using namespace std;

class ReversePoem {
public:
	ReversePoem(string poemFile);

	string getTitle();
	string getAuthor();
	string getBody();
	string getBodyReversed();

private:
	Stack<string> *myStack;
	string myBody;
	string myBodyReverse;
	friend class ReverseTester;
};

#endif /* REVERSEPOEM_H_ */
