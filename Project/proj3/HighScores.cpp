#include <iostream>
#include <string>
#include "HighScores.h"
using namespace std;

HighScores::HighScores() {
	for (int i = 0; i < 10; i++){
		myScores[i] = 0;
	}
	myNumScores = 0;
}

HighScores::~HighScores() {
	// TODO Auto-generated destructor stub
}

int HighScores::getNumScores() {
	return myNumScores;
}

void HighScores::addScore (int aScore) {
	int i = findLocationToInsert(aScore);

	if (i != -1) {
		if (myNumScores <= 10) {
			if (aScore != myScores[i]) {
				shiftUp(i);
				myScores[i] = aScore;
			}
		}
		if (myNumScores < 10) {
			myNumScores += 1;
		}
	}
}

int HighScores::getScore (int i) {
	if (i > myNumScores) {
		throw invalid_argument("bad input");
	} else {
		return myScores[i];
	}
}

int HighScores::findLocationToInsert (int newScore) {
	for (int i = 0; i < 10; i++) {
		if (newScore == myScores[i]) {
			return -1;
		} else if (newScore > myScores[i]) {
			return i;
		}
	}
	return -1;
}

void HighScores::shiftUp (int fromIndex) {
	for (int i = 9; i > fromIndex; i--) {
		myScores[i] = myScores[i-1];
	}
}

// The method I set up on my own to print out all values in the array.
void HighScores::printScores() {
	for (int i = 0; i < 10; i++) {
		cout << myScores[i] << endl;
	}
}
