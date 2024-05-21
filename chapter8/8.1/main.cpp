#include <iostream>
using namespace std;

/* enum State {}; */
void doCode(){
	string s;
	char c;	

	while ((c = cin.get()) != '.') {
		if (isspace(c)) {
			s += ' ';
		} else {
			s += tolower(c);
		}
	}
	s += '.';

	s[0] = toupper(s[0]);

	cout << s << endl;
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
