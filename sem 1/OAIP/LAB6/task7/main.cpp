#include <iostream>

using namespace std;

bool isPalindrome(string str) {
	if (str.length() % 2 == 0) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] != str[str.length()-i-1]) {
				return false;
			}
		}
	}
	else {
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] != str[str.length() - i - 1] && i != str.length()/2) {
				return false;
			}
		}
	}
	return true;
}


bool isStrOneLetter(string str){
	for (int i = 0; i < str.length()-1; i++) {
		if(str[i] != str[i+1]) {
			return false;
		}
	}
}


int main() {
	string str, res;

	cout << "str:";
	cin >> str;

	if(isStrOneLetter(str)){
		cout << "-1";
		return 0;
	}

	int ind = 0;

	while(ind < str.length()){
		string currStr;
		for (int i = ind; str[i] != '\0'; i++) {
			currStr += str[i];
			if(!isPalindrome(currStr) && res.length() < currStr.length()){
				res = currStr;
			}
		}
		ind++;
	}
	cout << "res:" << res.length();
}