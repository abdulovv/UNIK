#include <iostream>
using namespace std;
int main(){
	int n = 5,indMax,indMin;
	float max, min;
	cout << "N:";
	while (!(cin >> n), (cin.peek() != '\n') || n < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter again:";
	}
	
	float** numbers = new float* [n];
	for (int i = 0; i < n; i++) {
		numbers[i] = new float[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> numbers[i][j];
		}
		cout << endl;
	}

	max = numbers[0][0];
	min = max;
	indMax = 0;
	indMin = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(numbers[i][j] > max){
				indMax = i;
				max = numbers[i][j];
			}else if(numbers[i][j] < min){
				indMin = i;
				min = numbers[i][j];
			}

		}
	}
	
	for (int i = 0; i < n; i++) {
		float a = numbers[indMax][i];
		numbers[indMax][i] = numbers[indMin][i];
		numbers[indMin][i] = a;
	}

	cout << endl;
	cout << endl;


	if(indMax == indMin){
		cout << "max and min are placed in the same string";		
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << numbers[i][j] << " ";
			}
			cout << endl;
		}
	}

	for (int i = 0; i < n; i++) {
		delete [] numbers[i];
	}
	delete numbers;
}

