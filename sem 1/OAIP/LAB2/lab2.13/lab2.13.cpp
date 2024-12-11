#include <iostream>
#include <string>
using namespace std;
int main(){
    int countOfMushrooms;
    string text;
    setlocale(0,"");

    cout << "Введите количество грибов:";
    cin >> countOfMushrooms;

    if (countOfMushrooms < 0) {
        cout << "Количество грибов не может быть меньше 0";
        return 0;
    }

    text = "Мы нашли " + to_string(countOfMushrooms) + " ";

   
    if(countOfMushrooms % 100 >= 10 && countOfMushrooms % 100 <= 20){
        text = text + "грибов";
    }else if (countOfMushrooms % 10 == 1) {
        text = text + "гриб";
    }else if (countOfMushrooms % 10 > 1 && countOfMushrooms % 10 <= 4) {
        text = text + "грибa";
    }else if (countOfMushrooms % 10 > 4) {
        text = text + "грибов";
    }else if ((countOfMushrooms % 10 == 0)) {
        text = text + "грибов";
    }
    text = text + " в лесу.";
    cout << text;
    return 0;
}
