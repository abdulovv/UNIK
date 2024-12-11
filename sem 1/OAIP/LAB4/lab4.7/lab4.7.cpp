#include <iostream>
using namespace std;
int main(){
	int n,max,min,iMax,iMin;

	cout << "n:";
	while (!(cin >> n), (cin.peek() != '\n') || n < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter again:";
	}

	int* nums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		while (!(cin >> nums[i]), (cin.peek() != '\n')) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter again:";
		}
	}
	
	max = nums[0];
	min = max;
	iMax = 0;
	iMin = iMax;

	for (int i = 0; i < n; i++) {
		if(nums[i] < min) {
			iMin = i;
			min = nums[i];
		}
		if(nums[i] >= max) {
			iMax = i;
			max = nums[i];
		}
	}

	if (iMax < iMin) {
		int d = iMax;
		iMax = iMin;
		iMin = d;
	}

	int countOfZero = (abs(iMax - iMin) - 1);

	for (int i = 0; i < n; i++) {
		if (nums[i] == 0) {
			countOfZero++;
		}
	}

	if (iMax > iMin) {
		for (int i = iMin + 1; i < iMax; i++) {
			nums[i] = 0;
		}
	}
	else {
		for (int i = iMax + 1; i < iMin; i++) {
			nums[i] = 0;
		}
	}

	if (countOfZero < n/2.0){
		for (int i = 0; i < n; i++) {
			cout << nums[i] << " ";
		}
		return 0;
	}

	int length = n - countOfZero;
	int* nums2 = new int[length];

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] != 0) {
			nums2[j] = nums[i];
			j++;
		}
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < length; i++) {
		cout << nums2[i] << " ";
	}
	delete nums;
	delete nums2;
}
