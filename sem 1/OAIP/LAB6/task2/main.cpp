#include <iostream>

using namespace std;

bool fillStr(char* str) {
	bool clear = true;
	const int SIZE = 90;

	for (int i = 0; i < SIZE; i++) {
		char crChar = getchar();

		if (i > 80) {
			clear = true;
			while (clear) {
				char crChar = getchar();
				if (crChar == '\n') {
					break;
				}
			}
			return false;
		}

		if (crChar == '\n') {
			str[i] = '\0';
			break;
		}

		str[i] = crChar;
	}
	return true;
}


bool isWordDelimiter(char sym){
	char wordDelimiters[] = "!@#$%^&*()_=+|?/;,.¹;:<>~` ";
	for (int i = 0; wordDelimiters[i] != '\0'; i++) {
		if(wordDelimiters[i] == sym){
			return true;
		}
	}
	return false;
}



int main() { 
	setlocale(0,"");
	char* message = new char[80];
	bool test = fillStr(message);

	while (!test) {
		cout << "Enter again:";
		test = fillStr(message);
	}

	
	int countOfWords = 0;
	bool isWord = !isWordDelimiter(message[0]) ? true : false;

	for (int i = 1; message[i] != '\0'; i++) {
		bool isWordCurrSym = !isWordDelimiter(message[i]) ? true : false;

		if (isWord && !isWordCurrSym || message[i+1] == '\0' && isWordCurrSym) {
			countOfWords++;
		}

		isWord = isWordCurrSym;
	}

	int price;
	cout << "Enter the price of one word:";
	cin >> price;
	cout << endl;

	int totalPrice = price * countOfWords;
	cout << "Price of message:" << totalPrice;



}