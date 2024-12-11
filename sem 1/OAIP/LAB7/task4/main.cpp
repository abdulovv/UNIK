#include <iostream>
#include <string>

using namespace std;

string arabicToRoman(int arabicNum) {
    string result = "";
    const int SIZE = 17;
    int arabic[] = {1000, 900, 800, 700, 600, 100, 90, 80, 70, 60, 50, 40, 10, 9, 5, 4, 1};
    string roman[] = { "M", "CM","CCM","CCCM","CCCCM", "C","XC" ,"LXXX","LXX","LX","L","XL", "X","IX", "V", "IV", "I"};

    for (int i = 0; i < SIZE ; i++) {
        while (arabicNum >= arabic[i]) {
            result += roman[i];
            arabicNum -= arabic[i];
        }
    }
    return result;
}

int main() {
    int arabicNum;
    cout << "arabicNum:";
    cin >> arabicNum;

    while(arabicNum < 0){
        cout << "enter again:";
        cin >> arabicNum;
    }

    string romanNum = arabicToRoman(arabicNum);
    cout << "res:" << romanNum << endl;
}
