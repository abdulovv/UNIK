#include <iostream>
#include <cmath>
using namespace std;
int main(){
    const double PI = 3.14159265358979323846;
    double y,ymin,step,xmin=0;

    cout << "step:";
    while (!(cin >> step), (cin.peek() != '\n') || step <= 0 || step > 1) {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    ymin = fabs(sin(0) + cos(0) - 2 * (PI / 2 - atan(0)));
    for (double i = step; i <= 1; i+=step) {
        y = fabs(sin(i) + cos(i) - 2 * (PI / 2 - atan(i)));
        if (y < ymin) {
            ymin = y;
            xmin = i;
        }
    }

    cout << "min value:" << ymin << endl;
    cout << "xmin:" << xmin;
}
