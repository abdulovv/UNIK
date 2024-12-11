#include <iostream>
using namespace std;
int main(){
    long long n, k=0, num;

    cout << "n:";
    while (!(cin >> n), (cin.peek() != '\n') || n < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }
    
    cout << "num:";
    while (!(cin >> num), (cin.peek() != '\n') || num < 0 || num > 9) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
    }

    long long n2 = n;
    int r=0;
    while(n2 != 0){
        n2 /= 10;
        r++;
    }
    
    int *nums = new int[r];
    int nums2[10] = { 0,0,0,0,0,0,0,0,0,0 };

    for (int i = 0; i < r; i++) {
        nums[i] = n % 10;
        nums2[n % 10]++;
        n /= 10;
    }

    cout << endl;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        if (nums2[i] != 0) {
            k++;
        }
    }

    cout << "K:" << k;
    cout << endl;

    for (int i = r-1; i >= 0; i--) {
        if(nums[i] == num) {
            cout << "ind:" << i <<" ";
        }
    }

    delete nums;
    
    
    /*string num;
    string n;

    bool isLetter = true;
    do {
        cin >> num;

        for (int i = 0; i < num.length(); i++) {
            if (num[i] != '0' && num[i] != '1' && num[i] != '2' && num[i] != '3' && num[i] != '4' && num[i] != '5' && num[i] != '6' && num[i] != '7' && num[i] != '8' && num[i] != '9') {
                isLetter = true;
                break;
            }else{
                isLetter = false;
            }
        }
        
    } while (isLetter == true);

    isLetter = true;
    do {
        cin >> n;
        if (n[0] != '0' && n[0] != '1' && n[0] != '2' && n[0] != '3' && n[0] != '4' && n[0] != '5' && n[0] != '6' && n[0] != '7' && n[0] != '8' && n[0] != '9' || n.length() > 1) {
            isLetter = true;
        }else{
            isLetter = false;
        }
    } while (isLetter == true);

    char n1 = n[0];


    long long nums2[10] = { 0,0,0,0,0,0,0,0,0,0 };

    for (long long i = num.length() - 1; i >= 0;i--) {
        if (num[i] == '0') {
            nums2[0]++;
        }
        else if (num[i] == '1') {
            nums2[1]++;
        }
        else if (num[i] == '2') {
            nums2[2]++;
        }
        else if (num[i] == '3') {
            nums2[3]++;
        }
        else if (num[i] == '4') {
            nums2[4]++;
        }
        else if (num[i] == '5') {
            nums2[5]++;
        }
        else if (num[i] == '6') {
            nums2[6]++;
        }
        else if (num[i] == '7') {
            nums2[7]++;
        }
        else if (num[i] == '8') {
            nums2[8]++;
        }
        else if (num[i] == '9') {
            nums2[9]++;
        }
    }
    long long d = 0;
    for (long long i = 0; i < 10; i++) {
        if (nums2[i] != 0) {
            d++;
        }
    }

    std::cout << d;
    std::cout << endl;

    int siz = 0;
    for (long long i = num.length() - 1; i >= 0;i--) {
        if (num[i] == n1) {
            siz++;
        }
    }

    long long* nums3 = new long long[siz];
    int j = 0;
    for (long long i = num.length() - 1; i >= 0;i--) {
        if (num[i] == n1) {
            nums3[j] = num.length() - (i + 1);
            j++;
        }
    }

    for (int i = 0; i < siz; i++) {
        std::cout << nums3[i];
        if (i != siz - 1) {
            std::cout << " ";
        }
    }*/



}
