#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

double constrain(double value, double low = 0.0, double high = 100.0){
	if (value < low){
		return low;
	}else if (value > high){
		return high;
	}else{
		return value;
	}
}

bool isPrime(unsigned int x){

	int num = 0;

	if (x == 1){
		return false;
	}else if (x == 2){
		return true;
	}else{
		for (int i = 2; i <= x/2; i++){
			if (x % i == 0){
				num += 1;
			}else{
				num += 0;
			}
		}
	}

	if (num == 0){
		return true;
	}else{
		return false;
	}

	return 0;
}
