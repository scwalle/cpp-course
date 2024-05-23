#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int SENSORCOUNT = 3;
struct time24h {
	int hours;
	int mins;
	int secs;
};

const double DISTANCE = 13.1;
const double SENSOR_SPACING = DISTANCE / (SENSORCOUNT - 1);

struct Racer {
	time24h times[3];
	int id;
};

void outputTime(struct time24h &time){
	printf("%02d:%02d:%02d", time.hours, time.mins, time.secs);
}


int findRacer(vector<Racer> list, int id) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i].id == id) {
			return i;
		}
	}
	return -1;
}

double toMinutes(time24h time) {
	double mins = 0;
	mins += time.hours * 60;
	mins += time.mins;
	mins += (time.secs / 60.0);
	return mins;
}

double findSplit(time24h start, time24h end) {
	return toMinutes(end) - toMinutes(start);
}

// returns time it took to finish race in mins
double finishTime(Racer r) {
	time24h start = r.times[0];
	time24h end = r.times[SENSORCOUNT - 1];
	return findSplit(end, start);
}

bool slowerThan(Racer a, Racer b) {
	return (finishTime(a) > finishTime(b));
}

void printRacer(Racer racer) {
	cout << "Racer #" << racer.id << endl;
	for (int i = 0; i < SENSORCOUNT; i++) {
		cout << "Sensor " << i << " time: ";
		outputTime(racer.times[i]);
		cout << endl;
	}
}

time24h subtractTimes(time24h start, time24h end) {
	int hours, mins, secs;		
	hours = end.hours - start.hours;
	mins = end.mins - start.mins;
	secs = end.secs - start.secs;
	if (secs < 0) {
		secs += 60;
		mins--;
	}
	if (mins < 0) {
		mins += 60;
		hours--;
	}
	time24h out = {hours, mins, secs};
	return out;
};

void printRacerFull(Racer racer) {
	cout << "Racer #" << racer.id << endl;
	for (int i = 0; i < SENSORCOUNT; i++) {
		cout << "Sensor " << i << " time: ";
		outputTime(racer.times[i]);
		if (i != 0) {
			cout << "  Split: " 
				<< (findSplit(racer.times[i-1], racer.times[i]) / SENSOR_SPACING)
				<< " mins/mile";
		}
		cout << endl;
	}
	cout << endl;
	time24h start, end;
	start = racer.times[0];
	end = racer.times[2];
	time24h diff = subtractTimes(start, end);	

	cout << "Overall finish time: ";
	outputTime(diff);
	cout << endl;

	cout << "Overall race pace: " << (toMinutes(diff) / DISTANCE) << " mins/mile\n";
}

void doCode(){
	vector<Racer> racers;
	time24h gunTime;

	ifstream input;
	input.open("sensordata.txt");

	input >> gunTime.hours >> gunTime.mins >> gunTime.secs;

	while (!input.fail()) {
		int sensor, racerId;	
		Racer racer;
		char comma;



		input >> sensor >> comma 
			  >> racerId >> comma;

		int racerIndex = findRacer(racers, racerId);
		if (racerIndex == -1) {
			racers.push_back(racer);
			racerIndex = racers.size()-1;
			racer.id = racerId;
		} else {
			racer = racers[racerIndex];
		}

		time24h *time = &racer.times[sensor];

		input >> time->hours >> time->mins >> time->secs;
		/* racer.times[sensor] = time; */


		racers[racerIndex] = racer;
		/* printRacer(racer); */
	}
	input.close();
	/* cout << "----------------------------\n"; */

	sort(racers.begin(), racers.end(), slowerThan);

	/* for (Racer r : racers) { */
	/* 	printRacerFull(r); */
	/* } */

	int racerNum;
	cout << "Enter racer number: ";
	cin >> racerNum;
	int index = findRacer(racers, racerNum);
	if (index == -1) {
		cout << "Invalid racer number.\n";
		return;
	}
	Racer r = racers[index];

	cout << endl;
	printRacerFull(r);

	int place = index + 1;
	cout << "\nRacer placed " << place
		<< ((place == 1) ? "st" 
				: ( (place == 2) ? "nd"
				   : ((place == 3) ? "rd" 
					   : "th"
					   )
				  )
			)
		<< endl;


	// format:
	// 1st line: gun time in HH MM SS format
	// rest of lines:
	// sensorId,racerId,timeStamp(in HH MM SS)

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
