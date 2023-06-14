 /* Student name: Haocheng Jin (hj55) and Zeai Sun (zs35)
  * Date: 15 Feb
  * Author: Prof. Victor Norman
  * For: CS 112, Lab 5 at Calvin University.
  */
 
#include "VecTester.h"
#include <iostream>     // cout, cerr, ...
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // range_error, ...
using namespace std;

void VecTester::runTests() const {
	cout << "Testing class Vec" << endl;
	testDefaultConstructor();
	testExplicitConstructor();
	testCopyConstructor();
	testDestructor();
	testAssignment();
	testSetSize();
	testGetSize();
	testSetItem();
	testGetItem();
	testEquality();
	testWriteToStream();
	testReadFromStream();
	testSubscript();
//	testInequality();
	testAddition();
	testSubtraction();
//	testReadFromFile();
//	testWriteToFile();
	cout << "All tests passed!" << endl;
}

void VecTester::testDefaultConstructor() const {
	cout << "Testing default constructor... " << flush;
	Vec<double> v;
	assert( v.mySize == 0 );
	assert( v.myArray == nullptr );
	cout << "Passed!" << endl;
}

void VecTester::testExplicitConstructor() const {
	cout << "Testing explicit constructor... " << flush;
	cout << " 1 " << flush;
	Vec<double> v1(3);
	assert( v1.mySize == 3 );
	assert( v1.myArray != nullptr );
	for (int i = 0; i < 3; ++i) {
		assert( v1.myArray[i] == 0 );
	}
	cout << " 2 " << flush;
	Vec<double> v2(8);
	assert( v2.mySize == 8 );
	assert( v2.myArray != nullptr );
	for (int i = 0; i < 8; ++i) {
		assert( v2.myArray[i] == 0 );
	}
	cout << "Passed!" << endl;
}

void VecTester::testCopyConstructor() const {
	cout << "Testing copy constructor..." << flush;
	cout << " 1 " << flush;
	Vec<double> v1;
	Vec<double> v2(v1);
	assert( v2.mySize == 0 );
	assert( v2.myArray == nullptr );

	cout << " 2 " << flush;
	Vec<double> v3(5);
	Vec<double> v4(v3);
	assert(v4.mySize == 5);
	assert(v4.myArray != nullptr );
	assert(v4.myArray != v3.myArray);
	for (unsigned i = 0; i < 5; ++i) {
		assert( v4.myArray[i] == 0 );
	}

	cout << " 3 " << flush;
	Vec<double> v5(5);
	for (unsigned i = 0; i < 5; ++i) {
		v5.myArray[i] = (i+1);
	}
	Vec<double> v6(v5);
	assert( v6.mySize == 5 );
	assert( v6.myArray != nullptr );
	assert( v6.myArray != v5.myArray );
	for (unsigned i = 0; i < 5; ++i) {
		assert( v6.myArray[i] == v5.myArray[i] );
	}
	cout << "Passed!" << endl;
}

void VecTester::testDestructor() const {
	cout << "Testing destructor... " << flush;
	Vec<double> v(5);
	v.~Vec();
	assert( v.mySize == 0 );
	assert( v.myArray == nullptr );
	cout << "Passed, but make sure ~Vec() is returning the array's memory to the system!" << endl;
}

void VecTester::testAssignment() const {
	cout << "Testing =..." << flush;
	// empty-to-empty
	Vec<double> v, v0;
	v = v0;
	assert(v.mySize == 0);
	assert(v.myArray == nullptr );
	cout << " 0 " << flush;
	// empty-to-nonempty
	Vec<double> v1;
	Vec<double> v2(5);
	v2 = v1;
	assert(v2.mySize == 0);
	assert(v2.myArray == nullptr );
	cout << " 1 " << flush;
	// nonempty-to-empty
	Vec<double> v3(5);
	for (unsigned i = 0; i < 5; ++i) {
		v3.myArray[i] = (i+1);
	}
	Vec<double> v4;
	v4 = v3;
	assert( v4.mySize == 5 );
	assert( v4.myArray != v3.myArray );
	for (unsigned i = 0; i < 5; ++i) {
		assert( v4.myArray[i] == (i+1) );
	}
	cout << " 2 " << flush;
	// nonempty-to-nonempty (larger into smaller)
	Vec<double>  v5(2);
	for (unsigned i = 0; i < 2; ++i) {
		v5.myArray[i] = (i+1)*10;
	}
	v5 = v3;
	assert(v5.mySize == 5);
	assert(v5.myArray != v3.myArray);
	for (unsigned i = 0; i < 5; ++i) {
		assert( v5.myArray[i] == (i+1) );
	}
	cout << " 3 " << flush;
	// nonempty-to-nonempty (smaller into larger)
	Vec<double>  v6(7);
	for (unsigned i = 0; i < 7; ++i) {
		v6.myArray[i] = (i+1)*10;
	}
	v6 = v3;
	assert(v6.mySize == 5);
	assert(v6.myArray != v3.myArray);
	for (unsigned i = 0; i < 5; ++i) {
		assert( v6.myArray[i] == (i+1) );
	}
	cout << " 4 " << flush;
	// nonempty-to-nonempty (equal sized)
	Vec<double>  v7(5);
	for (unsigned i = 0; i < 5; ++i) {
		v7.myArray[i] = (i+1)*10;
	}
	v7 = v3;
	assert(v7.mySize == 5);
	assert(v7.myArray != v3.myArray);
	for (unsigned i = 0; i < 5; ++i) {
		assert( v7.myArray[i] == (i+1) );
	}
	cout << " 5 " << flush;
	// assignment chaining
	Vec<double>  v8;
	Vec<double>  v9(4);
	v9 = v8 = v3;
	assert( v9.mySize == 5 );
	assert( v9.mySize == 5 );
	assert( v8.myArray != v3.myArray );
	assert( v8.myArray != v3.myArray );
	assert( v9.myArray != v8.myArray );
	for (unsigned i = 0; i < 5; ++i) {
		assert( v8.myArray[i] == (i+1) );
		assert( v9.myArray[i] == (i+1) );
	}
	cout << " 6 " << flush;
	// self-assignment (idiotic but legal)
	v3 = v3;
	assert( v3.mySize == 5 );
	assert( v3.myArray != nullptr );
	for (unsigned i = 0; i < 5; ++i) {
		assert(v3.myArray[i] == (i+1) );
	}
	cout << " 7 " << flush;
	cout << "Passed!" << endl;
}

void VecTester::testSetSize() const {
	cout << "Testing setSize()..." << flush;
	// empty
	Vec<double>  v0;
	v0.setSize(3);
	assert( v0.getSize() == 3 );
	for (unsigned i = 0; i < 3; ++i) {
		assert( v0.getItem(i) == 0 );
	}
	cout << " 0 " << flush;
	// non-empty, increasing
	Vec<double>  v1(5);
	for (unsigned i = 0; i < 5; ++i) {
		v1.setItem(i, i+1);
	}
	v1.setSize(8);
	assert( v1.getSize() == 8 );
	for (unsigned i = 0; i < 5; ++i) {
		assert( v1.getItem(i) == (i+1) );
	}
	for (unsigned i = 5; i < 8; ++i) {
		assert( v1.getItem(i) == 0 );
	}
	cout << " 1 " << flush;
	// non-empty, decreasing
	Vec<double>  v2(5);
	for (unsigned i = 0; i < 5; ++i) {
		v2.setItem(i, i+1);
	}
	v2.setSize(3);
	assert( v2.getSize() == 3 );
	for (unsigned i = 0; i < 3; ++i) {
		assert( v2.getItem(i) == (i+1) );
	}
	cout << " 2 " << flush;
	// non-empty, equal
	Vec<double>  v3(5);
	for (unsigned i = 0; i < 5; ++i) {
		v3.setItem(i, i+1);
	}
	v3.setSize(5);
	assert( v3.getSize() == 5 );
	for (unsigned i = 0; i < 5; ++i) {
		assert( v3.getItem(i) == (i+1) );
	}
	cout << " 3 " << flush;
	// set size to zero
	v3.setSize(0);
	assert( v3.getSize() == 0 );
	assert( v3.myArray == nullptr );
	cout << " 4 " << flush;
	cout << "Passed!" << endl;
}

void VecTester::testGetSize() const {
	cout << "Testing getSize()..." << flush;
	Vec<double>  v1;
	assert( v1.getSize() == 0 );
	cout << " 1 " << flush;
	Vec<double>  v2(5);
	assert( v2.getSize() == 5 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void VecTester::testSetItem() const {
	cout << "Testing setItem()... " << flush;
	// empty case
	Vec<double>  v0;
	try {
		v0.setItem(0, 11);
		cerr << "setItem() succeeded on empty Vec";
		exit(1);
	} catch (range_error&) {
		cout << " 0 " << flush;
	}
	// nonempty case, valid subscript
	Vec<double>  v(5);
	for (unsigned i = 0; i < 5; ++i) {
		v.setItem(i, i+1);
	}
	for (unsigned i = 0; i < 5; ++i) {
		assert( v.myArray[i] == (i+1) );
	}
	cout << " 1 " << flush;
	// nonempty case, invalid subscript
	Vec<double>  v2(3);
	try {
		v2.setItem(3, 33);
		cerr << "setItem() succeeded beyond end of Vec";
		exit(1);
	} catch (range_error&) {
		cout << " 2 " << flush;
	}
	cout << "Passed!" << endl;
}

void VecTester::testGetItem() const {
	cout << "Testing getItem()... " << flush;
	// empty Vec
	Vec<double>  v0;
	try {
		v0.getItem(0);
		cerr << "getItem() succeeded on empty Vec";
		exit(1);
	} catch (range_error&) {
		cout << " 0 " << flush;
	}
	// non-empty, valid access
	Vec<double>  v(5);
	for (unsigned i = 0; i < 5; ++i) {
		v.setItem(i, i+1);
	}
	for (unsigned i = 0; i < 5; ++i) {
		assert( v.getItem(i) == (i+1) );
	}
	cout << " 1 " << flush;
	// nonempty Vec, invalid index
	Vec<double>  v2(3);
	try {
		v2.getItem(3);
		cerr << "getItem() succeeded beyond end of Vec";
		exit(1);
	} catch (range_error&) {
		cout << " 2 " << flush;
	}
	cout << "Passed!" << endl;
}


void VecTester::testEquality() const {
	cout << "Testing ==..." << flush;
	// empty case
	Vec<double>  v1;
	Vec<double>  v2;
	assert( v1 == v2 );
	cout << " 1 " << flush;
	// nonempty, same size, default values
	Vec<double>  v3(5);
	Vec<double>  v4(5);
	assert( v3 == v4 );
	cout << " 2 " << flush;
	// nonempty, same size, set values
	Vec<double>  v5(5);
	Vec<double>  v6(5);
	for (unsigned i = 0; i < 5; ++i) {
		v5.setItem(i, i+1);
		v6.setItem(i, i+1);
	}
	assert( v5 == v6 );
	cout << " 3 " << flush;
	// empty vs nonempty
	Vec<double>  v7;
	Vec<double>  v8(5);
	assert( !(v7 == v8) );
	cout << " 4 " << flush;
	// nonempty, same size, first value different
	Vec<double>  v9(5);
	Vec<double>  v10(5);
	Vec<double>  v11(5);
	Vec<double>  v12(5);
	v10.setItem(0, 1);
	assert( !(v9 == v10) );
	cout << " 5 " << flush;
	// nonempty, same size, middle value different
	v11.setItem(2, 1);
	assert( !(v9 == v11) );
	cout << " 6 " << flush;
	// nonempty, same size, last value different
	v12.setItem(4, 1);
	assert( !(v9 == v12) );
	cout << " 7 " << flush;

	cout << "Passed!" << endl;
}

void VecTester::testWriteToStream() const {
      cout << "Testing writeTo(ostream)... " << flush;
      Vec<double> v1(5);
      for (unsigned i = 0; i < 5; ++i) {
              v1.setItem(i, i+10);
      }
      // write to an ofstream instead of cout, to automate the test
      ofstream fout("vecStreamOut.txt");
      assert( fout.is_open() );
      fout << v1.getSize() << "\n";
      v1.writeTo(fout);
      fout.close();
      // now read in what we just wrote...
      ifstream fin("vecStreamOut.txt");
      assert( fin.is_open() );
      unsigned size;
      fin >> size;
      assert( size == 5 );
      double value;
      for (unsigned i = 0; i < 5; ++i) {
              fin >> value;
              assert( value == i+10 );
      }
      cout << "Passed! See 'vecStreamOut.txt' for values..." <<
      endl;
}

void VecTester::testReadFromStream() const {
      cout << "Testing readFrom(istream)... " << flush;
      // an ifstream is-an istream, so use one to automate the test
      ifstream fin("vecStreamOut.txt");
      assert( fin.is_open() );
      // get the size and build the Vec
      unsigned size;
      fin >> size;
      assert( size == 5 );
      Vec<double> v(size);
      // test readFrom()
      v.readFrom(fin);
      for (unsigned i = 0; i < 5; ++i) {
              assert( v.getItem(i)== i+10 );
      }
      fin.close();
      cout << "Passed!" << endl;
}


void VecTester::testSubscript() const {
	cout << "Testing subscript... " << flush;
	// empty case
	Vec<unsigned> v0;
	try {
		v0[0];
		cerr << "Subscript worked on empty Vec";
		exit(1);
	} catch (const range_error& re) {
		cout << " 0 " << flush;
	}
	// non-empty case, write version
	Vec<unsigned> v1(3);
	v1[0] = 11;
	v1[1] = 22;
	v1[2] = 33;
	assert( v1.getItem(0) == 11 );
	assert( v1.getItem(1) == 22 );
	assert( v1.getItem(2) == 33 );
	cout << " 1 " << flush;
	cout << " Passed!" << endl;
}

//
//void VecTester::testInequality() const {
//	cout << "Testing !=... " << flush;
//
//	// empty
//	Vec<double>  v0;
//	Vec<double>  v1;
//	assert( !(v0 != v1) );
//	cout << " 0 " << flush;
//
//	// empty vs nonempty
//	Vec<double>  v2(3);
//	assert( v1 != v2 );
//	cout << " 1 " << flush;
//
//	// equal sized, same values
//	Vec<double>  v3(3);
//	Vec<double>  v4(3);
//	assert( !(v3 != v4) );
//	cout << " 2 " << flush;
//
//	// equal sized, different values
//	for (unsigned i = 0; i < 3; ++i) {
//		v4.myArray[i] = i+1;
//	}
//	assert( v3 != v4 );
//	cout << " 3 " << flush;
//
//	// equal sized, same except first
//	for (unsigned i = 0; i < 3; ++i) {
//		v3.myArray[i] = i+1;
//	}
//	v3.myArray[0] = 0;
//	assert( v3 != v4 );
//	cout << " 4 " << flush;
//
//	// equal sized, same except middle
//	v3.myArray[0] = 1;
//	v3.myArray[1] = 0;
//	assert( v3 != v4 );
//	cout << " 5 " << flush;
//
//	// equal sized, same except last
//	v3.myArray[1] = 2;
// 	v3.myArray[2] = 0;
//	assert( v3 != v4 );
//	cout << " 6 " << flush;
//
//	// equal sized, equal
//	v3.myArray[2] = 3;
//	assert( !(v3 != v4) );
//	cout << " 7 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
void VecTester::testAddition() const {
	cout << "Testing +... " << flush;
	// nonempty
	Vec<double>  v1(3);
	Vec<double>  v2(3);
	v1.setItem(0, 1);
	v1.setItem(1, 2);
	v1.setItem(2, 3);
	v2.setItem(0, 2);
	v2.setItem(1, 4);
	v2.setItem(2, 6);
	Vec<double>  v3 = v1 + v2;
	assert( v3.getItem(0) == 3 );
	assert( v3.getItem(1) == 6 );
	assert( v3.getItem(2) == 9 );
	cout << " 1 " << flush;
	// empty
	Vec<double>  v4, v5;
	v3 = v4 + v5;
	assert( v3.getSize() == 0 );
	assert( v3.myArray == nullptr );
	cout << " 2 " << flush;
	// different sizes
	try {
		v3 = v2 + v4;
		cerr << "v2 + v4 succeeded for Vecs of different sizes";
		exit(1);
	} catch (invalid_argument&) {
		cout << " 3 " << flush;
	}
	cout << "Passed!" << endl;
}

void VecTester::testSubtraction() const {
	cout << "Testing -... " << flush;
	// nonempty
	Vec<double>  v1(3);
	Vec<double>  v2(3);
	v1.setItem(0, 1);
	v1.setItem(1, 2);
	v1.setItem(2, 3);
	v2.setItem(0, 2);
	v2.setItem(1, 4);
	v2.setItem(2, 6);
	Vec<double>  v3 = v1 - v2;
	assert( v3.getItem(0) == -1 );
	assert( v3.getItem(1) == -2 );
	assert( v3.getItem(2) == -3 );
	cout << " 1 " << flush;
	// empty
	Vec<double>  v4, v5;
	v3 = v4 - v5;
	assert( v3.getSize() == 0 );
	assert( v3.myArray == nullptr );
	cout << " 2 " << flush;
	// different sizes
	try {
		v3 = v2 - v4;
		cerr << "v2 - v4 succeeded for Vecs of different sizes";
		exit(1);
	} catch (invalid_argument&) {
		cout << " 3 " << flush;
	}
	cout << "Passed!" << endl;
}
//
//void VecTester::testReadFromFile() const {
//      cout << "Testing readFrom()... " << flush;
//      Vec<double> v1;
//      v1.readFrom("vecTest1.txt");
//      assert( v1.getSize() == 3 );
//      assert( v1.myArray != nullptr );
//      assert( v1.getItem(0) == 1 );
//      assert( v1.getItem(1) == 2 );
//      assert( v1.getItem(2) == 3 );
//      cout << " 1 " << flush;
//
//      Vec<double> v2(5);
//      double* oldAddr = v2.myArray;
//      v2.readFrom("vecTest2.txt");
//      assert( v2.getSize() == 4 );
//      cout << " 2 " << flush;
//      assert( v2.myArray != nullptr );
//      assert( v2.getItem(0) == 2 );
//      assert( v2.getItem(1) == 4 );
//      assert( v2.getItem(2) == 6 );
//      assert( v2.getItem(3) == 8 );
       /* the following assertion assumes that the new array's base
        *  address is different from the old array's base address,
        *  which may not be true. If your method seems to be right,
        *  is correctly using delete to deallocate the old array,
        *  and passes all assertions except this one, you may
        *  comment out this assertion.
        */
//      assert( v2.myArray != oldAddr );
//      cout << " 3 " << flush;
//      cout << "Passed! Make sure your method closed the file..." << endl;
//}
//
//void VecTester::testWriteToFile() const {
//      cout << "Testing writeTo()... " << flush;
//      // read a vector we know into an empty Vec...
//      Vec<double> v1;
//      v1.readFrom("vecTest1.txt");
//      // make a copy of it in a different file
//      v1.writeTo("vecTest1Copy.txt");
//      cout << " 1 " << flush;
//      cout << "vecTest1Copy.txt created " << flush;
//      // read in the copy, and check it
//      Vec<double> v3;
//      v3.readFrom("vecTest1Copy.txt");
//      assert( v3.getSize() == 3 );
//      assert( v3.myArray != nullptr );
//      assert( v3.getItem(0) == 1 );
//      assert( v3.getItem(1) == 2 );
//      assert( v3.getItem(2) == 3 );
//      cout << " 2 " << flush;
//
//      // read a vector we know into a nonempty Vec...
//      Vec<double> v2(5);
//      v2.readFrom("vecTest2.txt");
//      // make a copy of it in a different file
//      v2.writeTo("vecTest2Copy.txt");
//      cout << " 3 " << flush;
//      cout << "vecTest2Copy.txt created " << flush;
//      // read in the copy and check it
//      v3.readFrom("vecTest2Copy.txt");
//      assert( v3.getSize() == 4 );
//      assert( v3.myArray != nullptr );
//      assert( v3.getItem(0) == 2 );
//      assert( v3.getItem(1) == 4 );
//      assert( v3.getItem(2) == 6 );
//      assert( v3.getItem(3) == 8 );
//      cout << " 4 " << flush;
//      cout << "Passed!  Make sure you closed the file..." << endl;
//}

