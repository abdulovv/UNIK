#include <iostream>
using namespace std;
int main(){
	int n;
	cout << "n:";
	while (!(cin >> n), (cin.peek() != '\n') || n < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter again:";
	}

	int* arr = new int[n];
	
	for (int i = 0; i < n;i++) {
		arr[i] = i;
	}

	int countOfsockets = 1;
	for (int i = 0; i < n; i++) {
		countOfsockets += arr[i];
	}
	
	cout << "the final number of outlets:" << countOfsockets;
	
	delete arr;
}
