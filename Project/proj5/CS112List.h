/*
 * Student name: Zeai Sun (zs35)
 * Date: 19 Feb
 * Author: Prof. Victor Norman
 * For: CS 112, Project 5 at Calvin University.
 */

#ifndef CS112LIST_H_
#define CS112LIST_H_

#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

template <class Item>

class CS112List {
public:
	CS112List();
	CS112List(int size);
	CS112List(const CS112List<Item> &orig); // copy ctor
	virtual ~CS112List();

	// getters
	int getSize() const;
	Item getValue(int index);
	//	Item & operator[](int index);
	const Item operator[](unsigned index) const;
	Item & operator[](int index) const;

	// setters
	void setValue(int index, const Item &value);

	// others
	void append(const Item &value);
	CS112List<Item> & operator+(const CS112List<Item> &rhs) const;
	int find(Item word) const;
	void insert(int index, Item it);
	bool remove(Item it);
	Item removeAt(int index);
	CS112List<Item> & slice(int stop_index);
	CS112List<Item> & slice(int start_index, int stop_index);
	CS112List<Item> & slice(int start_index, int stop_index, unsigned step_index);

private:
	int mySize;      // number of items in the array
	int myCapacity;  // how much space we have for items
	Item *myArray;   // an array, of course.
	int validate_index(int index) const;
};

#endif /* CS112LIST_H_ */

template <class Item>
CS112List<Item>::CS112List() {
	mySize = 0;
	myCapacity = 0;
	myArray = nullptr;
}

template <class Item>
CS112List<Item>::CS112List(int size) {
	mySize = myCapacity = size;
	myArray = new Item[size]();
}

template <class Item>
CS112List<Item>::CS112List(const CS112List &orig) {
	// cout << "copy ctor called with object " << &orig << endl;
	mySize = orig.mySize;
	myCapacity = orig.myCapacity;
	if (myCapacity == 0) {
		myArray = nullptr;
	} else {
		// deep copy.
		myArray = new Item[mySize]();
		for (int i = 0; i < mySize; i++) {
			myArray[i] = orig.myArray[i];
		}
	}
}

// called when object goes out of scope.
template <class Item>
CS112List<Item>::~CS112List() {
	delete [] myArray;
}

template <class Item>
void CS112List<Item>::append(const Item &value) {
	if (mySize >= myCapacity) {
		// Note: double the capacity, unless it was 0, then make it 1.
		int newCapacity = myCapacity == 0 ? 1 : myCapacity * 2;
		Item *tmp = new Item[newCapacity]();
		for (int i = 0; i < mySize; i++) {
			tmp[i] = myArray[i];
		}
		myCapacity = newCapacity;
		delete[] myArray;
		myArray = tmp;
	}
	myArray[mySize] = value;
	mySize++;
}

template <class Item>
int CS112List<Item>::getSize() const {
	return mySize;
}

template <class Item>
Item CS112List<Item>::getValue(int index){
	return myArray[validate_index(index)];
}

template <class Item>
void CS112List<Item>::setValue(int index, const Item &value) {
	myArray[validate_index(index)] = value;
}

// return a reference to the index-th location.
template <class Item>
const Item CS112List<Item>::operator[](unsigned index) const {
	return myArray[validate_index(index)];
}

template <class Item>
Item & CS112List<Item>::operator[](int index) const {
	return myArray[validate_index(index)];
}

template <class Item>
CS112List<Item> & CS112List<Item>::operator+(const CS112List<Item> &rhs) const {
	CS112List *result = new CS112List(mySize + rhs.mySize);
	for (int i = 0; i < mySize; i++) {
		(*result)[i] = myArray[i];
	}
	for (int i = 0; i < rhs.mySize; i++) {
		(*result)[mySize + i] = rhs[i];
	}
	return *result;
}

template <class Item>
ostream& operator<<(ostream &out, const CS112List<Item> &rhs) {
	out << "[";
	for (int i = 0; i < rhs.getSize(); i++) {
		out << rhs[i];
		if (i < rhs.getSize() - 1) {
			out << ", ";
		}
	}
	out << "]";
	return out;
}

template <class Item>
int CS112List<Item>::validate_index(int index) const{
	if(index >= mySize){
		throw range_error("Index is out of range!");
	} else if (index < 0 - mySize) {
		throw range_error("Index is out of range!");
	} else {
		if (index >= 0){
			return index;
		} else {
			return mySize + index;
		}
	}
}

template <class Item>
int CS112List<Item>::find(Item word) const{
	for (int i = 0; i < mySize; i++){
		if(myArray[i] == word){
			return i;
		}
	}
	return -1;
}

template <class Item>
void CS112List<Item>::insert(int index, Item it){
	if (myCapacity == mySize) {
		myCapacity ++;
	}
	mySize ++;
	for (int i = mySize; i > index; i--) {
		myArray[i] = myArray[i-1];
	}
	myArray[index] = it;
}

template <class Item>
bool CS112List<Item>::remove(Item it) {
	for (int i = 0; i < mySize; i++) {
		if (myArray[i] == it) {
			for (int j = i; j < mySize; j++) {
				myArray[j] = myArray[j+1];
			}
			mySize --;
			return true;
		}
	}
	return false;
}

template <class Item>
Item CS112List<Item>::removeAt(int index) {
	int validIndex = validate_index(index);  // Convert the python-like index (positive or negative) to a valid c++ index (positive).
	Item result = myArray[validIndex];
	//	cout << "result : " << result << endl;
	for (int i = validIndex; i < mySize; i++) {
		myArray[i] = myArray[i+1];
	}
	mySize --;
	return result;
}

template <class Item>
CS112List<Item> & CS112List<Item>::slice(int stop_index) {
	if (stop_index < 0) {
		stop_index = 0;
	} else if (stop_index > mySize) {
		stop_index = mySize;
	}
	CS112List<Item> *result = new CS112List;
	for (int i = 0; i < stop_index; i++) {
		result->append(myArray[i]);
	}
	return *result;
}

template <class Item>
CS112List<Item> & CS112List<Item>::slice(int start_index, int stop_index) {
	if (start_index < 0) {
		start_index = 0;
	} else if (start_index > mySize) {
		start_index = mySize;
	}
	if (stop_index < 0) {
		stop_index = 0;
	} else if (stop_index > mySize) {
		stop_index = mySize;
	}
	CS112List<Item> *result = new CS112List;
	for (int i = start_index; i < stop_index; i++) {
		result->append(myArray[i]);
	}
	return *result;
}

template <class Item>
CS112List<Item> & CS112List<Item>::slice(int start_index, int stop_index, unsigned step_index) {
	if (start_index < 0) {
		start_index = 0;
	} else if (start_index > mySize) {
		start_index = mySize;
	}
	if (stop_index < 0) {
		stop_index = 0;
	} else if (stop_index > mySize) {
		stop_index = mySize;
	}
	if (step_index == 0) {
		throw invalid_argument("bad step index");
	}
	CS112List<Item> *result = new CS112List;
	for (int i = start_index; i < stop_index; i+=step_index) {
		result->append(myArray[i]);
	}
	return *result;
}
