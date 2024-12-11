#include <iostream>
using namespace std;
int main(){
    int countOfMin=0,n,m;

    cout << "M:";
    while (!(cin >> m), (cin.peek() != '\n') || m < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    int** nums = new int* [m];

    cout << "N:";
    while (!(cin >> n), (cin.peek() != '\n') || n < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }


    for (int i = 0; i < m; i++) {
        nums[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            cin >> nums[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool min = true;
            int cur = nums[i][j];
            if(i - 1 >= 0) {
               if(j - 1 >= 0 && cur >= nums[i - 1][j - 1]){
                   min = false;
               }
               if (cur >= nums[i - 1][j]) {
                   min = false;
               }
               if (j + 1 <= n - 1 && cur >= nums[i - 1][j + 1]) {
                   min = false;
               }
            }
            if(i + 1 <= m-1){
                if (j - 1 >= 0 && cur >= nums[i + 1][j - 1]) {
                    min = false;
                }
                if (cur >= nums[i + 1][j]) {
                    min = false;
                }
                if (j + 1 <= n - 1 && cur >= nums[i + 1][j + 1]) {
                    min = false;
                }
            }
            if(j - 1 >= 0){
                if (i - 1 >= 0 && cur >= nums[i-1][j-1]) {
                    min = false;
                }
                if(cur >= nums[i][j - 1]){
                    min = false;
                }
                if(i + 1 <= m - 1 && cur >= nums[i + 1][j - 1]) {
                    min = false;
                }
            }

            if (j + 1 <= n - 1) {
                if (i - 1 >= 0 && cur >= nums[i - 1][j + 1]) {
                    min = false;
                }
                if (cur >= nums[i][j + 1]) {
                    min = false;
                }
                if (i + 1 <= m - 1 && cur >= nums[i + 1][j + 1]) {
                    min = false;
                }
            }
            if (min) {
                countOfMin++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] nums[i];
    }
    delete nums;

    
    cout << "count of min:" << countOfMin;


}