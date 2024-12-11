#include <iostream>
using namespace std;
int main() {
    int n, m;

    cout << "N:";
    while (!(cin >> n), (cin.peek() != '\n') || n < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    int** nums = new int* [n];

    cout << "M:";
    while (!(cin >> m), (cin.peek() != '\n') || m < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }


    for (int i = 0; i < n; i++) {
        nums[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while (!(cin >> nums[i][j]), (cin.peek() != '\n')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter again:";
            }
        }
        cout << endl;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int max = nums[i][j];
            if (i - 1 >= 0) {
                if (j - 1 >= 0 && max < nums[i - 1][j - 1]) {
                    max = nums[i - 1][j - 1];
                }
                if (max < nums[i - 1][j]) {
                    max = nums[i - 1][j];
                }
            }
            if (j - 1 >= 0 && max < nums[i][j - 1]) {
                max = nums[i][j - 1];
            }
            nums[i][j] = max;
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] nums[i];
    }
    delete nums;


}