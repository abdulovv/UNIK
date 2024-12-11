#include <iostream>
using namespace std;
int main(){
    int n, m;

    cout << "N:";//m
    while (!(cin >> m), (cin.peek() != '\n') || m<0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    char** field = new char* [m];

    cout << "M:";
    while (!(cin >> n), (cin.peek() != '\n') || n < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }


    for (int i = 0; i < m; i++) {
        field[i] = new char[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            while (!(cin >> field[i][j]), (cin.peek() != '\n') || field[i][j] != '*' && field[i][j] != '.') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter again:";
            }
        }
        cout << endl;
    }

    int countOfBombs = 0;
    bool leftup = false;
    bool rightup = false; 
    bool rightdown = false;
    bool leftdown = false;
    char bomb = '*';
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char cur = field[i][j];
            if(cur != '*') {
                if (i - 1 >= 0) {
                    if (j - 1 >= 0 && bomb == field[i - 1][j - 1]) {
                        countOfBombs++;
                        leftup = true;
                    }
                    if (bomb == field[i - 1][j]) {
                        countOfBombs++;
                    }
                    if (j + 1 <= n - 1 && bomb == field[i - 1][j + 1]) {
                        countOfBombs++;
                        rightup = true;
                    }
                }
                if (i + 1 <= m - 1) {
                    if (j - 1 >= 0 && bomb == field[i + 1][j - 1]) {
                        countOfBombs++;
                        leftdown = true;
                    }
                    if (bomb == field[i + 1][j]) {
                        countOfBombs++;
                    }
                    if (j + 1 <= n - 1 && bomb == field[i + 1][j + 1]) {
                        countOfBombs++;
                        rightdown = true;
                    }
                }
                if (j - 1 >= 0) {
                    if (i - 1 >= 0 && bomb == field[i - 1][j - 1] && leftup == false) {
                        countOfBombs++;
                    }
                    if (bomb == field[i][j - 1]) {
                        countOfBombs++;
                    }
                    if (i + 1 <= m - 1 && bomb == field[i + 1][j - 1] && leftdown == false) {
                        countOfBombs++;
                    }
                }
                if (j + 1 <= n - 1) {
                    if (i - 1 >= 0 && bomb == field[i - 1][j + 1] && rightup == false) {
                        countOfBombs++;
                    }
                    if (bomb == field[i][j + 1]) {
                        countOfBombs++;
                    }
                    if (i + 1 <= m - 1 && bomb == field[i + 1][j + 1] && rightdown == false) {
                        countOfBombs++;
                    }
                }
                if (countOfBombs > 0) {
                    int code = 48 + countOfBombs;
                    field[i][j] = code;
                }
                countOfBombs = 0;
                leftup = false;
                rightup = false;
                rightdown = false;
                leftdown = false;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << field[i][j]<<" ";
        }
        cout << endl;
    }

    for (int j = 0; j < n; j++) {
        delete[] field[j];
    }
    delete[] field;

}
