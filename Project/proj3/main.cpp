/*
Student name: ZeAi Sun (zs35)
Date: February 7, 2022
Project name: Project 3
 */

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "HighScores.h"
using namespace std;

int main(){

	// Initialize an object for Step 1-4.

	HighScores score1;

	score1.getNumScores();
	assert(score1.getNumScores() == 0);

	score1.addScore(2);
	score1.addScore(5);
	score1.addScore(3);
	assert(score1.getNumScores() == 3);

	for (int i = 0; i <= 7; i++) {
		score1.addScore(i * 10);
	}
	assert(score1.getNumScores() == 10);

	assert(score1.getScore(0) == 70);
	assert(score1.getScore(5) == 20);
	assert(score1.getScore(9) == 2);

	try {
		score1.getScore(10);
	    assert("bad input");
	} catch (const invalid_argument &ie) {
	    cout << "Index out of range.";
	}

	// Initialize another object for Step 5.

	HighScores score2;

	// The example values used in the project instruction.
	score2.addScore(100);
	score2.addScore(95);
	score2.addScore(93);
	score2.addScore(89);
	score2.addScore(87);
	score2.addScore(70);
	score2.addScore(49);
	score2.addScore(22);
	score2.addScore(19);
	score2.addScore(17);

	assert(score2.getNumScores() == 10);

	// 77 will take the place of 70 and 17 will be thrown out of the array.
	score2.addScore(77);
	assert(score2.getScore(5) == 77);
	assert(score2.getNumScores() == 10);

	// 101 will take the place of 100 and 19 will be thrown out of the array.
	score2.addScore(101);
	assert(score2.getScore(0) == 101);
	assert(score2.getNumScores() == 10);

	// 5 will not be stored because it's smaller than the 9th value 22.
	score2.addScore(5);
	assert(score2.getScore(9) != 5);
	assert(score2.getNumScores() == 10);

	// 77 will not be stored again because it's already in the array.
	score2.addScore(77);
	assert(score2.getScore(6) == 77);
	assert(score2.getNumScores() == 10);

	cout << "All tests passed!" << endl;

	return 0;
}
