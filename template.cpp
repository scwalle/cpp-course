#include <iostream>
using namespace std;

void doCode(){
	int hours, mins;
	cout << "Enter time:\n";
	cin >> hours;
	cin.ignore(); // ignore colon. this is a bad way to do this
	cin >> mins;
	char day1, day2;
	cout << "Enter day of week:";
	cin >> day1 >> day2;
	cout << day1 << endl;
	cout << day2 << endl;


	cout << "Sum:";
	cout << hours + mins;
	cout << "\n";

	cout << "Product: ";
	cout << hours * mins;
	cout << "\n";
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
