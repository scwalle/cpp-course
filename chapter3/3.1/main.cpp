#include <iostream>
using namespace std;

void doCode(){
	char day1, day2;
	cout << "Days of week: Mo Tu We Th Fr Sa Su" << "Enter day of week: ";
	cin >> day1 >> day2;

	day1 = toupper(day1);
	day2 = toupper(day2);

	int hours, mins;
	cout << "Enter start time: ";
	cin >> hours;
	cin.ignore(); // ignore colon. this is a bad way to do this
	cin >> mins;
	
	int duration = 0;
	cout << "Enter duration of call in minutes: ";
	cin >> duration;

	float rate;
	// Saturday and Sunday both start with s
	if (day1 == 'S') { 
		// sat & sun special rate 
		rate = 0.15;	
	} else if (8 < hours && hours < 18) { 
		// $0.40 / min from 8:00a to 6:00p  (8:00 to 18:00)
		rate = 0.40;	
	} else {
		rate = 0.25; // default rate of $0.25 / min
	}
	cout << "-----------------\n\nRate: " << rate << endl;
	cout << "Final cost: " << duration * rate << endl;
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
