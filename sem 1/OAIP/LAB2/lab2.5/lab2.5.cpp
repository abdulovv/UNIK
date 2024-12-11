#include <iostream>
using namespace std;

int main() {
    const string TEXTDISTANCEINSIDE = "Расстояние:";
    const string TEXTDISTANCEOUTSIDE = "Точка расположена за квадратом. Расстояние:";
    double k, x, y;

    setlocale(0,"");

    cout << "Введите k:";
    cin >> k;

    if (k==0) {
        cout << "Квадрат с заданными координатами не существует.";
        return 0;
    }

    cout << "Введите x:";
    cin >> x;
    cout << "Введите y:";
    cin >> y;



    if (k < 0) { //обработка для к<0; 
        if (x < 0 && y < 0 || x > 0 && y > 0 || x > 0 && y < 0 || x < 0 && y > 0) {
            x = x * (-1);
            y = y * (-1);
        }else if(x == 0 && y > 0){
            y = y * (-1);
        }else if (x == 0 && y < 0) {
            x = y*(-1);
            y = 0;   
        }else if (y == 0 && x > 0) {
            y = x * (-1);
            x = 0;
        }else if (y == 0 && x < 0) {
            x = x * (-1);
        }
        k = k * (-1);
    }


    if ((x >= 0) && (x <= k) && (y >= 0) && (y <= k)) { //точка внутри
        double distance1X, distance2X, distance1Y, distance2Y;
        distance1X = x;
        distance2X = k - x;
        distance1Y = y;
        distance2Y = k - y;
        if (distance1X <= distance2X && distance1X <= distance1Y && distance1X <= distance2Y) {
            cout << TEXTDISTANCEINSIDE << distance1X;
        }else if (distance2X <= distance1X && distance2X <= distance1Y && distance2X <= distance2Y) {
            cout << TEXTDISTANCEINSIDE << distance2X;
        }else if (distance1Y <= distance1X && distance1Y <= distance2X && distance1Y <= distance2Y) {
            cout << TEXTDISTANCEINSIDE << distance1Y;
        }else if (distance2Y <= distance1X && distance2Y <= distance2X && distance2Y <= distance1Y) {
            cout << TEXTDISTANCEINSIDE << distance2Y;
        }
    }else if (x >= 0 && x < k && y <= 0){ //снаружи точка снизу
        double distance;
        distance = 0 - y;
        cout << TEXTDISTANCEOUTSIDE << distance;
    }else if (x >= 0 && x <= k && y >= k) {  //снаружи точка сверху
        double distance;
        distance = y - k;
        cout << TEXTDISTANCEOUTSIDE << distance;
    }else if (x <= 0 && y >= 0 && y <= k) {  //снаружи точка слева
        double distance;
        distance = 0 - x;
        cout << TEXTDISTANCEOUTSIDE << distance;
    }else if (x >= k && y >= 0 && y <= k) {  //снаружи точка справа
        double distance;
        distance = x - k;
        cout << TEXTDISTANCEOUTSIDE << distance;
    }else {  //снаружи точка по диагонали
        double distance;
        if (x >= 0 && y <= 0) { //справа вниз
            distance = sqrt((x - k)*(x - k)+y*y);
        }else if (x >= 0 && y >= 0) { //справа вверх
            distance = sqrt((x - k) * (x - k) + (y - k) * (y - k));
        }else if (x <= 0 && y >= 0) { //слева вверх
            distance = sqrt(x*x + (y - k) * (y - k));
        }else if (x <= 0 && y <= 0) { //слева вниз
            distance = sqrt(x * x + y * y);
        }
        cout << TEXTDISTANCEOUTSIDE << distance;
    }
    return 0;

    


}
