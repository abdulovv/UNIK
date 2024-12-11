#include <iostream>

using namespace std;

bool isNeedStr(string str1, string str2){
	if(str1.length() != str2.length()){
		return false;
	}
	
	for (int i = 0; str1[i] != '\0'; i++) {
		if(str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}


bool funct(string s, string t) {

	string res;
	for (int d = 0; s[d] != '\0'; d++) {
		int add2 = 0;
		for (int i = d; s[i] != '\0'; i++) {
			add2++;
			res += s[i];
			if (isNeedStr(t, res)) {
				return true;
			}
			if (i > 0) {
				int add = 0;
				for (int j = i - 1; j >= 0; j--) {
					res += s[j];
					add++;
					if (isNeedStr(res, t)) {
						return true;
					}
				}
				res.erase(res.length() - add);
			}
		}
		res.erase(res.length() - add2);
	}
	return false;
}


int main(){
	string S,T;
	bool res;

	cout << "S:";
	cin >> S;

	cout << "T:";
	cin >> T;

	res = funct(S, T);

	//ababcde
	//bcba
	
	cout << (res ? "YES" : "NO");
	

}