#include <iostream>
using namespace std;
int main(){
    int m1,n1, m2, n2;

    cout << "N(1)";
    while (!(cin >> n1), (cin.peek() != '\n') || n1 < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    cout << "M(1)";
    while (!(cin >> m1), (cin.peek() != '\n') || m1 < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    int** A = new int*[n1];

    for (int i = 0; i < n1; i++) {
        A[i] = new int[m1];
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0;j < m1;j++) {
            while (!(cin >> A[i][j]), (cin.peek() != '\n')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter again:";
            }

        }
        cout << endl;
    }
    
    cout << endl;


    cout << "N(2)";
    while (!(cin >> n2), (cin.peek() != '\n') || n2 < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }


    cout << "M(2)";
    while (!(cin >> m2), (cin.peek() != '\n') || m2 < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    if(n2 != m1){
        cout << "impossible to multiply";
        return 0;
    }

    int** B = new int* [n2];
    for (int i = 0; i < n2; i++) {
        B[i] = new int[m2];
    }


    for (int i = 0; i < n2; i++) {
        for (int j = 0;j < m2;j++) {
            while (!(cin >> B[i][j]), (cin.peek() != '\n')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter again:";
            }
        }
        cout << endl;
    }

    int** C = new int* [n1];
    for (int i = 0;i < n1;i++) {
        C[i] = new int[m2];
    }

    int sum = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            for (int d = 0; d < m1; d++) {
                sum += A[i][d] * B[d][j];
            }
            C[i][j] = sum;
            sum = 0;
        }
    }
    

    cout << endl;
    cout << endl;

    for (int i = 0; i < n1; i++) {
        for (int j = 0;j < m2;j++) {
            cout << C[i][j] <<" ";
        }
        cout << endl;
    }

    for (int i = 0; i < n1; i++) {
        delete[] A[i];
    }
    delete A;

    for (int i = 0; i < n2; i++) {
        delete[] B[i];
    }
    delete B;

    for (int i = 0; i < n1; i++) {
        delete[] C[i];
    }
    delete C;

}
