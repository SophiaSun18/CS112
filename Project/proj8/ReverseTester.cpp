/*
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 21, 2022
 */

#include "ReverseTester.h"
#include "ReversePoem.h"

string poemName1 = "poems/cats.txt";
string poemName2 = "poems/love.txt";
string poemName3 = "poems/theKiss.txt";

void ReverseTester::runTests() {
	cout << "Testing ReversePoem class..." << endl;
	testConstructor();
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
	cout << "All tests passed!" << endl;
}

void ReverseTester::testConstructor() {
	cout << "Testing Constructor...";
	ReversePoem poem1(poemName1);
	assert(poem1.myStack->getSize() == 6);
	assert(poem1.myStack->getCapacity() == 8);
	assert(poem1.myStack->peekTop() == "I hate those furry felines.");
	assert(poem1.myStack->pop() == "I hate those furry felines.");
	assert(poem1.myStack->pop() == "I could never say");
	assert(poem1.myStack->pop() == "I love it when cats rub against me.");
	assert(poem1.myStack->pop() == "");
	assert(poem1.myStack->pop() == "Leo J. Smada");
	assert(poem1.myStack->pop() == "Cats");
	assert(poem1.myStack->getSize() == 0);
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}

void ReverseTester::testGetTitle() {
	cout << "Testing getTitle()...";
	ReversePoem poem1(poemName1);
	assert(poem1.getTitle() == "Cats");
	cout << " 0 " << flush;

	ReversePoem poem2(poemName2);
	assert(poem2.getTitle() == "Love?");
	cout << " 1 " << flush;

	ReversePoem poem3(poemName3);
	assert(poem3.getTitle() == "The Kiss");
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ReverseTester::testGetAuthor() {
	cout << "Testing getAuthor()...";
	ReversePoem poem1(poemName1);
	assert(poem1.getAuthor() == "Leo J. Smada");
	cout << " 0 " << flush;

	ReversePoem poem2(poemName2);
	assert(poem2.getAuthor() == "Anonymous");
	cout << " 1 " << flush;

	ReversePoem poem3(poemName3);
	assert(poem3.getAuthor() == "R. Lamoureux");
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ReverseTester::testGetBody() {
	cout << "Testing getBody()...";
	ReversePoem poem1(poemName1);
	assert(poem1.getBody() == "I love it when cats rub against me.\nI could never say\nI hate those furry felines.\n");
	cout << " 0 " << flush;

	ReversePoem poem2(poemName2);
	assert(poem2.getBody() == "I don't love you anymore...\nI would be lying if I said\nThat I still love you the way I always did.\nI'm sure\nNothing was in vain.\nAnd I feel inside of me that\nYou mean nothing to me\nI could never really say that\nOur time together matters.\nI feel more and more that\nI'm forgetting you...\nAnd I will never use the phrase\nI love you.\nI'm sorry but I must tell the truth...\n");
	cout << " 1 " << flush;

	ReversePoem poem3(poemName3);
	assert(poem3.getBody() == "When you kissed me\nA fool fell in love\nI became weak in the knees\nThe world revolved around your halo\nAngel eyes captured my imagination\nLike Einstein I discovered relativity\nWisdom had been my lonely pathway\nDrunk on independent thought\nWondering if those lips would part for me\nWanting to breathe your breath\nGazing longingly\nI looked towards you\nSo quickly\nYou looked away\nmy heart sank\nWhen you kissed another boy\n");
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ReverseTester::testGetBodyReversed() {
	cout << "Testing getBodyReversed()...";
	ReversePoem poem1(poemName1);
	assert(poem1.getBodyReversed() == "I hate those furry felines.\nI could never say\nI love it when cats rub against me.\n");
	cout << " 0 " << flush;

	ReversePoem poem2(poemName2);
	assert(poem2.getBodyReversed() == "I'm sorry but I must tell the truth...\nI love you.\nAnd I will never use the phrase\nI'm forgetting you...\nI feel more and more that\nOur time together matters.\nI could never really say that\nYou mean nothing to me\nAnd I feel inside of me that\nNothing was in vain.\nI'm sure\nThat I still love you the way I always did.\nI would be lying if I said\nI don't love you anymore...\n");
	cout << " 1 " << flush;

	ReversePoem poem3(poemName3);
	assert(poem3.getBodyReversed() == "When you kissed another boy\nmy heart sank\nYou looked away\nSo quickly\nI looked towards you\nGazing longingly\nWanting to breathe your breath\nWondering if those lips would part for me\nDrunk on independent thought\nWisdom had been my lonely pathway\nLike Einstein I discovered relativity\nAngel eyes captured my imagination\nThe world revolved around your halo\nI became weak in the knees\nA fool fell in love\nWhen you kissed me\n");
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}
