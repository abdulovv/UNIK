#include <iostream>
#include <string>

using namespace std;

const int SIZE = 16;

int* toOtherBase (int num, int base){
	int* res = new int[SIZE] {};

	int i = 1;
	while(num > 0){
		res[SIZE-i] = num % base;
		num /= base;
		i++;
	}
	return res;
}

char numToLetter (short num){
	string arrOfNumbers{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
					   'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	return arrOfNumbers[num];
}

void output (int* res){
	for (int i = 0; i < SIZE; i++) {
		cout << numToLetter(res[i]);
		if((i+1) % 4 == 0){
			cout << " ";
		}
	}
}

int* pluss(int* num1, int* num2, int base) {
	int* res = new int[SIZE] {};
	bool next = false;

	for (int i = SIZE-1; i >= 0; i--) {
		int sum = num1[i] + num2[i];
		if(sum == base){
			res[i] = (next ? 1 : 0);
			next = true;
		}else if(sum > base){
			res[i] = (next ? sum - base + 1 : sum - base);
			next = true;
		}else{
			if(next){
				if(sum + 1 < base){
					res[i] = sum + 1;
				}else{
					res[i] = 0;
					continue;
				}
			}else{
				res[i] = sum;
			}
			next = false;
		}
	}
	return res;
}

int* difference(int* num1, int* num2, int base) {
	bool next = false;
	int* res = new int[SIZE];
	for(int i = SIZE - 1; i >= 0; i--){
		int diff = num1[i] - num2[i];
		diff = (next ? diff - 1 : diff);
		if(diff == 0){
			res[i] = 0;
			next = false;
		}else if(diff > 0){
			res[i] = diff;
			next = false;
		}else{
			res[i] = base - abs(diff);
			next = true;
		}
	}
	return res;
}


int main(){
	int numINT1, numINT2, base;

	cout << "num1:";
	cin >> numINT1;

	cout << "num2:";
	cin >> numINT2;

	cout << "base:";
	cin >> base;

	bool isNum1BiggerThenNum2 = (abs(numINT1) > abs(numINT2) ? true : false);

	int* sum = new int[SIZE];
	int* diff = new int[SIZE];
	int* num1 = new int[SIZE];
	int* num2 = new int[SIZE];

	if (numINT1 > 0 && numINT2 > 0) {
		num1 = toOtherBase(numINT1, base);
		num2 = toOtherBase(numINT2, base);
		sum = pluss(num1, num2, base);

		cout << "sum:";
		output(sum);
		cout << endl;
		cout << "diff:";
		if (numINT1 - numINT2 != 0) {
			if (isNum1BiggerThenNum2) {
				diff = difference(num1, num2, base);
			}else {
				diff = difference(num2, num1, base);
				cout << "-";
			}
			output(diff);
		}else{
			for (int i = 0; i < SIZE; i++) {
				cout << "0";
				if ((i + 1) % 4 == 0) {
					cout << " ";
				}
			}
		}
	}else if(numINT1 > 0 && numINT2 < 0){
		num1 = toOtherBase(numINT1, base);
		num2 = toOtherBase(-numINT2, base);
		diff = pluss(num1, num2, base);
		if(isNum1BiggerThenNum2){
			sum = difference(num1,num2,base);
		}else{
			sum = difference(num2, num1, base);
		}

		cout << "sum:";
		if (numINT1 - numINT2 != 0) {
			if (!isNum1BiggerThenNum2) {
				cout << "-";
			}
			output(sum);
		}else {
			for (int i = 0; i < SIZE; i++) {
				cout << "0";
				if ((i + 1) % 4 == 0) {
					cout << " ";
				}
			}
		}
		cout << endl;
		cout << "diff:";
		output(diff);
	}else if(numINT1 < 0 && numINT2 > 0){
		num1 = toOtherBase(-numINT1, base);
		num2 = toOtherBase(numINT2, base);
		diff = pluss(num1, num2, base);
		if (isNum1BiggerThenNum2) {
			sum = difference(num1, num2, base);
		}else{
			sum = difference(num2, num1, base);
		}

		cout << "sum:";
		if (numINT1 - numINT2 != 0) {
			if (isNum1BiggerThenNum2) {
				cout << "-";
			}
			output(sum);
		}else{
			for (int i = 0; i < SIZE; i++) {
				cout << "0";
				if ((i + 1) % 4 == 0) {
					cout << " ";
				}
			}
		}
		cout << endl;
		cout << "diff:-";
		output(diff);
	}else{
		num1 = toOtherBase(-numINT1, base);
		num2 = toOtherBase(-numINT2, base);
		sum = pluss(num1, num2, base);
		if (isNum1BiggerThenNum2) {
			diff = difference(num1, num2, base);
		}
		else {
			diff = difference(num2, num1, base);
		}

		cout << "sum:-";
		output(sum);
		cout << endl;
		cout << "diff:";
		if (numINT1 - numINT2 != 0) {
			if (isNum1BiggerThenNum2) {
				cout << "-";
			}
			output(diff);
		}else{
			for (int i = 0; i < SIZE; i++) {
				cout << "0";
				if((i+1) % 4 == 0){
					cout << " ";
				}
			}
		}
	}
}
