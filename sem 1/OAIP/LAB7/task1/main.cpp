#include <iostream>
#include <string>
using namespace std;

bool isCorrectInput(string num){
	for (int i = 0; num[i] != '\0'; i++) {
		if(num[i] != '0' && num[i] != '1') {
			return 0;
		}
	}
	return 1;
}

string reverse(string num) {
	string newNum = "1";
	for (int i = 1; num[i] != '\0'; i++) {
		if(num[i] == '0'){
			newNum += '1';
		}else{
			newNum += '0';
		}
	}
	return newNum; 
}

int main(){
	string num;
	do {
		cout << "num:";
		getline(cin, num);
	} while(!isCorrectInput(num));

	if(num[0] == '1') {
		num = reverse(num);
	}

	cout << "res:" << num;
}