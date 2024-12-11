#include <iostream>
using namespace std;
int main(){
    setlocale(0,"");
	int x, y, k;
	float a, b, c;

	cout << "Введите X:";
	cin >> x;

	cout << "Введите Y:";
	cin >> y;

	cout << "Введите A:";
	cin >> a;

	cout << "Введите B:";
	cin >> b;

	cout << "Введите C:";
	cin >> c;

	cout << "Введите K:";
	cin >> k;

	if (x < y) {
		x = 0;
	}else if(x > y){
		y = 0;
	}else if (x == y) {
		x = 0;
		y = 0;
	}



	if (a == b && b== c) {
		cout << "Переменные A,B,C равны между собой"<<endl;
	}else if (a == b) {
		cout << "Переменные А и B равны между собой"<<endl;
	}else if (a == c) {
		cout << "Переменные А и C равны между собой" << endl;
	}else if (b == c) {
		cout << "Переменные B и C равны между собой" << endl;
	}else if (a > b && a > c) {
		a = a - k;
	}
	else if (b > a && b > c) {
		b = b - k;
	}
	else {
		c = c - k;
	}

	cout << "A=" << a << endl;
	cout << "B=" << b << endl;
	cout << "C=" << c << endl;
	
	cout << "X=" << x << endl;
	cout << "Y=" << y;

}

