#include <iostream>
using namespace std;
int main(){
    int a,num=0,r=0,sum=0;
    cout << "a:";
    while (!(cin >> a), (cin.peek() != '\n') || a < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }



    for (int i = 1; i < a; i++) {
        num = i;
        while (num != 0) { //кол-во разрядов
            num /= 10;
            r++;
        }//num=0;

        num = i;

        for (int j=1; j <= r; j++) {
            sum += pow((num % 10),r);
            num /= 10;
        }
        r = 0;
        if (i == sum) {
            cout << sum << endl;
        }
        sum = 0;
    }

}
