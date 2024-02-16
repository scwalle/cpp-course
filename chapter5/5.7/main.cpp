#include <iostream>
using namespace std;

#define X_MONTHS \
	X(January)   \
	X(February)  \
	X(March)     \
	X(April)     \
	X(May)       \
	X(June)      \
	X(July)      \
	X(August)    \
	X(September) \
	X(October)   \
	X(November)  \
	X(December)

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

string monthNames[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

string weekdays[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(Months month, int year);
int getDayOfWeek(int day, Months month, int year);
void getInput(Months &month, int &day, int &year) {
	cout << "Enter time (mm/dd/yyyy): ";
	int month_temp;
	scanf("%d/%d/%d", &month_temp, &day, &year);
	month = (Months) (month_temp-1);
}

void doCode(){
	Months month;
	int day;
	int year;
	getInput(month, day, year);
	int weeknum = getDayOfWeek(day, month, year);
	string weekstr = weekdays[weeknum];
	printf("Day of week: %s", weekstr.c_str());
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
int getMonthValue(Months month, int year) {
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

int getDayOfWeek(int day, Months month, int year){
	return (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;
}

