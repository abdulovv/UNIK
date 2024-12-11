#include <iostream>
using namespace std;
int main(){
	const string ERROR = "Сторона треугольника не может быть меньше или равна 0";
	setlocale(0, "");
	int x, y, z;

	cout << "Введите X:";
	cin >> x;

	if (x <= 0) {
		cout << ERROR;
		return 0;
	}
	
	cout << "Введите Y:";
	cin >> y;

	if (y <= 0) {
		cout << ERROR;
		return 0;
	}
	
	cout << "Введите Z:";
	cin >> z;

	if (z <= 0) {
		cout << ERROR;
		return 0;
	}

	if (x < y + z && y < x + z && z < x + y) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}

   
}

