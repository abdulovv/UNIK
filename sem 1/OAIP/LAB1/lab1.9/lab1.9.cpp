#include <iostream>
using namespace std;
int main() {
	int a, b;
	setlocale(0, "RUSSIAN");

	cout << "Введите число a:";
	cin >> a;
	cout << "" << endl;

	cout << "Введите число b:";
	cin >> b;
	cout << "" << endl;

	if (a >= 0 && b >= 0 || a <= 0 && b <= 0) {
		a = a - b;
		b = a + b;
		a = b - a;
	}else{
		a = a + b;
		b = a - b;
		a = a - b;
	}

	cout << a << endl;
	cout << b << endl;


}
