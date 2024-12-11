#include <iostream>
using namespace std;
int main(){
    setlocale(0, "");
    float p, q, x, x1, x2, x3, x4;

    cout << "Введите p=";
    cin >> p;

    cout << "Введите q=";
    cin >> q;

    if (p == 0) {
        cout << "x=" << pow((-q),1/3);
        return 0;
    }

    if (q == 0) {
        cout << "x=0" << endl;
        if (p < 0) {
            cout << "x=0" << endl;
            cout << "x=+/-" << sqrt(p);
        }
        return 0;
    }

    x1 = -q / 2 - sqrt(q * q / 4 + p * p * p / 27);
    x3 = pow(x1, 1 / 3.0);
    x2 = -q / 2 + sqrt(q * q / 4 + p * p * p / 27);
    x4 = pow(x2, 1 / 3.0);

    x = x3 + x4;
    cout << "x= " << x;
}

