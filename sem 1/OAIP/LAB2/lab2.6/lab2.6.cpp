#include <iostream>
using namespace std;
int main(){
    setlocale(0, "");
    float a, b, c, d, z;

    cout << "Введите a:";
    cin >> a;

    cout << "Введите b:";
    cin >> b;

    cout << "Введите c:";
    cin >> c;

    cout << "Введите d:";
    cin >> d;

    if (c >= d && a < d) {
        if (c == 0) {
            cout << "Произойдет деление на ноль";
            return 0;
        }
        z = a + b / c;
    }else if (c < d && a >= d) {
        if (c == 0) {
            cout << "Произойдет деление на ноль";
            return 0;
        }
        z = a - b / c;
    }else{
        z = 0;
    }
    cout << "Z=" << z;
}
