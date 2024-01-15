#include <iostream>
using namespace std;

void getTime(int &hours, int &mins) {
	cout << "Enter time:\n";
	cin >> hours;
	cin.ignore(); // ignore colon
	cin >> mins;
}

void convert24hto12h(int &hours, int &mins, char &AMorPM) {
	if (hours < 12) {
		AMorPM = 'A';
		if (hours == 0) hours = 12;
		return;
	} else {
		AMorPM = 'P';
		if (hours != 12) hours -= 12;
		return;
	}
}

void outputTime(int hours, int mins, char AMorPM){
	printf("Converted to 12 hour time: %02d:%02d %cM", hours, mins, AMorPM);
}

void doCode(){
	int hours, mins;
	getTime(hours, mins);
	char AMorPM;
	convert24hto12h(hours, mins, AMorPM);
	outputTime(hours, mins, AMorPM);
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
