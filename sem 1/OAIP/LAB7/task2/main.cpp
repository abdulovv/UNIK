#include <iostream>
#include <string>
using namespace std;
const int SIZE = 32;

bool isCorrectInput(string num) {
	if(num.empty()){
		return 0;
	}

	if(num[0] == '-') {
		for (int i = 1; num[i] != '\0'; i++) {
			if (((int)num[i] < 48 || (int)num[i] > 57)) {
				return 0;
			}
		}
	}else{
		for (int i = 0; num[i] != '\0'; i++) {
			if (((int)num[i] < 48 || (int)num[i] > 57)) {
				return 0;
			}
		}
	}
	
	return 1;
}

string enter(string num) {
	getline(cin, num);

	if (!isCorrectInput(num)){
		for (;;) {
			cout << "enter again:";
			getline(cin, num);
			cin.clear();
			if (isCorrectInput(num)) {
				break;
			}
		}
	}
	cin.clear();
	return num;
}

int* toBinary(string input) {
	int* res = new int[SIZE] {};
	string numSTR = "";
	long num = stoi(input);
	if(num < 0){
		res[0] = 1;
		num *= -1;
	}else{
		res[0] = 0;
	}

	if(num == 0){
		return res;
	}
	int i = 31;
	while (num > 0) {
		res[i] = num % 2;
		num /= 2;
		i--;
	}
	return res;
}

int* reverse(int* num) {
	for (int i = 1; i < SIZE; i++) {
		num[i] = (num[i] == 1 ? 0 : 1);
	}
	return num;
}

int* plus1(int* num, int ind) {
	if(num[ind] == 0) {
		num[ind]++;
	}else{
		for (int i = ind;i >= 1;i--) {
			if(num[i] == 0) {
				num[i] = 1;
				break;
			}
			num[i] = 0;
		}
	}
	return num;
}

int* toDopKod(string input){
	int* num = toBinary(input);
	if(num[0] == 1) {
		num = reverse(num);
		num = plus1(num,SIZE-1);
	}
	return num;
}

int* toPrKod(int* num) {
	if(num[0] == 1) {
		num = reverse(num);
		num = plus1(num, SIZE-1);
	}
	
	return num;
}

int* sum(int* num1, int* num2) {
	bool one = false;
	int* res = new int[SIZE];
	for (int i = SIZE - 1; i >= 0; i--) {
		if( (num1[i] == 0 && num2[i] == 1) || (num2[i] == 0 && num1[i] == 1) ) {
			if(one){
				res[i] = 0;
				continue;
			}
			res[i] = 1;
			one = false;
		}else if( (num1[i] == 0 && num2[i] == 0) ){
			if(one){
				res[i] = 1;
				one = false;
				continue;
			}
			res[i] = 0;
		}else if(num1[i] == 1 && num2[i] == 1) {
			if(!one){
				res[i] = 0;
			}else if(one){
				res[i] = 1;
			}
			one = true;
		}

	}
	return res;
}


int main() {
	string num1, num2;
	int* num_1 = new int[SIZE];
	int* num_2 = new int[SIZE];
	int* res = new int[SIZE];
	
	num1 = enter(num1);
	num_1 = toDopKod(num1);

	for (int i = 0; i < SIZE; i++) {
		cout << num_1[i];
		if((i+1)%4 == 0){
			cout << " ";
		}
	}
	
	cout << endl;

	num2 = enter(num2);
	num_2 = toDopKod(num2);
	for (int i = 0; i < SIZE; i++) {
		cout << num_2[i];
		if ((i + 1) % 4 == 0) {
			cout << " ";
		}
	}

	cout << endl;
	cout << "res:"<<endl;

	res = sum(num_1, num_2);
	res = toPrKod(res);

	for (int i = 0; i < SIZE; i++) {
		cout << res[i];
		if ((i + 1) % 4 == 0) {
			cout << " ";
		}
	}


	

}