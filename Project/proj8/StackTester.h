/* StackTester.h declares a test-class for a dynamically allocated (array) Stack.
 * Joel Adams, for CS 112 at Calvin University
 * Student Name: ZeAi Sun (zs35)
 * Date: Mar 21, 2022
 */

#ifndef STACKTESTER_H_
#define STACKTESTER_H_


class StackTester {
public:
	void runTests();
	void testConstructor();
	void testIsEmpty();
	void testPushPeekTopAndIsFull();
	void testPop();
	void testCopyConstructor();
	void testAssignment();
	void testDestructor();
	void testGetSizeGetCapacityAndSetCapacity();
};

#endif /*STACKTESTER_H_*/

