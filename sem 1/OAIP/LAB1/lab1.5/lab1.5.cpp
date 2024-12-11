#include <iostream>

using namespace std;
int main() {
    double a1, a100, a, d, s, n = 10+1; //#1
    setlocale(LC_ALL, "RUSSIAN");

    cout << "a1=";
    cin >> a1;
    cout << "" << endl;

    cout << "a100=";
    cin >> a100;
    cout << "" << endl;

    d = (a100 - a1) / 99;
    a = a1 + (n - 1);
    s = (a1 + a) / 2 * n;

    cout << "Разность:";
    cout << d;
    cout << "" << endl;

    cout << "Сумма:";
    cout << s;
    cout << "" << endl;

    return 0;
}