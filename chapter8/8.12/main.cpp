#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ios>
using namespace std;

#define ds(var) cout << #var ": " << var << endl

struct time24h {
	int hours;
	int mins;
};

struct time12h {
	int hours;
	int mins;
	char XM;
};

void getTime(string timestr, struct time12h &time) {
	sscanf(timestr.c_str(), "%d:%d %cM", &time.hours, &time.mins, &time.XM);
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

void outputTime(struct time24h &time){
	printf("Final time: %02d:%02d hours", time.hours, time.mins);
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

string toMilitary(string time) {
	struct time12h time12;
	getTime(time, time12);

	struct time24h time24;
	time24 = convert12hto24h(time12);
	/* outputTime(time24); */

	stringstream out;
	out << setw(2) << setfill('0') << time24.hours << time24.mins << " hours";

	/* outputTime(output); */
	/* ds(mins); */
	/* ds(buf); */
	/* ds(hrs); */
	/* ds(XM); */

	return out.str();
}

void doCode(){
	string time;
	cout << "Enter time: ";
	getline(cin, time);
	string out = toMilitary(time);
	cout << endl << out << endl;
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
