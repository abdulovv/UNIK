#include <iostream>
#include <string>

using namespace std;

bool isEIY (char ch){
	ch = tolower(ch);
	return  ch == 'e' || ch == 'i' || ch == 'y';
}

bool isVowelletter(char ch) {
	ch = tolower(ch);
	return  ch == 'e' || ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'a';
}

string changeX (string text, int ind){
	string newText;
	for (int i = 0; i < ind ; i++) {
		newText += text[i];
	}

	newText += text[ind] == 'x' ? "ks" : "Ks";

	int start = ind+1;
	for (int i = start; i < size(text); i++) {
		newText += text[i];
	}
	return newText;
}

string changePH(string text, int ind) {
	string newText;
	for (int i = 0; i < ind; i++) {
		newText += text[i];
	}

	newText += text[ind] == 'p' ? "f" : "F";

	int start = ind+2;
	for (int i = start; i < size(text); i++) {
		newText += text[i];
	}
	return newText;
}

string changeQU(string text, int ind) {
	string newText;
	for (int i = 0; i < ind; i++) {
		newText += text[i];
	}

	newText += text[ind] == 'q' ? "kv" : "Kv";

	int start = ind + 2;
	for (int i = start; i < size(text); i++) {
		newText += text[i];
	}
	return newText;
}

string changeTH(string text, int ind) {
	string newText;
	for (int i = 0; i < ind; i++) {
		newText += text[i];
	}

	newText += text[ind] == 't' ? "z" : "Z";

	int start = ind + 2;
	for (int i = start; i < size(text); i++) {
		newText += text[i];
	}
	return newText;

}

string changeOO(string text, int ind) {
	string newText;
	for (int i = 0; i < ind; i++) {
		newText += text[i];
	}

	newText += text[ind] == 'o' ? "u" : "U";

	int start = ind + 2;
	for (int i = start; i < size(text); i++) {
		newText += text[i];
	}
	return newText;
}

string changeYOU(string text, int ind) {
	string newText;
	for (int i = 0; i < ind; i++) {
		newText += text[i];
	}

	newText += text[ind] == 'y' ? "u" : "U";

	int start = ind + 3;
	for (int i = start; i < size(text); i++) {
		newText += text[i];
	}
	return newText;
}

string changeEE(string text, int ind) {
	string newText;
	for (int i = 0; i < ind; i++) {
		newText += text[i];
	}

	newText += text[ind] == 'e' ? "i" : "I";

	int start = ind + 2;
	for (int i = start; i < size(text); i++) {
		newText += text[i];
	}
	return newText;	
}

string changeLetters(string text){
	for (int i = 0; text[i] != '\0'; i++) {
		char currentChar = text[i];
		if (tolower(currentChar) == 'w') {
			text[i] = isupper(currentChar) ? 'V' : 'v';
		}
		if (tolower(currentChar) == 'q' && tolower(text[i + 1]) == 'u') {
			text = changeQU(text, i);
		}
		else if (tolower(currentChar) == 'q') {
			text[i] = isupper(currentChar) ? 'K' : 'k';
		}
		if (tolower(currentChar) == 'c' && isEIY(text[i + 1])) {
			text[i] = isupper(currentChar) ? 'S' : 's';
		}
		else if (tolower(currentChar) == 'c' && !isEIY(text[i + 1])) {
			text[i] = isupper(currentChar) ? 'K' : 'k';
		}
		if (tolower(currentChar) == 'x') {
			text = changeX(text, i);
			i++;
		}
		if (tolower(currentChar) == 'p' && tolower(text[i + 1]) == 'h') {
			text = changePH(text, i);
		}
		if (tolower(currentChar) == 't' && tolower(text[i + 1]) == 'h') {
			text = changeTH(text, i);
		}
		if (tolower(currentChar) == 'o' && tolower(text[i + 1]) == 'o') {
			text = changeOO(text, i);
		}
		if (tolower(currentChar) == 'e' && tolower(text[i + 1]) == 'e') {
			text = changeEE(text, i);
		}
		if (size(text) - i >= 2 && tolower(currentChar) == 'y' && tolower(text[i + 1]) == 'o' && tolower(text[i + 2]) == 'u') {
			text = changeYOU(text, i);
		}
	}
	return text;
}

string delLetters(string text, int ind, int count) {
	string newText;

	for (int i = 0; i < ind; i++) {
		newText += text[i];
	}

	newText += text[ind];

	int start = ind + count;//!!
	for (int i = start; text[i] != '\0'; i++) {
		newText += text[i];
	}
	return newText;
}

int repeat(string text){
	
	if(size(text) == 1){
		return -1;
	}

	for (int i = 0; text[i] != '\0'; i++) {
		if( isalpha(text[i]) && !isVowelletter(text[i]) && tolower(text[i]) == tolower(text[i + 1])) {
			return i;
		}
	}
	return -1;
}

string deleteAllLetters(string text){
	while(repeat(text) != -1){
		int ind = repeat(text);
		char ch = tolower(text[ind]);
		int count = 1;
		for (int i = ind+1; i != '\0'; i++) {
			if(ch == tolower(text[i])){
				count++;
			}else{
				break;
			}
		}

		text = delLetters(text, ind, count);
	}
	return text;
}

string simplifyText(string text){
	
	text = deleteAllLetters(text);
	text = changeLetters(text);
	text = deleteAllLetters(text);
	
	return text;
}

int main(){
	string text, text2;
	
	cout << "enter:";
	getline(cin, text);

	for(char ch: text){
		if( !(ch == 'Q' || ch == 'X' || ch == 'W' || ch == 'C') ) {
			text2 += ch;
		}
	}

	text = text2;
	
	text = simplifyText(text);
	
	

	cout << endl;
	cout << "final text: ";


	for (int i = 0; text[i] != '\0'; i++) {
		cout << text[i];
	}
}