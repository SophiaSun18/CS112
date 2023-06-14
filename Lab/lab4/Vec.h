/* Vec.h provides a simple vector class named Vec.
 * Student Name: ZeAi Sun (zs35)
 * Date: February, 8
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	// The constructors.
	Vec();
	Vec(unsigned value);
	Vec(const Vec& original);

	// The destructor.
	virtual ~Vec();

	// The assignment operator.
	Vec& operator=(const Vec& original);

	// The getters.
	unsigned getSize() const;
	Item getItem(unsigned index) const;

	// The setters.
	void setSize(unsigned newSize);
	void setItem(unsigned index, const Item& it);

	// The equality operator.
	bool operator==(const Vec& v2) const;

	// The file input and output.
	void writeTo(ostream& out) const;
	void readFrom(istream& in);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
