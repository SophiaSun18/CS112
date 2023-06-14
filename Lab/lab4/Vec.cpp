/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: ZeAi Sun (zs35)
 * Date: February, 8
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"

Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}

Vec::Vec(unsigned size) {
	mySize = size;
	if (size > 0) {
		myArray = new Item[size];
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = 0;
		}
	} else {
		myArray = nullptr;
	}
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (mySize > 0) {
		myArray = new Item[mySize]();
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

Vec::~Vec() {
	delete[] myArray;
	myArray = nullptr;
	mySize = 0;
}

Vec& Vec::operator=(const Vec& original) {
	mySize = original.mySize;
	if (mySize > 0) {
		myArray = new Item[mySize]();
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
	return *this;
}

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize) {
		throw range_error("bad index");
	} else {
		myArray[index] = it;
	}
}

Item Vec::getItem(unsigned index) const {
	if (index >= mySize) {
		throw range_error("bad index");
	} else {
		return myArray[index];
	}
}

void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete[] myArray;
			myArray = nullptr;
			mySize = 0;
		} else {
			Item * newArray = new Item[newSize]();
			if (mySize < newSize) {
				for (unsigned i = 0; i < mySize; i++) {
					newArray[i] = myArray[i];
				}
				for (unsigned i = mySize; i < newSize; i++) {
					newArray[i] = 0;
				}
			} else {
				for (unsigned i = 0; i < newSize; i++) {
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete[] myArray;
			myArray = newArray;
		}
	}
}

bool Vec::operator==(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return false;
	} else {
		if (mySize == 0) {
			return true;
		} else {
			for (unsigned i = 0; i < mySize; i++) {
				if (myArray[i] != v2.myArray[i]) {
					return false;
				}
			}
			return true;
		}
	}
}

void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}

void Vec::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}
