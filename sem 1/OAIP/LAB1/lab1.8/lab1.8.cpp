#include <iostream>

using namespace std;
int main() {
    const string ERROR1 = "Кол-во часов не может быть больше 23";
    const string ERROR2 = "кол-во минут не может быть больше равно 60";
    int h1, m1, h2, m2, time1, time2, r, h, m;
    setlocale(LC_ALL, "RUSSIAN");

    cout << "Введите время начала(часы):";
    cin >> h1;
    cout << "" << endl;

    if (h1 >= 24) {
        cout << ERROR1;
        return 0;
    }

    cout << "Введите время начала(минуты):";
    cin >> m1;
    cout << "" << endl;

    if (m1 >= 60) {
        cout << ERROR2;
        return 0;
    }

    cout << "Введите время конца(часы):";
    cin >> h2;
    cout << "" << endl;

    if (h2 > 24) {
        cout << ERROR1;
        return 0;
    }

    cout << "Введите время конца(минуты):";
    cin >> m2;
    cout << "" << endl;

    if (m2 >= 60) {
        cout << ERROR2;
        return 0;
    }

    time1 = h1 * 60 + m1;
    time2 = h2 * 60 + m2;

    if (time1 > time2) {
        r = time2 - time1 + 24 * 60;
    }
    else {
        r = time2 - time1;
    }

    h = r / 60;
    m = r % 60;

    cout << "Время работы:" << h << "ч." << m << "мин.";
    return 0;
}