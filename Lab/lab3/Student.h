/*
 * Student.h
 *
 *  Created on: Feb 1, 2022
 *      Author: zs35
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
using namespace std;

class Student {
public:
	Student();
	Student(string name, unsigned int id);
	virtual ~Student();

	string getName();
	unsigned int getId();
	float getGpa();
	string getMajor();

	void setGpa(float newGpa);
	void setMajor(string newMajor);

private:
	string myName;
	unsigned int myId;
	float myGpa;
	string myMajor;
};

#endif /* STUDENT_H_ */
