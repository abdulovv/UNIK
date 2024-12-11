#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    const double PI = 3.14159265358979323846;
    int n, d = 0, u;
    long double x, xDeg, sn = 0;

    cout << "Count of x:";
    while (!(cin >> u), (cin.peek() != '\n') || u <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    cout << "n:";
    while (!(cin >> n), (cin.peek() != '\n') || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }



    while (u > 0) {
        cout << "x:";
        while (!(cin >> x), (cin.peek() != '\n') || x < 0.1 || x > 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter again:";
        }

        cout << "1)sinx=" << sin(x) << endl;

        xDeg = x;

        for (int i = 1; i <= n*2+1; i += 2) {
            for (int j = 0; j < i - 1; j++) {
                xDeg *= x;
            }
            for (int j = 1; j <= i; j++) {
                xDeg /= j;
            }
            if (d % 2 == 0) {
                sn += xDeg;
            }
            else {
                sn -= xDeg;
            }
            xDeg = x;
            d++;
        }
        cout << "2)sinx=" << sn << endl;
        sn = 0;
        d = 0;
        u--;
    }
}
