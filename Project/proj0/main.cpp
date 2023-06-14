/* main.cpp
  * Student name: ZeAi Sun
  * Date: January 12, 2022
  * Author: Prof. Victor Norman
  * For: CS 112, Project 0 at Calvin University.
  */

#include <iostream>
#include <string>
using namespace std;

int main() {

	const unsigned int BIG_NUMBER = 10000000;
	string FirstName = "ZeAi";
	char LastName = 'S';
	double PI = 3.1415;
	bool enable = false;
	long number = 0;

	const unsigned int* px1 = &BIG_NUMBER;
	cout << "The location of BIG_NUMBER is: " << px1 << endl;

	string* px2 = &FirstName;
	cout << "The location of FirstName is: " << px2 << endl;

	char* px3 = &LastName;
	cout << "The location of LastName is: " << px3 << endl;

	double* px4 = &PI;
	cout << "The location of PI is: " << px4 << endl;

	bool* px5 = &enable;
	cout << "The location of enable is: " << px5 << endl;

	long* px6 = &number;
	cout << "The location of number is: " << px6 << endl;

	int num = 37;
	cout << "The value of num in decimal is: " << dec << num << endl;
	cout << "The value of num in octal is: " <<oct << num << endl;
	cout << "The value of num in hexadecimal is: " <<hex << num << endl;

	float arr[20];
	cout << "The size of arr is: "<< sizeof arr << endl;

	float* fx = &arr[7];
	arr[7] = 17.771;
	cout << "The value of the 7th item in the array is: "<< arr[7] << endl;
	cout << "The location that the pointer is pointing to is: " << fx << endl;
}
