#include <iostream>

using namespace std;

bool isNeChetnoe (int num){
    bool res = (num & 1);
    return res;
}

bool delitsyaLiOnonNa3(int num) {
    num += (isNeChetnoe(num) ? num : 0);

    while (num != 0 && num > 0) {
        if (num == 3) {
            return true;
        }
        num -= (isNeChetnoe(num) ? 3 : 0);
        num = num >> 1;
    }
    return false;
}

bool delitsyaliononna37(int num) {
    num += (isNeChetnoe(num) ? num : 0);
    while (num != 0 && num > 0) {
        if (num == 37) {
            return true;
        }
        num -= (isNeChetnoe(num) ? 37 : 0);
        num = num >> 1;
    }
    return false;
}

bool delitsyaliononna89(int num) {
    num += (isNeChetnoe(num) ? num : 0);
    while (num != 0 && num > 0) {
        if (num == 89) {
            return true;
        }
        num -= (isNeChetnoe(num) ? 89 : 0);
        num = num >> 1;
    }
    return false;
}

int main() {
    int num;
    cout << "num:";
    cin >> num;

    cout << "Delitsya li ono na 3:" << (delitsyaLiOnonNa3(num) ? "YES" : "NO") << endl;
    cout << "Delitsya li ono na 37:" << (delitsyaliononna37(num) ? "YES" : "NO") << endl;
    cout << "Delitsya li ono na 89:" << (delitsyaliononna89(num) ? "YES" : "NO") << endl;
    return 0;
}
