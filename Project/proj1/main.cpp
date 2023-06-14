#include <iostream>
#include <string>
#include <assert.h>
#include "utils.h"
using namespace std;

void findNPrimes(unsigned primes[], unsigned size){

	int num = 0;

	for (int x = 1; num * 4 < size; x++){
		if (isPrime(x) == true){
			primes[num] = x;
			num ++;
		}
	}
}


int main() {

	unsigned arr[100];

	findNPrimes(arr, 400);

	assert(arr[0] == 2);
	assert(arr[10] == 31);
	assert(arr[50] == 233);
	assert(arr[99] == 541);

	cout << "All tests passed!";

}
