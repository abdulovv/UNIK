#include <iostream>
#include <string>

using namespace std;

string reverse(string text) {
    string newText = "";

    for (int i = 0; text[i] != '\0'; i++) {
        newText += text[text.length() - (i + 1)];
    }

    return newText;
}


bool equals(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        if(s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}


bool isSubStringsEquals(string s1, string s2, int count) {
    string firstSubStr = s1.substr(s1.length() - count );
    string secondSubStr = s2.substr(0,count);
    return equals(firstSubStr, secondSubStr);
}


bool isOneWord(int countOfLett, int wordSize, string s1, string s2) {
    return countOfLett == wordSize && equals(s1, s2);
}


bool isStringsAcross(int countOfLett, string s1, string s2) {
    return isSubStringsEquals(s1, s2, countOfLett) 
        || isSubStringsEquals(s2, s1, countOfLett);
}


bool isStringsSimple(string s1, string s2){
    return s1.length() != 1 || s2.length() != 1;
}


bool isResultWillHaveSameWord(string s1, string s2){
    return equals(s1 + s2, reverse(s2 + s1));
}


int calculate(string s1, string s2, int l){
    int size = l - s1.length() - s2.length();
    if (size > 0) {
        unsigned long long res = pow(26, size);
        if (equals(s1, s2)) {
            return res;
        }else if (isResultWillHaveSameWord(s1, s2) && isStringsSimple(s1, s2)) {
            res *= 2;
            int sizeDifference = s1.length() - s2.length();
            int countOfVariables = size - abs(sizeDifference);

            if (countOfVariables == 0) {
                res -= 1;
            }else {
                res -= pow(26, countOfVariables);
            }
            return res;
        }else {
            return res*2;
        }
    }else if (size == 0) {
        return equals(s1, s2) ? 1 : 2;
    }else {
        int countOfLett = abs(size);
        if (isOneWord(countOfLett, l, s1, s2) || isStringsAcross(countOfLett, s1, s2)) {
            return 1;
        }
    }
    return 0;
}


int main() {
    string s1, s2;
    unsigned long long l, m;

    cout << "S1:";
    cin >> s1;
    
    cout << "S2:";
    cin >> s2;

    cout << "L:";
    cin >> l;

    cout << "M:";
    cin >> m;

    int result = calculate(s1, s2, l) ;
    
    cout << "result:" << result % m;

    return 0;
}