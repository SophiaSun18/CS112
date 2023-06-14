/* App.cpp
 * Student Name: ZeAi Sun (zs35)
 * Date: February, 14
 * Created on: Feb 27, 2020
 * Author: vtn2
 */

#include "App.h"
#include <iostream>
#include "Vec.h"
using namespace std;

App::App() {}

void App::run() {
    unsigned numDims = printInstructions();
    Vec startingPos = getStartingPosition(numDims);
    Vec resultingPos = getVectors(startingPos);
    printResults(startingPos, resultingPos);
}

unsigned App::printInstructions() {
    unsigned numDims;
    cout << "This application simulates how to move through space by\nadding "
            "together any number of vectors of a given size."
         << endl;
    cout << "How many dimensions would you like to work with? ";
    cin >> numDims;
    return numDims;
}

Vec App::getStartingPosition(unsigned numDims) {
    cout << "Enter starting position: " << endl;
    return getVectorFromUser(numDims);
}

Vec App::getVectorFromUser(unsigned numDims) {
    Vec StartP(numDims);
    for (int i = 0; i < numDims; i++) {
    	cin >> StartP[i];
    }
    return StartP;
}

Vec App::getVectors(const Vec& startVec) {
    char yorn;
    Vec res(startVec);
    while (true) {
        cout << "Do you want to enter another vector? (y/n): ";
        cin >> yorn;
        if (yorn == 'y') {
            Vec v = getVectorFromUser(startVec.getSize());
            res = res + v;
        } else {
            break;
        }
    }
    return res;
}

void App::printResults(const Vec &start, const Vec &end) {
    cout << "Starting to calculate for the result..." << endl;

    Vec vec1(start);
    Vec vec2(end);
    Vec result = vec1 + vec2;

    cout << "The staring point is: ";
    for (int i = 0; i < vec1.getSize(); i++) {
    	cout << start[i] << " ";
    }
    cout << endl;

    cout << "The change of position is: ";
    for (int i = 0; i < vec2.getSize(); i++) {
       	cout << end[i] << " ";
       }
    cout << endl;

    cout << "The ending point is: ";
    for (int i = 0; i < result.getSize(); i++) {
    	cout << result[i] << " ";
    }
    cout << endl;
}
