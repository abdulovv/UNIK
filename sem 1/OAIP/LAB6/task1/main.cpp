#include <iostream>

using namespace std;

bool fillStr(char* str){
	bool clear = true;
	const int SIZE = 90;

	for (int i = 0; i < SIZE; i++) {
		char crChar = getchar();

		if (i > 80) {
			clear = true;
			while (clear) {
				char crChar = getchar();
				if(crChar == '\n') {
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

	

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ') {
			return false;
		}
	}

	return true;
}


int main(){
	char* str = new char[80];
	bool test = fillStr(str);
	
	while (!test){
		cout << "Enter again:";
		test = fillStr(str);
	}

	int countOfDig = 0;
	int countOfRows = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if(str[i] == '0' || str[i] == '1') {
			countOfDig++;
		}else{
			if (countOfDig == 5) {
				countOfRows++;
			}
			countOfDig = 0;
		}
	}
	cout << "count of rows:" << countOfRows;
}