int** sort(int num, int m, int** table) {
    int firstPos = m / 2;
    int maxNum = m * m;
    int currRow = 0, currCol = firstPos;

    table[currRow][currCol] = num;

    for (int i = num + 1; i <= maxNum; i++) {
        int prevRow = currRow;
        int prevCol = currCol;

        currRow - 1 < 0 ? currRow = m - 1 : currRow--;
        currCol + 1 >= m ? currCol = 0 : currCol++;

        if (table[currRow][currCol] != 0) {
            prevRow + 1 > m ? currRow = 0 : currRow = prevRow + 1;
            currCol = prevCol;
        }

        table[currRow][currCol] = i;
    }
    return table;

}

#include <iostream>
using namespace std;
int main(){
    int n,magicConst;

    cout << "n:";
    while (!(cin >> n), (cin.peek() != '\n') || n < 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }
    
    int** table = new int* [n];

    for (int i = 0; i < n; i++) {
        table[i] = new int[n];  
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            table[i][j] = 0; 
        }
    }

    magicConst = n * (pow(n, 2) + 1) / 2;


    if (n % 2 == 1) {
        int firstPos = n / 2;
        int maxNum = n * n;
        int currRow=0, currCol=firstPos;

        table[currRow][currCol] = 1;

        for (int i = 2; i <= maxNum; i++) {
            int prevRow = currRow;
            int prevCol = currCol;

            currRow - 1 < 0 ? currRow = n - 1 : currRow--;
            currCol + 1 >= n ? currCol = 0 : currCol++;
           
            if (table[currRow][currCol] != 0) {
                prevRow + 1 > n ? currRow = 0 : currRow = prevRow + 1;
                currCol = prevCol;
            }

            table[currRow][currCol] = i;
        }
    }else if(n % 4 == 0) {
        int min = 1;
        int max = pow(n,2);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ( (i < n / 4 || i >= n - (n / 4) ) && (j < n / 4 || j >= n - (n / 4) )) { 
                    table[i][j] = min;
                }else if ((i >= n / 4 && i < n - n / 4) && (j >= n / 4 && j < n - n / 4)) { 
                    table[i][j] = min;
                }else {  
                    table[i][j] = max;
                }

                min++;
                max--;
            }
        }
        
    }else{
        int** finalTable = new int* [n];
        for (int i = 0; i < n; i++) {
            finalTable[i] = new int[n];
        }
        int halfLength = n / 2;

        sort(1, halfLength, table);

        //1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                finalTable[i][j] = table[i][j];
            }
        }
        //2
        for (int i = 0; i < halfLength; i++) {
            for (int j = halfLength; j < n; j++) {
                finalTable[i][j] = table[i][j - halfLength] + halfLength * halfLength * 2;
            }
        }
        //3
        for (int i = halfLength; i < n; i++) {
            for (int j = 0; j < halfLength; j++) {
                finalTable[i][j] = table[i - halfLength][j] + halfLength * halfLength * 3;
            }
        }
        //4
        for (int i = halfLength; i < n; i++) {
            for (int j = halfLength; j < n; j++) {
                finalTable[i][j] = table[i - halfLength][j - halfLength] + halfLength * halfLength;
            }
        }


        for (int i = 0; i < halfLength; i++) { //верхняя половина всего квадрата
            for (int j = 0; j < n; j++) {
                if ((j < halfLength / 2 && i != halfLength / 2) || ((i == halfLength / 2) && j > 0 && j <= halfLength / 2)) {
                    int m = finalTable[i][j]; // для перестановки
                    finalTable[i][j] = finalTable[i + halfLength][j];
                    finalTable[i + halfLength][j] = m;
                }

                if (j > (n - 1) - (n - 6) / 4) { // столбцы справа
                    int m = finalTable[i][j];
                    finalTable[i][j] = finalTable[i + halfLength][j];
                    finalTable[i + halfLength][j] = m;
                }
            }
        }
        table = finalTable;
    }

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++) {
            cout << table[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }

    cout << endl;
    cout << endl;

    cout << "sum:" << magicConst;

    for (int i = 0; i < n; i++) {
        delete[] table[i];
    }
    delete table;
}
