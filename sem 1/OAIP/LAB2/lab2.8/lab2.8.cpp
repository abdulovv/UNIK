#include <iostream>
using namespace std;
int main(){
	setlocale(0,"");
	
	
	float a, b, c, discriminant;

	cout << "Введите a:";
	cin >> a;

	cout << "Введите b:";
	cin >> b;

	cout << "Введите c:";
	cin >> c;

	//t=x^2

	discriminant = pow(b, 2) - 4 * a * c;

	if (discriminant == 0) {
		float x1, x2, t;

		t = -b / (2 * a);

		if (t <= 0) {
			cout << "Корней нету.";
			return 0;
		}else {
			x1 = sqrt(t);
			x2 = -sqrt(t);
		}
	}else if (discriminant > 0) {
		float x1, x2, x3, x4, t1, t2;

		t1 = (-b + sqrt(discriminant)) / (2 * a);
		t2 = (-b - sqrt(discriminant)) / (2 * a);

		if (t1 < 0 && t2 < 0) {
			cout << "Корней нету.";
			return 0;
		}
		else if (t1 == 0 && t2 == 0) {
			x1 = sqrt(t1);
			cout << "X1 = " << x1 << endl;
		}
		else if (t1 > 0 && t2 > 0) {
			x1 = sqrt(t1);
			x2 = -sqrt(t1);
			x3 = sqrt(t2);
			x4 = -sqrt(t2);

			cout << "X1 = " << x1 << endl;
			cout << "X2 = " << x2 << endl;
			cout << "X3 = " << x3 << endl;
			cout << "X4 = " << x4 << endl;
		}
		else if (t1 > 0 && t2 < 0) {
			x1 = sqrt(t1);
			x2 = -sqrt(t1);

			cout << "X1 = " << x1 << endl;
			cout << "X2 = " << x2 << endl;

		}
		else {
			x1 = sqrt(t2);
			x2 = -sqrt(t2);

			cout << "X1 = " << x1 << endl;
			cout << "X2 = " << x2 << endl;
		}
	}
	else {
		cout << "Корней нету.";
	}
	
}
