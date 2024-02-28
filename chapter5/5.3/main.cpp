#include <iostream>
using namespace std;

struct time24h {
	int hours;
	int mins;
};

struct time12h {
	int hours;
	int mins;
	char XM;
};

void getTime(struct time12h &time) {
	scanf("%d:%d %cM", &time.hours, &time.mins, &time.XM);
}

void getDuration(struct time24h &time) {
	scanf("%d:%d", &time.hours, &time.mins);
}

time24h convert12hto24h(const struct time12h time) {
	time24h out;
	out.hours = time.hours;
	out.mins = time.mins;
	if (time.XM == 'P' && time.hours != 12) {
		out.hours += 12;
	} else if (time.XM == 'A' && time.hours == 12) {
		out.hours -= 12;
	}
	return out;
}

time12h convert24hto12h(const struct time24h time) {
	time12h out;
	out.mins = time.mins;
	if (time.hours < 12) {
		out.XM = 'A';
		if (time.hours == 0) out.hours = 12;
		return out;
	} else {
		out.XM = 'P';
		if (time.hours != 12) out.hours = time.hours - 12;
		return out;
	}
}

void outputTime(struct time12h &time){
	printf("Final time: %02d:%02d %cM", time.hours, time.mins, time.XM);
}

struct time24h addTimes(struct time24h time1, struct time24h time2) {
	struct time24h out;
	out.hours = time1.hours + time2.hours;
	out.mins  = time1.mins + time2.mins;

	if ( out.mins > 60 ) {
		out.hours++;
		out.mins -= 60;
	}

	if ( out.hours >= 24 ) {
		out.hours -= 24;
	}
	return out;
}	

void doCode(){
	struct time24h start;
	{
		struct time12h start12;
		cout << "Enter start time: ";
		getTime(start12);
		start = convert12hto24h(start12);
	}

	struct time24h wait;
	cout << "Enter wait time: ";
	getDuration(wait);

	struct time24h end = addTimes(start, wait);
	
	time12h output = convert24hto12h(end);
	outputTime(output);
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
