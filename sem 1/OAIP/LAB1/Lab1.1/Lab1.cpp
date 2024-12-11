#include <iostream>
using namespace std;
int main() {
    double x, b, a, x2, ans1, ans2;
    setlocale(LC_ALL, "RUSSIAN");
    cout << "х=:";
    cin >> x;
    cout << "" << endl;

    x2 = x * x; //+1
    b = x * (23 * x2 + 32); // +3
    a = 69 * x2 + 8; //+2
    ans1 = a + b; //+1
    ans2 = a - b; //+1

    cout << "Ответ 1:";
    cout << ans1;
    cout << "" << endl;
    cout << "Ответ 2:";
    cout << ans2;

    return 0;
}