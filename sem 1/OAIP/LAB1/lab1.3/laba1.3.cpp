#include <iostream>
using namespace std;
int main() {
    double t, v, a, s;
    setlocale(LC_ALL, "RUSSIAN");

    cout << "Введите начальную скорость:";
    cin >> v;
    cout << "" << endl;

    cout << "Введите время движения:";
    cin >> t;

    if (t < 0) {
        cout << "Время не может быть отрицательным";
    }
    else {
        cout << "" << endl;

        cout << "Введите ускорение:";
        cin >> a;
        cout << "" << endl;

        s = v * t + (a * t * t) / 2;

        cout << "Расстояние:";
        cout << s;
    }
    return 0;
}