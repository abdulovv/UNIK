#include <iostream>
using namespace std;
int main(){
    setlocale(0, "");
    const string IMPOSSIBLEVALUE = "Радиус не может быть отрицательным или равен нулю";
    int x1, x2, y1, y2,radius1,radius2;
    float distanceBetweenCentres;

    cout << "Введите Х1:";
    cin >> x1;

    cout << "Введите Y1:";
    cin >> y1;

    cout << "Введите Х2:";
    cin >> x2;

    cout << "Введите Y2:";
    cin >> y2;

    cout << "Введите R1:";
    cin >> radius1;

    if (radius1 <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите R2:";
    cin >> radius2;

    if (radius2 <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    distanceBetweenCentres = sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));

    if(x1 == x2 && y1 == y2 && radius1 == radius2){ 
        cout << "Окружности лежат друг на друге";
        return 0;
    }

    if (radius1 >= distanceBetweenCentres + radius2) { 
        cout << "Окружность М1 поглощает окружность М2";
    }else if(radius2 >= distanceBetweenCentres + radius1){
        cout << "Окружность М2 поглощает окружность М1";
    }else if(radius1 + radius2 >= distanceBetweenCentres){
        cout << "Окружности пересекаются";
    }else {
        cout << "Ни одно условие не выполнено";
    }
    return 0;
}
