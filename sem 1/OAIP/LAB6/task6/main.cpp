#include <iostream>

using namespace std;

string allLetters(string word){
	string letters;

	for (int i = 0; word[i] != '\0'; i++) {
		bool test = true;
		for (int j = 0; letters[j] != '\0'; j++) {
			if(word[i] == letters[j]) {
				test = false;
				break;
			}
		}
		if(isalpha(word[i]) && test) {
			letters += word[i];
		}
	}
	return letters;
}

unsigned long long fact (int a){
	unsigned long long  res = 1;
	for (int i = 1; i <= a; i++) {
		res *= i;
	}
	return res;
}

int main() {
	string word;
	cin >> word;
	while(word.length() > 14){
		cout << "enter again:";
		cin >> word;
	}

	string letters = allLetters(word);

	unsigned long long  res = fact(size(word));

	for (int i = 0; letters[i] != '\0'; i++) {
		int count = 0;
		for(int j = 0; word[j] != '\0'; j++){
			if(letters[i] == word[j]) {
				count++;
			}
		}
		res /= fact(count);
	}

	cout << "res:" << res;
}