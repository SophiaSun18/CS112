/*
Student name: ZeAi Sun (zs35)
Date: January 29, 2022
Project name: Project 2
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

int main(){

	// Initialize the two-dimensional arrays and set the default value of all values inside the array to 0.
	int i = 15;
	int matrix[15][15] = { 0 };

	// Receive an integer from the user and check if the integer is odd and less than or equal to 15.
	cout << "Enter an odd positive integer that is less than 15: ";
	cin >> i;

	if (i > 15){
		cout << "Sorry! The integer is greater than 15!";
		i = 15;
	}else{
		if (i%2 == 0){
			cout << "Sorry! The integer is not an odd number!";
			i = 15;
		}
	}

	// Set up the position of 1 to the middle of the first row.
	int rows = 0;
	int cols = i/2;

	// Run the for loop i * i times and assign an integer to every value of the array.
	for (int times = 1; times <= i * i; times ++){

		// If the value is on the upper-right corner, then set the position of the next value under it.
		if (rows == 0 and cols == i - 1){
			matrix[rows][cols] = times;
			rows += 1;
		}else{

			// If the position of the next value is the default value, then set up the new value to the next integer.
			if (matrix[rows][cols] == 0){
				matrix[rows][cols] = times;
			}else{
				// If the position of the next value is occupied, then set the position of the next value under the last one.
				rows += 2;
				cols -= 1;
				matrix[rows][cols] = times;
			}

			// If reaching the top row, then set the position of the next value to the last row.
			if (rows - 1 < 0) {
				rows = i - 1;
			}else{
				// If not reaching the top row, then set the position of the next value to the upper row.
				rows = rows - 1;
			}

			// If reaching the most right column, then set the position of the next value to the first row.
			if (cols + 1 == i) {
				cols = 0;
			}else{
				// If not reaching to the most right column, then set the position of the next value one column to the right.
				cols = cols + 1;
			}
		}

	}

	// Print out the matrix.
	for (int x = 0; x < i; x++){
		for (int y = 0; y < i; y++){
			cout << setw(2) << matrix [x][y] << " ";
		}
		cout << endl;
	}

}
