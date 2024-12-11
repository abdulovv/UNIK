#include <iostream>
#include <string>

using namespace std;

bool isEIY(char ch) {
	ch = tolower(ch);
	return  ch == 'e' || ch == 'i' || ch == 'y';
}


bool isVowelletter(char ch) {
	ch = tolower(ch);
	return  ch == 'e' || ch == 'y' || ch == 'u' || ch == 'i' || ch == 'o' || ch == 'a';
}

string delQWXC(string text) {
	string newText;
	for (int i = 0; text[i] != '\0'; i++) {
		char ch = text[i];
		if (!(ch == 'Q' || ch == 'X' || ch == 'W' || ch == 'C')) {
			newText += ch;
		}
	}
	return newText;
}

string changeX(string text, int ind) {
	string newText;
	for (int i = 0; i < ind; i++) {
		newText += text[i];
	}

	newText += text[ind] == 'x' ? "ks" : "Ks";

	int start = ind + 1;
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

	int start = ind + 2;
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


string changeLetters111(string text) {
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

	for (int i = 0; text[i] != '\0'; i++) {
		char currentChar = text[i];
		if (tolower(currentChar) == 'c' && isEIY(text[i + 1])) {
			text[i] = isupper(currentChar) ? 'S' : 's';
		}
		else if (tolower(currentChar) == 'c' && !isEIY(text[i + 1])) {
			text[i] = isupper(currentChar) ? 'K' : 'k';
		}
	}

	return text;
}

string changeLetters222(string text) {
	string newText;
	for (int i = 0; text[i] != '\0'; i++) {
		char currentChar = text[i];


		if (tolower(currentChar) == 'w') {
			newText += isupper(currentChar) ? 'V' : 'v';
			continue;
		}
		if (tolower(currentChar) == 'q' && tolower(text[i + 1]) == 'u') {
			newText += currentChar == 'q' ? "kv" : "Kv";
			i++;
			continue;
		}
		else if (tolower(currentChar) == 'q') {
			newText += isupper(currentChar) ? 'K' : 'k';
			continue;
		}
		if (tolower(currentChar) == 'x') {
			newText += currentChar == 'x' ? "ks" : "Ks";
			continue;
		}
		if (tolower(currentChar) == 'p' && tolower(text[i + 1]) == 'h') {
			newText += currentChar == 'p' ? "f" : "F";
			i++;
			continue;
		}
		if (tolower(currentChar) == 't' && tolower(text[i + 1]) == 'h') {
			newText += currentChar == 't' ? "z" : "Z";
			i++;
			continue;
		}
		if (tolower(currentChar) == 'o' && tolower(text[i + 1]) == 'o') {
			newText += currentChar == 'o' ? "u" : "U";
			i++;
			continue;
		}
		if (tolower(currentChar) == 'e' && tolower(text[i + 1]) == 'e') {
			newText += currentChar == 'e' ? "i" : "I";
			i++;
			continue;
		}
		if (size(text) - i >= 2 && tolower(currentChar) == 'y' && tolower(text[i + 1]) == 'o' && tolower(text[i + 2]) == 'u') {
			newText += currentChar == 'y' ? "u" : "U";
			i+=2;
			continue;
		}
		newText += currentChar;
	}

	for (int i = 0; newText[i] != '\0'; i++) {
		char currentChar = newText[i];
		if (tolower(currentChar) == 'c' && isEIY(newText[i + 1])) {
			newText[i] = isupper(currentChar) ? 'S' : 's';
		}
		else if (tolower(currentChar) == 'c' && !isEIY(newText[i + 1])) {
			newText[i] = isupper(currentChar) ? 'K' : 'k';
		}
	}

	return newText;
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


int repeat(string text, int startInd) {

	if (size(text) == 1) {
		return -1;
	}

	for (int i = startInd; text[i] != '\0'; i++) {
		if (isalpha(text[i]) && !isVowelletter(text[i]) && (tolower(text[i]) == tolower(text[i + 1]))) {
			return i;
		}
	}
	return -1;
}

string deleteAllLetters(string text) {
	int lastI = 0;
	while (true) {
		int ind = repeat(text, lastI);
		lastI = ind;
		if (ind == -1) {
			return text;
		}
		char ch = tolower(text[ind]);
		int count = 1;

		for (int i = ind + 1; i != '\0'; i++) {
			if (ch == tolower(text[i])) {
				count++;
			}
			else {
				break;
			}
		}

		text = delLetters(text, ind, count);
	}
	return text;
}


string simplifyText111(string text) {
	text = delQWXC(text);
	text = changeLetters111(text);
	text = deleteAllLetters(text);
	return text;
}

string simplifyText222(string text) {
	text = delQWXC(text);
	text = changeLetters222(text);
	text = deleteAllLetters(text);
	return text;
}

bool test (string t1, string t2){
	if(t1.length() != t2.length()){
		return false;
	}

	for (int i = 0; i < t1.length(); i++) {
		if(t1[i] != t2[i]) {
			return false;
		}
	}
	return true;
}
	
int main() {
	string text , text2;

	getline(cin, text);

	text2 = text;

	text = simplifyText111(text);

	cout << endl;
		cout << "res1:"<< endl;

	for (int i = 0; text[i] != '\0'; i++) {
		cout << text[i];
	}

	cout << endl << endl << "======================================================= " << endl << endl;

	
	cout <<  "res2:" << endl;

	text2 = simplifyText222(text2);

	for (int i = 0; text2[i] != '\0'; i++) {
		cout << text2[i];
	}
	cout << endl;

	cout << test(text,text2);
}


//nkwelnkSEWEEEEEEEEEEEXXXXXXXXXXXQVVIIKCCUUYUOYUOIEPWER