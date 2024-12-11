#include <iostream>
using namespace std;
int main() {
	const string NOSOLUTIONS = "Решений нет";
	setlocale(0, "");
	float a, b, c;

	cout << "Введите a:";
	cin >> a;

	cout << "Введите b:";
	cin >> b;

	cout << "Введите c:";
	cin >> c;

	if ( a == b && b == c && c == 0) {
		cout << NOSOLUTIONS;
		return 0;
	}

	if (b == c && c == 0) {
		cout << NOSOLUTIONS;
	}

	if (a == 0 && b == 0 || a == 0 && c == 0) {
		cout << "x=0";
		return 0;
	}



	if (a != 0 ) {
		float discriminant,t1,t2;
		//t=(x+1/x) , x!= 0

		discriminant = pow(b, 2) - 4 * a * (c - 2 * a);

		if (discriminant < 0) {
			cout << NOSOLUTIONS;
			return 0;
		}

		t1 = ((-b) + sqrt(discriminant)) / (2 * a);
		t2 = ((-b) - sqrt(discriminant)) / (2 * a);

		if (t1 == t2) {
			float discriminant1, x1, x2;
			discriminant1 = pow(t1, 2) - 4;

			if (discriminant1 < 0) {
				cout << NOSOLUTIONS;
				return 0;
			}

			x1 = (t1 + sqrt(discriminant1)) / 2;
			x2 = (t1 - sqrt(discriminant1)) / 2;

			if (x1 == x2) {

				if (x1 == 0) {
					cout << NOSOLUTIONS;
				}
				else {
					cout << "x=" << x1;
				}

			}else {

				if (x1 != 0) {
					cout << "x=" << x1 << endl;
				}
				if (x2 != 0) {
					cout << "x=" << x2 << endl;
				}

			}
		}else {
			float discriminant1, discriminant2, x1, x2;
			
			discriminant1 = pow(t1, 2) - 4;
			discriminant2 = pow(t2, 2) - 4;

			if (discriminant1 >= 0) {
				x1 = (t1 + sqrt(discriminant1)) / 2;
				x2 = (t1 - sqrt(discriminant1)) / 2;
				
				if (x1 != 0) {
					cout << "x=" << x1 << endl;
				}
				if (x2 != 0) {
					cout << "x=" << x2 << endl;
				}
			}if (discriminant2 >= 0) {
				x1 = (t2 + sqrt(discriminant2)) / 2;
				x2 = (t2 - sqrt(discriminant2)) / 2;

				if (x1 != 0) {
					cout << "x=" << x1 << endl;
				}
				if (x2 != 0) {
					cout << "x=" << x2 << endl;
				}
			}

		}
	}else{
		float discriminant, x1,x2;
		cout << "x=0" << endl;
		discriminant = pow(c, 2) - 4 * pow(b, 2);
		if (discriminant >= 0) {
			x1 = ((-c) + sqrt(discriminant)) / (2 * b);
			x2 = ((-c) - sqrt(discriminant)) / (2 * b);

			if (x1 == x2) {
				cout << "x=" << x1;
			}else {
				cout << "x=" << x1 << endl;
				cout << "x=" << x2 << endl;
			}
		}
	}
}