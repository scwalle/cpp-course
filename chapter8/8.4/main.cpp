#include <iostream>
using namespace std;

/* void readName(string & first, string & last, string & middle) { */
/* } */

#define ds(var) cout << #var ": " << var << endl

void doCode(){
	string first, last, middle;
	cin >> first >> middle >> last;

	if (last.empty()) {
		last = middle;
		middle = "";
	}

	cout << last << ", " << first;
	if (!middle.empty()) { // if has middle name
		cout << " " << middle[0] << ".";
	}
	cout << endl;

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
