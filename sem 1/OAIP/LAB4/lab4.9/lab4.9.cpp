#include <iostream>
using namespace std;
int main(){
    int n, max;

    cout << "n:";
    while (!(cin >> n), (cin.peek() != '\n') || n < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }
                    
     // |3|4| очередность
     // |1|2| заполнения
                        
    int*** arr = new int**[n];
    
    for (int i = 0;i < n;i++) {
        arr[i] = new int* [n];
    }

    for (int i = 0; i < n;i++ ) {
        for (int j = 0; j < n;j++) {
            arr[i][j] = new int [n];
        }
    }

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            for (int d = 0;d < n;d++) {
                cout << "[" << i << "]" << "[" << j << "]" << "[" << d << "] =";
                cin >> arr[i][j][d];
            }
        }
    }

    int curSum=0;
    int d = n - 1;
    for (int i = 0; i < n;i++) {
        curSum += arr[i][i][i];
    }
    max = curSum;
    curSum = 0;

    for (int j = 0; j < n;j++) {
       curSum += arr[j][j][d];
       d--;
    }
    if(curSum > max){
        max = curSum;
    }
    curSum = 0;
    d = n - 1;

    for (int j = 0; j < n;j++) {
        curSum += arr[j][d][j];
        d--;
    }
    if (curSum > max) {
        max = curSum;
    }
    curSum = 0;
    d = n - 1;

    for (int j = 0; j < n;j++) {
        curSum += arr[d][j][j];    
        d--;
    }
    if (curSum > max) {
        max = curSum;
    }



    cout << std::endl;
    cout << "==================================================";
    cout << std::endl;

    cout << "max sum:" << max;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++ ) {
            delete arr[i][j] ;
        }
    }

    for (int j = 0; j < n; j++) {
        delete arr[j];
    }
    delete arr;
}
