#include <iostream>
#include <cmath>
using namespace std;
int main() {
	const string ERROR = "деление на 0";
	setlocale(LC_ALL, "RUSSIAN");
	double d, x, b, a,answ,znam;
	
	cout << "Введите D:";
	cin >> d;
	cout << "" << endl;

	cout << "Введите x:";
	cin >> x;
	cout << "" << endl;

	b = x + d;

	if (b == 0) {
		cout << ERROR;
		return 0;
	}

	a = d * x / b;
	
	znam = (pow(d, 3) + a + d - b);

	if (znam == 0) {
		cout << ERROR;
		return 0;
	}
	
	answ = (pow(x, 2) + b * cos(x)) / znam;
	cout << answ;
	return 0;
	

}