/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin University.
 *
 * Student name: Zeai Sun (zs35)
 * Date: Mar 14
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testReadFromStream();
	void testWriteToStream();
	void testReadFromFile();
	void testWriteToFile();
	void testPrepend();
	void testGetIndexOf();
	void testInsertion();
	void testRemove();
	void testInsertAfter();
	void testInsertBefore();
	void testOutput();
};

#endif /*LISTTESTER_H_*/
