#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define DEBUG 1

#if DEBUG
#define ds(var) cout << #var ": " << var << endl
#else
#define ds(var) ((void)(var))
#endif

const int maxAge = 200;

void readFile(istream & file, double males[], double females[]) {
	while (!file.fail()) {
		int age;
		double maleRate;
		double femaleRate;
		file >> age >> maleRate >> femaleRate;
		
		/* ds(age); */
		/* ds(maleRate); */
		/* ds(femaleRate); */
		males[age] = maleRate;
		females[age] = femaleRate;
	}	
}

void doCode(){
	double males[200];
	double females[200];

	ifstream file;
	file.open("LifeDeathProbability.txt");

	readFile(file, males, females);
	
	int age;
	cout << "Enter age: ";
	cin >> age;

	char sex;
	cout << "Enter sex (m/f): ";
	cin >> sex;

	double prob; // death probability

	while (true) {
		if (age >= 120) {
			break;
		}

		prob = (sex == 'm') ? males[age] : females[age]; // death probability
		cout << "Current probability: " << prob << endl;
		double r = ((double) rand() / (RAND_MAX));
		cout << "generated: " << r << endl;
		if (r > prob) {
			cout << "Survived " << age << endl;
			age++;
		} else {
			break;
		}
	}
	cout << "Simulation ended at age " << age << endl;
	cout << "You will live to age " << age << endl;
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
