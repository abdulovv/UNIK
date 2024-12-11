#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double h;
    setlocale(LC_ALL, "RUSSIAN");
    cout << "Высота:";
    cin >> h;
    if (h >= 0) {
        h = sqrt(2 * h / 9.8);
        cout << "" << endl;
        cout << "Ответ:";
        cout << setprecision(9) << h;
    }
    else {
        cout << "" << endl;
        cout << "высота не может быть отрицательной";
    }
    return 0;
}