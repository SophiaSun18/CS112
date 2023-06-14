/* main.cpp is the driver for a Conga line simulation.
 *
 * @author: Joel Adams, for CS 112 at Calvin University.
 *
 * Based on an exercise by Marc LeBlanc from Wheaton College (MS).
 *
 * Student name: Zeai Sun (zs35)
 * Date: Mar 14
 */

#include "CongaLine.h"
#include "ListTester.h"

int main() {
	CongaLine dance("Ann", "Bob");
	ListTester test;
	test.runTests();
	dance.run();
}
