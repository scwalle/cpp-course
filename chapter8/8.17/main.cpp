#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

const int SENSORCOUNT = 3;
struct time24h {
	int hours = -1;
	int mins = -1;
	int secs = -1;
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

bool fasterThan(Racer a, Racer b) {
	return finishTime(a) < finishTime(b);
}

void printRacer(Racer racer) {
	cout << "Racer #" << racer.id << endl;
	for (int i = 0; i < SENSORCOUNT; i++) {
		cout << "Sensor " << i << " time: ";
		outputTime(racer.times[i]);
		cout << endl;
	}
}

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
}

void printSuspicions (Racer r) {
	bool sus = false;
	stringstream out;
	int missedSensor = -1;
	// missed sensor
	for (int i = 0; i < SENSORCOUNT; i++) {
		if (r.times[i].hours == -1) {
			sus = true;
			out << "\t- missed sensor #" << i << endl;
		}
	}

	// fast split
	
	// start at 1 to do pairs, ie. (0,1), (1,2) etc.
	for (int i = 1; i < SENSORCOUNT; i++) {
		if (r.times[i].hours == -1 || r.times[i-1].hours == -1) {
			// only check split if racer passed both sensors
			/* cout << "skipping " << i << "\n"; */
			continue;
		}
			/* cout << "not skipping " << i << "\n"; */
		
		double split = findSplit(r.times[i - 1], r.times[i]) /
			SENSOR_SPACING;
		if (split < (4 + (30/60.0))) { // if faster than 4:30
			out << "\t- sensor #" << i << " split suspiciously fast" << endl;
			sus = true;
		}
	}

	if (sus) {
		cout << "Racer #" << r.id << ":\n";
		cout << out.str();
	}
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

	sort(racers.begin(), racers.end(), fasterThan);

	for (Racer r : racers) {
		/* printRacerFull(r); */
		printSuspicions(r);
	}



	// format:
	// 1st line: gun time in HH MM SS format
	// rest of lines:
	// sensorId,racerId,timeStamp(in HH MM SS)

}
	
int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	doCode();
	/* while(true){ */
	/* 	doCode(); */
		
	/* 	cout << "\nTry again? (Ctrl-C to exit, anything else to go again): "; */
	/* 	string loop = ""; */
	/* 	cin >> loop; */
	/* 	if (loop == "") return 0; */
	/* 	cout << endl << endl; */
	/* } */
}
