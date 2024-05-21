#include <iostream>
using namespace std;

void doCode(){
	char c;
	string word;
	while (!cin.fail()){
		while (isspace(c = cin.peek())){
			cout.put(cin.get());
		}
		// c is not whitespace, start of a word
		cin >> word;
		bool isnum = true;
		for (char c : word) {
			if (!isdigit(c)) {
				isnum = false;
				break;
			}
		}
		if (isnum) {
			cout << string(word.length(), 'x');
		} else {
			cout << word;
		}
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
