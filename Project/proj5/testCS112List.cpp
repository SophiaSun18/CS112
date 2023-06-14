/*
 * Student name: Zeai Sun (zs35)
 * Date: 19 Feb
 * Author: Prof. Victor Norman
 * For: CS 112, Project 5 at Calvin University.
 */

#include <cassert>
#include <iostream>
#include "CS112List.h"
using namespace std;


int main() {
	cout << "Testing constructors..." << endl;
	CS112List<string> lst;
	assert(lst.getSize() == 0);

	CS112List<string> lst2(5);
	assert(lst2.getSize() == 5);

	cout << "Testing getValue()..." << endl;
	assert(lst2.getValue(0) == "");
	assert(lst2.getValue(4) == "");
	try {
		assert(lst2.getValue(5) == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "Testing setValue()..." << endl;
	lst2.setValue(0, "hi");
	assert(lst2.getValue(0) == "hi");
	try {
		assert(lst2.getValue(5) == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "Testing []..." << endl;
	assert(lst2[0] == "hi");  // getting the value
	lst2[1] = "hello";        // setting the value.
	assert(lst2[1] == "hello");
	try {
		assert(lst2[5] == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "Testing copy constructor..." << endl;
	CS112List<string> lst3(lst2);
	assert(lst3.getSize() == lst2.getSize());
	lst2[2] = "please work!";
	assert(lst3[2] != "please work!");

	cout << "Testing printing..." << endl;
	CS112List<string> lst4(2);
	lst4[0] = "Emma";
	lst4[1] = "Wang";
	cout << "This is a list -->" << lst4 << "<--\n";

	cout << "Testing append()..." << endl;
	CS112List<string> aList;
	assert(aList.getSize() == 0);
	aList.append("Alex");
	assert(aList.getSize() == 1);
	assert(aList[0] == "Alex");
	cout << aList << endl;
	aList.append("Heyab");
	assert(aList.getSize() == 2);
	assert(aList[0] == "Alex");
	assert(aList[1] == "Heyab");
	cout << aList << endl;
	aList.append("Prof Norman is weird.");
	cout << aList << endl;

	cout << "Testing operator+..." << endl;
	CS112List<string> l1;
	l1.append("Hi");
	CS112List<string> l2;
	l2.append("Nihao");
	l2.append("Konnichiwa");
	CS112List<string> l3 = l1 + l2;
	cout << l3 << endl;
	assert(l3.getSize() == 3);
	assert(l3[0] == "Hi");
	assert(l3[1] == "Nihao");
	assert(l3[2] == "Konnichiwa");

	cout << "Testing negative indexes..." << endl;
	assert(l3[-1] == "Konnichiwa");
	assert(l3[-2] == "Nihao");
	assert(l3.getValue(-2) == "Nihao");
	try {
		l3[-4];
		assert(false);
	} catch (const range_error &re) {
		// nothing here.
	}
	l3[-1] = "AufWiedersehen";
	assert(l3[2] == "AufWiedersehen");
	l3.setValue(-1, "Hallo");
	assert(l3[2] == "Hallo");

	cout << "Testing find() ..." << endl;
	CS112List<string> l4;
	l4.append("Hi");
	l4.append("Hola");
	l4.append("Ohayo");
	l4.append("Nihao");
	l4.append("Hi");
	assert(l4.find("Hi") == 0);
	assert(l4.find("Ohayo") == 2);
	assert(l4.find("Hello") == -1);

	cout << "Testing insert() ..." << endl;
	CS112List<string> l5;
	l5.append("1st item");
	l5.append("2nd item");
	l5.append("3rd item");
	l5.append("4th item");
	l5.append("5th item");  // The capacity should be 8 now.
	l5.insert(0, "new 1st item");
	assert(l5.getValue(0) == "new 1st item");
	l5.insert(3, "new 3rd item");
	assert(l5.getValue(3) == "new 3rd item");
	l5.insert(5, "new 4th item");
	assert(l5.getValue(5) == "new 4th item");
	assert(l5.getSize() == 8);
	l5.insert(7, "new 5th item");
	assert(l5.getValue(7) == "new 5th item");
	assert(l5.getSize() == 9);  // The capacity grows as the size exceeds 8.

	cout << "Testing remove()..." << endl;
	CS112List<string> l6 = l5;
	assert(l6.remove("new 1st item") == true);
	assert(l6.getValue(0) == "1st item");
	assert(l6.getSize() == 8);  // The size decreases as one item was removed.
	assert(l6.remove("new 3rd item") == true);
	assert(l6.getValue(2) == "3rd item");
	assert(l6.remove("new 4th item") == true);
	assert(l6.getValue(3) == "4th item");
	assert(l6.remove("new 5th item") == true);
	assert(l6.getValue(4) == "5th item");
	assert(l6.getSize() == 5);
	assert(l6.remove("new 6th item") == false);  // "new 6th item" is not in the list, so it should return false.
	assert(l6.getSize() == 5);  // The size doesn't change since nothing was removed.

	cout << "Testing removeAt()..." << endl;
	CS112List<string> l7 = l5;
	assert(l7.removeAt(0) == "new 1st item");
	assert(l7.getValue(0) == "1st item");
	assert(l7.getSize() == 8);  // The size decreases as one item was removed.
	assert(l7.removeAt(-2) == "new 5th item"); // The removeAt also works on python-like index.
	assert(l7.getValue(-2) == "4th item");
	assert(l7.removeAt(-3) == "new 4th item");
	assert(l7.getValue(-3) == "3rd item");
	assert(l7.removeAt(2) == "new 3rd item");
	assert(l7.getValue(2) == "3rd item");
	assert(l7.getSize() == 5);
	try{
		l7.removeAt(5);
	} catch (range_error &e) {
		cout << "Index 5 out of range!" << endl;
	}
	assert(l7.getSize() == 5);    // The size doesn't change since nothing was removed.

	cout << "Testing slice()..." << endl;
	CS112List<int> l8;
	for (int i = 0; i < 10; i++) {
		l8.append(i);
	}

	CS112List<int>test1 = l8.slice(3);
	for (int i = 0; i < 3; i++) {
		assert(test1.getValue(i) == l8.getValue(i));
	}

	CS112List<int>test2 = l8.slice(11);
	for (int i = 0; i < 10; i++) {
		assert(test2.getValue(i) == l8.getValue(i));
	}

	CS112List<int>test3 = l8.slice(-1);
	assert(test3.getSize() == 0);

	CS112List<int>test4 = l8.slice(0,3);
	for (int i = 0; i < 3; i++) {
		assert(test4.getValue(i) == l8.getValue(i));
	}

	CS112List<int>test5 = l8.slice(3,3);
	assert(test5.getSize() == 0);

	CS112List<int>test6 = l8.slice(-1,5);
	for (int i = 0; i < 5; i++) {
		assert(test6.getValue(i) == l8.getValue(i));
	}

	CS112List<int>test7 = l8.slice(4,50);
	for (int i = 0; i < 10 - 4; i++) {
		assert(test7.getValue(i) == i+4);
	}

	CS112List<int>test8 = l8.slice(0,10,3);
	for (int i = 0; i < 10 / 3; i++) {
		assert(test8.getValue(i) == l8.getValue(i * 3));
	}

	CS112List<int>test9 = l8.slice(-1,10,3);
	for (int i = 0; i < 10 / 3; i++) {
		assert(test9.getValue(i) == l8.getValue(i * 3));
	}

	CS112List<int>test10 = l8.slice(0,50,3);
	for (int i = 0; i < 10 / 3; i++) {
		assert(test10.getValue(i) == l8.getValue(i * 3));
	}

	try {
		cout << l8.slice(4,50,0) << endl;
	} catch (invalid_argument &e) {
		cout << "bad step index" << endl;
	}

	cout << "All tests passed!" << endl;
	return 0;
}
