/* Vec.h
  * Student name: Haocheng Jin (hj55) and Zeai Sun (zs35)
  * Date: 15 Feb
  * Author: Prof. Victor Norman
  * For: CS 112, Lab 5 at Calvin University.
  */

#ifndef VEC_H_
#define VEC_H_

#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;

template <class Item>

class Vec {
public:
	Vec();
	virtual ~Vec();
	Vec(unsigned size);
	Vec(const Vec<Item>& original);
	Vec<Item>& operator=(const Vec<Item>& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec<Item>& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	const Item &operator[](unsigned index) const;
	Item &operator[](unsigned index);
	Vec<Item> operator+(const Vec<Item> &v) const;
	Vec<Item> operator-(const Vec<Item> &v) const;
	//	void readFrom(istream& in);
	//	void writeTo(string out_file) const;

private:
	unsigned mySize;
	Item *myArray;
	friend class VecTester;
};

template <class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = nullptr;
}

template <class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	if(size > 0) {
		myArray = new Item [size]();
	} else {
		myArray = nullptr;
	}
}

template <class Item>
Vec<Item>::Vec(const Vec<Item> &original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray = new Item[mySize];

		for (int i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}

}

template <class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (mySize != original.mySize) {
		if (mySize > 0) {
			delete[] myArray;
			myArray = nullptr;
		}
		if (original.mySize > 0) {
			myArray = new Item [original.mySize];
		}
		mySize = original.mySize;
	}
	for (int i = 0; i < mySize; i++) {
		myArray[i] = original.myArray[i];
	}
	return *this;
}


template <class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}
template <class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index >= mySize || index < 0) {
		throw range_error("");
	}
	myArray[index] = it;
}

template <class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (index >= mySize || index < 0) {
		throw range_error("");
	}
	return myArray[index];
}

template <class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if(newSize == 0) {
			delete[] myArray;
			myArray = nullptr;
			mySize = 0;
		} else {
			Item* newArray = new Item[newSize]();
			if (mySize < newSize) {
				for (int i = 0; i < mySize; i++){
					newArray[i] = myArray[i];
				}
			} else {
				for (int i = 0; i < newSize; i++){
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete[] myArray;
			myArray = newArray;
		}
	}
}
template <class Item>
bool Vec<Item>::operator==(const Vec& v2) const {
	if(mySize != v2.mySize){
		return false;
	} else {
		for (int i = 0; i < mySize; i++){
			if (myArray[i] != v2.myArray[i]){
				return false;
			}
		}
	}
	return true;
}

template <class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (int i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}
template <class Item>
void Vec<Item>::readFrom(istream& in) {
	int i = 0;
	while(in >> myArray[i]){
		i++;
	}
}

////project 4 start
////Subscript
template <class Item>
const Item &Vec<Item>::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("index out of range");
	}
	return myArray[index];
}

template <class Item>
Item &Vec<Item>::operator[](unsigned index){
	if (index >= mySize) {
		throw range_error("index out of range");
	}
	return myArray[index];
}


////readFrom
//template <class Item>
//void Vec<Item>::readFrom(string in_file) {
//  ifstream fin(in_file);
//  unsigned size;
//  fin >> size;
//  setSize(size);
//  readFrom(fin);
//  fin.close();
//}
//template <class Item>
////writeTo
//void Vec<Item>::writeTo(string out_file) const {
//  ofstream fout(out_file);
//  fout << getSize() << "\n";
//  writeTo(fout);
//  fout.close();
//}

//
//Addition
template <class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item> &v) const {
	if (mySize != v.mySize) {
		throw std::invalid_argument("Vectors are not the same size.");
	}
	Vec temp(mySize);
	for( unsigned i=0; i<mySize; i++) {
		temp.setItem(i, myArray[i] + v.getItem(i));
	}
	return temp;
}

//Subtraction
template <class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item> &v) const {
	if (mySize != v.mySize) {
		throw std::invalid_argument("Vectors are not the same size.");
	}
	Vec temp(mySize);
	for( unsigned i=0; i<mySize; i++) {
		temp.setItem(i, myArray[i] - v.getItem(i));
	}
	return temp;
}


template <class Item>
Vec<Item>::~Vec() {
	delete[] myArray;
	myArray = nullptr;
	mySize = 0;
}

#endif /*VEC_H_*/
