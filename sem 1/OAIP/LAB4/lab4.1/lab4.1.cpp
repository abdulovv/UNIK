#include <iostream>
using namespace std;
int main(){
    const int K = 5;
    int ind=0;
    

    int array [K];

    for (int i = 0; i < K; i++) {
        cout << "Enter num:";
        while (!(std::cin >> array[i]), (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter again:";
        }
        
        
    }
    bool swap;
    do{
        swap = false;
        for (int i = 0; i < K - 1; i++) {
            if (array[i] < 0) {
                continue;
            }
            if (array[i] >= 0 && array[i + 1] < 0) {
                int a = array[i];
                array[i] = array[i + 1];
                array[i + 1] = a;
                swap = true;
            }
        }
    } while (swap);

    for (int i = 0; i < K; i++) {
        cout <<array[i]<<" ";
    }
}
