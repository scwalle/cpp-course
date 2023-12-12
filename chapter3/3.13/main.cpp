#include <iostream>
#include <format>
using namespace std;

int const len = 4;

bool allDifferent(string s){
	if (len == 1 || len == 0) {
		return true;
	}

	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			cout << "testing " << s[i] << " and " << s[j] << endl;
			if (s[i] == s[j]) {
				cout << s[i] << " == " << s[j] << endl;
				cout << "Fail!\n";
				return false;
			} else {
				cout << s[i] << " != " << s[j] << endl;
			}
		}
	}
	return true;
}

bool is3Times(char s[]) {
	return ( s[0] - '0' == 3 * (s[2] - '0') );
}

int sumDigits(char s[]) {
	int sum = 0;
	for (int i = 0; s[i]; i++) {
		sum += s[i] - '0';	
	}
	return sum;
}

int main(){
	int i = 0;
	char num[len + 1] = { 0 };
	snprintf(num, 5, "%04d", i);
	cout << num << endl;
	for (;!(
				allDifferent(num) 
				&& is3Times(num) 
				&& (i % 2 == 0) 
				&& (sumDigits(num) == 27)
		   ); i++) {
		snprintf(num, 5, "%04d", i);
		cout << num << endl;
	}
	cout << "Answer: " << num;
}
