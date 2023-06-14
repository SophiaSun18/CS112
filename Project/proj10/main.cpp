/*
 * Student Name: ZeAi Sun (zs35)
 * Date: Apr 3rd, 2022
 */

#include "BST.h"
#include "BST_Tester.h"
#include <fstream>

int main() {

	// Test the function of BST template.
	BST_Tester bstt;
	bstt.runTests();

	// Read from file and insert all values into the BST.
	string Input;
	BST<long> bst;

	cout << "Enter the file name: ";
	cin >> Input;

	ifstream fin(Input);
	long aLine;
	int dupNum = 0;

	if ( fin.is_open() ) {
		while ( fin.good() ) {     // Check if the stream works without error.
			fin >> aLine;
			try {                         // Catch the exception and calculate the number of duplicate values.
				bst.insert(aLine);
			} catch ( const Exception &se ) {
				dupNum ++;
			}
		}
	}

	cout << "height: " << bst.getHeight() << " duplicate: " << dupNum << endl;

}
