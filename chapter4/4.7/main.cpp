#include <iostream>
using namespace std;

const int HOUR = 60;

int timeToMinutes(
	int hours, int minutes, bool isAM 
){
	int total = 0;
	if (!isAM) { // if it's PM, add 12 hours
		total += 12 * HOUR;
	}
	// account for 12:00 AM == 00:00
	if (hours != 12) {
		total += hours * HOUR;
	}
	total += minutes;
	return total;
}

int computeDifference(
		int startHours, int startMinutes, bool startisAM, 
		int endHours, int endMinutes, bool endisAM
) {
	int start = timeToMinutes(startHours,  startMinutes,  startisAM);
	int end = timeToMinutes(endHours,  endMinutes,  endisAM);
	int total = end - start;
	if (start > end) {
		total += 24 * HOUR;
	}
	return total;
}

void getTime(int &hours, int &minutes, bool &isAM){
	char AMPM;
	scanf("%i:%i %cM", &hours, &minutes, &AMPM);
	isAM = ( AMPM == 'A' ); // true if AM, false if not aka PM
}

void printTime(int &hours, int &minutes, bool &isAM){
	char AMPM = isAM ? 'A' : 'P';
	printf("%i:%i %cM", hours, minutes, AMPM);
	/* isAM = ( AMPM == 'A' ); // true if AM, false if not aka PM */
}

void run(){
	int startHours, startMinutes;
	bool startisAM;
	int endHours, endMinutes;
	bool endisAM;

	cout << "Start time: ";
	getTime(startHours, startMinutes, startisAM);

	cout << "End time: ";
	getTime(endHours, endMinutes, endisAM);

	int timeDifference = computeDifference(startHours, startMinutes, startisAM, endHours, endMinutes, endisAM);

	cout << endl;
	cout << "Difference in minutes: " << timeDifference;
}

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do {
		cout << endl;
		run();

		cout << endl << endl;
		cout << "Run again? (y/n): ";
		char loop;
		cin >> loop;
		if (loop == 'n' || loop == 'N') break;
	} while (true);

	return 0;
}
