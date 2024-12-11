#include "pch.h"

double averageSum(int* arr, int size);


TEST(TEST1) {
	int size = 5;
	int* arr = new int[size];
	double average1 = 0;

	arr[0] = 44;
	arr[1] = 22;
	arr[2] = 76;
	arr[3] = 3;
	arr[4] = 13;

	for (int i = 0; i < size; i++) {
		average1 += arr[i];
	}

	average1 /= size;
	double average2 = averageSum(arr, size);

	if(average1 != average2){
		FAIL();
	}
}

double averageSum(int* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	sum /= size;
	return sum;
}