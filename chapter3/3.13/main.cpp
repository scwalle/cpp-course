#include <iostream>
#include <format>
using namespace std;

bool allDifferent(string s){
	int len = s.length();
	if (len == 1 || len == 0) {
		return true;
	}

	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			cout << "testing " << s[i] << " and " << s[j] << endl;
			if (s[i] == s[j]) {
				return true;
			} else {
				cout << s[i] << " !== " << s[j] << endl;
			}
		}
	}
	return false;
}

string padTo(string s, int len){
	string out;
	return out.insert(0, '0', len - s.length());	
}

int main(){
	int i = 0;
	/* string num = padTo(to_string(i), 4); */ 
	string num = std::format("{:04}", i);
	/* snprintf(num, 5, "%04d", i); */
	cout << num << endl;
	return 0;
	while (
			allDifferent(num)// &&
	) {
		cout << i++ << endl;
		string num = padTo(to_string(i), 4); 
	}
	cout << "Answer: " << i;
}
