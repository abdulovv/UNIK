#include <iostream>
#include <string>

using namespace std;

string reverse(string num) {
	string newNum = "";
	int size = 0;

	for (int i = 0; num[i] != '\0'; i++) {
		size++;
	}

	for (int i = 0; num[i] != '\0'; i++) {
		newNum += num[size - (i + 1)];
	}

	return newNum;
}


string toBinary(int num){
	string res = "";
	int n = to_string(num).length();
	int i = 0;
	while(i < n){
		res += to_string(num % 2);
		num /= 2;
		i++;
	}
	res = reverse(res);
	return res;
}

bool isNeedNum(int num) {
	string numBase10 = to_string(num);
	string numBase2 = toBinary(num);
	for (int i = 0; i < numBase10.length(); i++) {
		if(numBase10[i] != numBase2[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	
	cout << "num:";
	cin >> n;

	int i = 0;
	int num = 0;

	while(i != n){
		num++;
		if( (num % 10 == 1 || num % 10 == 0) && isNeedNum(num) ){
			i++;
		}
	}

	cout << "res:" << num;
}
