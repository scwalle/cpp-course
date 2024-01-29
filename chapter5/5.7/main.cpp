#include <iostream>
using namespace std;

bool isLeapYear(int year);

int getCenturyValue(int year);

int getYearValue(int year);

int getMonthValue(int month, int year);

int getDayOfWeek(int day, int month, int year);

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

/*
Month		Return Value
-------------------------
January 	0 (6 if year is a leap year)
February 	3 (2 if year is a leap year)
March 		3
April 		6
May 		1
June 		4
July 		6
August 		2
September 	5
October 	0
November 	3
December 	5
*/
enum Months {
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};
/*












*/
int getMonthValue(int month, int year) {
	switch(month){
		case January:
			return isLeapYear(year) ? 6 : 0;
		break;
		case February:
			return isLeapYear(year) ? 2 : 3;
		break;
		case March:
			return 3;
		break;
		case April:
			return 6;
		break;
		case May:
			return 1;
		break;
		case June:
			return 4;
		break;
		case July:
			return 6;
		break;
		case August:
			return 2;
		break;
		case September:
			return 5;
		break;
		case October:
			return 0;
		break;
		case November:
			return 3;
		break;
		case December:
			return 5;
		break;
	}
};

int getDayOfWeek(int day, int month, int year){
	return (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;
}

