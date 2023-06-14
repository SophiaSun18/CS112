/*
 * Fraction.cpp
 *
 *  Created on: Feb 1, 2022
 *      Author: zs35
 */

#include <string>
#include <stdexcept>
#include <cstdlib>
#include "Fraction.h"
using namespace std;

/*
 *  (int, int) -> int
 *  This function finds the greatest common divisor of two integers, using
 *  Euclid's algorithm
 */
int computeGCD(int alpha, int beta) {
    alpha = abs(alpha);
    beta = abs(beta);
    int remainder = alpha % beta;
    while (remainder != 0) {
        alpha = beta;
        beta = remainder;
        remainder = alpha % beta;
    }
    return beta;
}

Fraction::Fraction() {
	myNumerator = 0;
	myDenominator = 1;
	simplify();
}

Fraction::Fraction(int numerator, int denominator) {
	myNumerator = numerator;
	myDenominator = denominator;
	simplify();
}

Fraction::~Fraction() {
	// TODO Auto-generated destructor stub
}

int Fraction::getNumerator(){
	return myNumerator;
}

int Fraction::getDenominator(){
	return myDenominator;
}

void Fraction::setNumerator(int newNumerator){
	myNumerator = newNumerator;
	simplify();
}

void Fraction::setDenominator(int newDenominator){
	if (newDenominator == 0){
		throw invalid_argument("bad denominator");
	}else{
		myDenominator = newDenominator;
	}
	simplify();
}

string Fraction::asString(){
	return to_string(myNumerator) + "/" + to_string(myDenominator);
}

void Fraction::simplify(){
	int gcd = computeGCD(myNumerator, myDenominator);

	if(gcd != 0){
		myNumerator = myNumerator / gcd;
		myDenominator = myDenominator / gcd;
	}else if (gcd < 0){
		myNumerator = myNumerator * -1;
		myDenominator = myDenominator * -1;
	}
}
