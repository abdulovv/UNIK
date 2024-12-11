#include <iostream>
#include "arrayFunctions.h";
using namespace std;

double averageSum (int* arr, int size){
	double sum = 0;
	for (int i = 0; i < size;i++) {
		sum += arr[i];
	}
	sum /= size;
	return sum;
}

int main() {
	int n, m, size=0;

	cout << "n:";
	cin >> n;

	cout << "m:";
	cin >> m;

	int** nums = createMatrix(n, m);
	fillMatrix(nums,n,m);

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if(j % 2 != 0 && nums[i][j] % 2 != 0) {
				size++;
			}
		}
	}

	int* needNums = new int[size];

	int ind = 0;

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (j % 2 != 0 && nums[i][j] % 2 != 0) {
				needNums[ind] = nums[i][j];
				ind++;
			}
		}
	}

	printArray(needNums,size);

	cout << endl;
	cout << "average:" << averageSum(needNums,size);

	deleteMatrix(nums, n);
	delete[] needNums;
    
}