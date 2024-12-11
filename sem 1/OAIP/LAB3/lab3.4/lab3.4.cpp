#include <iostream>
using namespace std;
int main(){
    int a,sum=0;
    
    cout << "a:";

    while (!(cin >> a), (cin.peek() != '\n') || a <= 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    

    for (int i = 1; i <= a; i++) {
        if (i % 2 == 0) {
            sum = sum + i;
        }
    }
    cout << "sum:" << sum <<endl;

    /*
    if(a % 2 != 0){
        a -= 1;  
    }
    sum = (2+a)/2*(a/2);
    cout << sum;
    */
}
