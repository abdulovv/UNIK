#include <iostream>
using namespace std;
int main(){
    const int M = 4;
    const int N = 4;
    int count=0;
    int array[M][N];

     for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++){
            while (!(cin >> array[i][j]), (cin.peek() != '\n')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter again:";
            }
        }
        cout << endl;
     }

     for (int i = M - 1; i >= 0; i--) {
         for (int j = N - 1; j > i; j--) {
             if (array[i][j] > 0) { // 0 + or -
                 count++;
             }
         }
     }

     cout << endl;
     cout << "count:" << count;
     

}
