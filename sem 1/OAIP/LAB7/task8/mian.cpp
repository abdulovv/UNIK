#include <iostream>
#include <string>

using namespace std;

string reverse(string num) {
    string newNum = "";
    int size = 0;

    for (int i = 0; num[i] != '\0'; i++) {
        size++;
    }

    for (int i = 0; num[i] != '\0'; i++) {
        newNum += num[size - (i + 1)];
    }

    return newNum;
}

string to3Base(int num) {
    string res = "";
    while (num > 0) {
        res += to_string(num % 3);
        num /= 3;
    }
    return reverse(res);
}

int main(){
    int num;
    cout << "num:";
    cin >> num;

    string res = to3Base(num);

    int pos = res.find("10");
    while(pos + 1){
        res.replace(pos, 2,"03");
        pos = res.find("10");
    }

    pos = res.find("20");
    while(pos + 1){
        res.replace(pos,2,"13");
        pos = res.find("20");
    }

    pos = res.find("30");
    while(pos + 1){
        res.replace(pos,2,"23");
        pos = res.find("30");
    }

    while (res[0] == '0') {
        res.erase(0, 1);
    }

    cout << "res:" << res;

}
