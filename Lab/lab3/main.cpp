/* main.cpp
  * Student name: ZeAi Sun(zs35)
  * Date: February 1, 2022
  * Author: Prof. Victor Norman
  * For: CS 112, Lab 3 at Calvin University.
  */

#include <iostream>
#include <string>
#include <cassert>
#include "Student.h"
#include "Fraction.h"
using namespace std;

int main(){

	Student aStudent;

	assert(aStudent.getName() == "");
	assert(aStudent.getId() == 0);
	assert(aStudent.getGpa() == 0.0);
	assert(aStudent.getMajor() == "Undecided");

	aStudent.setGpa(4.0);
	assert(aStudent.getGpa() == 4.0);
	aStudent.setMajor("CS");
	assert(aStudent.getMajor() == "CS");

	Student bStudent("Sophia", 35);

	assert(bStudent.getName() == "Sophia");
	assert(bStudent.getId() == 35);
	assert(bStudent.getGpa() == 0.0);
	assert(bStudent.getMajor() == "Undecided");

	// Part 2 tests

	Fraction aFraction;
	Fraction bFraction(2, 4);
	// The test cases of bFraction returns error after the simplify() method was added into the Fraction class.

	assert(aFraction.getNumerator() == 0);
	assert(aFraction.getDenominator() == 1);

//	assert(bFraction.getNumerator() == 2);
//	assert(bFraction.getDenominator() == 4);

	aFraction.setNumerator(1);
	assert(aFraction.getNumerator() == 1);
	aFraction.setDenominator(2);
	assert(aFraction.getDenominator() == 2);

//	bFraction.setNumerator(3);
//	assert(bFraction.getNumerator() == 3);
//	bFraction.setDenominator(6);
//	assert(bFraction.getDenominator() == 6);

	try {
	    aFraction.setDenominator(0);
	    assert(false);
	} catch (const invalid_argument &ie) {
	    assert(aFraction.getDenominator() != 0);
	}

	assert(aFraction.asString() == "1/2");
//	assert(bFraction.asString() == "3/6");
	aFraction.setNumerator(3);
	assert(aFraction.asString() == "3/2");

	Fraction cFraction(3, 6);
	assert(cFraction.asString() == "1/2");

	cFraction.setNumerator(8);
	assert(cFraction.asString() == "4/1");

	cFraction.setDenominator(12);
	assert(cFraction.asString() == "1/3");

	cout << "All tests passed!" << endl;
	return 0;
}
