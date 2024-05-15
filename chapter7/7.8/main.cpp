#include <iostream>
using namespace std;


void doCode(){
	int freq[26];
	char c;
	int chars = 0;
	cout << "input sentence: ";
	while ((c = getchar()) != '.') {
		if (c == ' ') { continue; }

		chars++;


		int letter = c - 'a';
		freq[letter]++;	
	}

	char letters[26];
	int letterc = 0;

	for (int i = 1; i <= chars; i++) {
		for (int letter = 0; letter < 26; letter++) {
			if (freq[letter] == i) {
				letters[letterc] = letter;
				letterc++;
			}
		}
	}

	cout << endl;
	cout << "Letter | Frequency\n-------|----------\n";
	for (int i = 0; i < letterc; i++) {
		cout << "   " << (char) (letters[i] + 'a') << "   |     " << freq[letters[i]] << endl;
	}
}
	
int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	while(true){
		doCode();
		
		cout << "\nTry again? (Ctrl-C to exit, anything else to go again): ";
		string loop = "";
		cin >> loop;
		if (loop == "") return 0;
		cout << endl << endl;
	}
}
