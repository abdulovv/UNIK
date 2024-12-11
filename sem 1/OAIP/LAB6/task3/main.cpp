#include <iostream>
#include <string>

using namespace std;

string reverse(string text){
	string newText = "";
	int size=0;

	for (int i = 0; text[i] != '\0'; i++) {
		size++;
	}

	for (int i = 0; text[i] != '\0' ;i++ ) {
		newText += text[size-(i+1)];
	}

	return newText;
}


string enter(){
	string input,res;
	cout << "enter:";
	cin.ignore();
	getline(cin, input);
	return res;
}

int main() {
	int size;
	cout << "size:";
	cin >> size;

	string** mtrx = new string * [size];
	for (int i = 0; i < size; i++) {
		mtrx[i] = new string[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mtrx[i][j] = enter();
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			string currentText = mtrx[i][j];
			int sum = 0;
			for (int d = 0; currentText[d] != '\0'; d++) {
				sum += currentText[d];
			}
			if(sum % 2 == 0){
				mtrx[i][j] = reverse(currentText);
			}
		}
		
	}


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << mtrx[i][j] << " ";
		}
		cout << endl;
	}
}