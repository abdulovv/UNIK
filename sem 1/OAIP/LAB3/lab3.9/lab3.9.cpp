#include <iostream>
using namespace std;
int main(){
    int a, n, res=0;

    cout << "a:";
    while (!(cin >> a), (cin.peek() != '\n')) {
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

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            res += pow(2, (i - 1)) * a;
        }else {
            res -= pow(2, (i - 1)) * a;
        }
    }

    cout << "res:" << res;

}
