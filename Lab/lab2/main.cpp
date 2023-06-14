/* main.cpp
  * Student name: ZeAi Sun(zs35), Palmer Ford(pjf5)
  * Date: January 25, 2022
  * Author: Prof. Victor Norman
  * For: CS 112, Lab 2 at Calvin University.
  */

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "functions.h"
using namespace std;

int main(){

	string fileName;
	unsigned numLines;

	cout << "Enter the file name: ";
	cin >> fileName;
	cout << "Enter the number of lines in the file: ";
	cin >> numLines;

	ifstream fin(fileName);
	assert(fin.is_open());

	int *numbers = new int[numLines];
	for (unsigned i = 0; i < numLines; i++){
		fin >> numbers[i];
	}
	fin.close();

	int dup_number;
	bool result = findDuplicate(numbers, numLines, dup_number);

	if(result == true){
		cout << "There was a duplicate in the file! Its value is " << dup_number << "!" << endl;
	}else{
		cout << "There was no duplicate in the file." << endl;
	}
}
