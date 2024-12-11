#include <iostream>
using namespace std;
int main() {
    double b1, q, s, n = 1;//#1
    setlocale(LC_ALL, "RUSSIAN");

    cout << "b1=";
    cin >> b1;

    q = 1 / (n + 1);
    s = b1 / (1 - q);

    cout << "" << std::endl;
    cout << "Сумма:";
    cout << s;

    return 0;
}