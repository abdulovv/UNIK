#include <iostream>
using namespace std;
int main(){
    int n;
    
    while (!(cin >> n), (cin.peek() != '\n') || n<0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    int row = 0;

    int size = 1;
    while(size*size < n){
        size++;
    }

    int** table = new int* [size];
   
    for (int i = 0;i < size;i++) {
        table[i] = new int[size];
    }

    for (int i = 0; i < size;i++) {
        for (int j = 0; j < size;j++) {
            table[i][j] = 0;
        }
    }

    int currCol = 0;
    int currRow = 0;
    int col = 1;
    table[currRow][currCol] = 1;
    currCol++;

    for (int i = 2;i <= size*size ;i++) {
        int prevCol = currCol;
        int prevRow = currRow;

        if(table[currRow][currCol] == 0){
            table[currRow][currCol] = i;
        }

        if(currCol - 1 < 0){
            currCol = col + 1;
            currRow = 0;
            col++;
        }else{
            currCol--;
        }

        if ( table[currRow][currCol] != 0 ){
            currCol = prevCol;
            currRow++;
        }
    }

    for (int i = 0; i < size;i++) {
        for(int j = 0; j < size;j++){
            if(table[i][j] == n){
                cout << "i=" << i << endl;
                cout << "j=" << j << endl;
            }
        }
    }

    for (int i = 0; i < size;i++) {
        delete[] table[i];
    }
    delete[] table;
    
    
}
