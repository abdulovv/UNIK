#include <iostream>
#include <cmath>
using namespace std;
int main(){
    const double PI = 3.14159265358979323846;
    double A = 0, x=A, B = PI / 2, M = 20;

    for (int i = 0; x < B ; i++) {
        x = A + i * (B - A) / M; 
        double y = sin(x) - cos(x);
        cout << y << endl;
    }

}
