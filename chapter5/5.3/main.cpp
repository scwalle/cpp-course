#include <iostream>
using namespace std;

struct time {
	int hours;
	int mins;
	char XM;
};

void getTime(struct time &time) {
	scanf("%d:%d %cM", &time.hours, &time.mins, &time.XM);
}

void getDuration(struct time &time) {
	scanf("%d:%d", &time.hours, &time.mins);
}

void convert24hto12h(struct time &time) {
	if (time.hours < 12) {
		time.XM = 'A';
		if (time.hours == 0) time.hours = 12;
		return;
	} else {
		time.XM = 'P';
		if (time.hours != 12) time.hours -= 12;
		return;
	}
}

void outputTime(struct time &time){
	printf("Final time: %02d:%02d %cM", time.hours, time.mins, time.XM);
}

struct time addTimes(struct time time1, struct time time2) {
	struct time out;
	out.hours = time1.hours + time2.hours;
	out.mins  = time1.mins + time2.mins;

	if ( out.mins > 60 ) {
		out.hours++;
		out.mins -= 60;
	}

	if ( out.hours > 24 ) {
		out.hours -= 24;
	}
	return out;
}	

void doCode(){
	struct time start;
	cout << "Enter start time: ";
	getTime(start);

	struct time wait;
	cout << "Enter wait time: ";
	getDuration(wait);

	struct time end = addTimes(start, wait);

	convert24hto12h(end);
	outputTime(end);
}
	
int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	while(true){
		doCode();
		
		cout << "\n\nTry again? (Ctrl-C to exit, anything else to go again): ";
		string loop = "";
		cin >> loop;
		if (loop == "") return 0;
		cout << endl << endl;
	}
}
