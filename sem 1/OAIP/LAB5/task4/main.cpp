#include <iostream>
#include "arrayFunctions.h";

double** reverse(double** nums, int n, int m){
	double** reverseNums = createMatrixDouble(n, m);
	int sizeN = n-1;
	int sizeM = m-1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			reverseNums[i][j] = nums[sizeN][sizeM];
			sizeM--;
		}
		sizeN--;
		sizeM = m - 1;
	}
	return reverseNums;
}

using namespace std;
int main(){
	int n, m;

	cout << "n:";
	cin >> n;

	cout << "m:";
	cin >> m;

	double** nums = createMatrixDouble(n,m);
	fillMatrix(nums,n,m);

	int countOfZero = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(nums[i][j] == 0) {
				countOfZero++;
				cout << "ind:" << "[" << i << "][" << j << "]"<<endl;
			}
		}
	}

	cout << "Count of Zero = " << countOfZero << endl;
	cout << endl;
	cout << "Reverse matrix:" << endl;
	nums = reverse(nums, n, m);
	printMatrix(nums, n, m);
	
	deleteMatrix(nums,n);
	
}