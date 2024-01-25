#include <iostream>
using namespace std;

bool isLeapYear(int year);

int getCenturyValue(int year);

int getYearValue(int year);

int getMonthValue(int month, int year);

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

bool isLeapYear(int year){
	return (year % 400 == 0) || (year % 4 == 0 && ! (year  % 100 == 0));
};


int getCenturyValue(int year) {
	int remainder = (year / 100) % 4;
	return (3 - remainder)*2;
};


int getYearValue(int year) {
	int last2 = year % 100;
	return last2 / 4 + last2;	
};

int getMonthValue(int month, int year) {
	switch(){
		case "January":
			return 0;
		break;
	}
};

