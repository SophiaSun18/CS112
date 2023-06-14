/*
 * Student.cpp
 *
 *  Created on: Feb 1, 2022
 *      Author: zs35
 */

#include "Student.h"
#include <string>

Student::Student() {
	myName = "";
	myId = 0;
	myGpa = 0.0;
	myMajor = "Undecided";
}

Student::Student(string name, unsigned int id) {
	myName = name;
	myId = id;
	myGpa = 0.0;
	myMajor = "Undecided";
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

string Student::getName(){
	return myName;
}

unsigned int Student::getId(){
	return myId;
}

float Student::getGpa(){
	return myGpa;
}

string Student::getMajor(){
	return myMajor;
}

void Student::setGpa(float newGpa){
	myGpa = newGpa;
}

void Student::setMajor(string newMajor){
	myMajor = newMajor;
}
