/*
 * Fraction.h
 *
 *  Created on: Feb 1, 2022
 *      Author: zs35
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include <string>
using namespace std;

class Fraction {
public:
	Fraction();
	Fraction(int numerator, int denominator);
	virtual ~Fraction();

	int myNumerator;
	int myDenominator;

	int getNumerator();
	int getDenominator();

	void setNumerator(int newNumerator);
	void setDenominator(int newDenominator);

	string asString();

private:
	void simplify();
};

#endif /* FRACTION_H_ */
