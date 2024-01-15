#include <iostream>
using namespace std;

struct time {
	int hours;
	int mins;
};

void getTime(int &hours, int &mins) {
	cin >> hours;
	cin.ignore(); // ignore colon. this is a bad way to do this
	cin >> mins;
}
void doCode(){
	int hours, mins;
	cout << "Enter start time:\n";
	getTime(hours, mins);

	int waitHours, waitMins;
	cout << "Enter wait time:\n";
	getTime(waitHours, waitMins);

	int finalHours, finalMins;
	finalHours = hours + waitHours;
	finalMins = mins + waitMins;

	if ( finalMins > 60 ) {
		finalHours++;
		finalMins -= 60;
	}

	if ( finalHours > 24 ) {
		finalHours -= 24;
	}

	printf("Final time: %02d:%02d", finalHours, finalMins);
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
