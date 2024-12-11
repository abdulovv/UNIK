#include <iostream>
#include <cmath>
using namespace std;
int main(){
    const double PI = 3.14159265358979323846;
    const double E  = 2.71828182845904523536;
    long long d=0,c;
    long double x,xDeg, sin = 0, cos = 1, lnx, x1, res=1;
    
    cout << "x(rad):";
    while (!(cin >> x), (cin.peek() != '\n')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }
    
    x1 = x;

    if (x1 < 0) {
        x1 = -x1;
    }

    lnx = 0;
    
    c = x / (2 * PI);
    x -= c * 2 * PI;
   
    xDeg = x;

    for (int d = 0, i = 1;;) {
         
        for (int j = 0; j < i-1; j++) {
            xDeg *= x;
        }
        for (int j = 1; j <= i; j++) {
            xDeg /= j;
        }
        if (d % 2 == 0) {
            sin += xDeg;
        }else {
            sin -= xDeg;
        }
        
        if( (xDeg <= 0.00001 && xDeg > 0) || (-xDeg <= 0.00001 && xDeg < 0) || xDeg==0){
            break;
        }
        xDeg = x;
        d++;
        i += 2;
    }
   
    xDeg = x;

    for (int d = 1, i = 2;;) {
        for (int j = 2; j <= i ; j++) {
            xDeg *= x;
        }
        for (int j = 1; j <= i; j++) {
            xDeg /= j;
        }
        if (d % 2 == 0) {
            cos += xDeg;
        }
        else {
            cos -= xDeg;
        }
        if ((xDeg <= 0.00001 && xDeg > 0) || (-xDeg <= 0.00001 && xDeg < 0) || xDeg == 0) {
            break;
        }
        xDeg = x;
        d++;
        i += 2;
    }

    //=======================================================

    if (x1 == 0) {
        if (cos < sin) {
            cout << "cos=" << cos;
        }else{
            cout << "sin=" << sin;
        }
    }
    else {
        while (true) {
            if (x1 < 2) {
                break;
            }

            x1 /= E;
            d++;
        }

        for (int i = 1; i <= 1500; i++) {
            for (int j = 0; j < i; j++) {
                res *= (x1 - 1);
            }

            res /= i;
            
            if (i % 2 != 0) {
                lnx += res;
            }else {
                lnx -= res;
            }

            res = 1;
        }

        lnx += d;

        cout << "lnx:" << lnx << endl;
        cout << "sin=" << sin << endl;
        cout << "cos=" << cos << endl;
        cout << endl;
        cout << "======================" << endl;
        cout << endl;


        if (cos < sin && cos < lnx) {
            cout << "cos=" << cos;
        }else if(sin < cos && sin < lnx){
            cout << "sin=" << sin << endl;
        }else{
            cout << "lnx:" << lnx << endl;
        }
    }
    
    
   

  
  
   
    
    

  

}
