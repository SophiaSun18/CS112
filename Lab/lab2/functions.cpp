/* functions.cpp
  * Student name: ZeAi Sun(zs35), Palmer Ford(pjf5)
  * Date: January 25, 2022
  * Author: Prof. Victor Norman
  * For: CS 112, Lab 2 at Calvin University.
  */

bool findDuplicate(int arr[], unsigned size, int &dup_num){

	for(unsigned i = 0; i < size; i++){
		int num1 = arr[i];
		int count = 0;
		for(unsigned j = 0; j < size; j++){
			if(arr[j] == num1){
				count ++;
			}
		}
		if(count > 1){
			dup_num = num1;
			return true;
		}
	}
	return false;
}
