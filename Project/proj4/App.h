/* App.h
 * Student Name: ZeAi Sun (zs35)
 * Date: February, 14
 * Created on: Feb 27, 2020
 * Author: vtn2
 */


/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: ZeAi Sun (zs35)
 * Date: February, 14
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */
#ifndef APP_H_
#define APP_H_

#include "Vec.h"

class App {
public:
	App();
	void run();

private:
	unsigned printInstructions();
	Vec getStartingPosition(unsigned numDims);
	Vec getVectors(const Vec & startVec);
	void printResults(const Vec &start, const Vec &end);
	Vec getVectorFromUser(unsigned numDims);
};

#endif /* APP_H_ */
