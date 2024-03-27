#include <iostream>
#include <fstream>
using namespace std;

void processStudents(istream &input, ostream &output){
	string lastname, firstname;
	const int numofscores = 10;
	int scores[10] = {0};
	int sum = 0;
	while (!input.eof()) {
		input >> lastname >> firstname;
		for (int i = 0; i < numofscores; i++) {
			input >> scores[i];
		}
		if (input.eof()) {
			break;
		}

		sum = 0;	
		for (int i = 0; i < numofscores; i++) {
			sum += scores[i];
		}
		double average = sum / 10.0;

		output << lastname << ' ' << firstname << ' ';
		for (int i = 0; i < numofscores; i++) {
			output << scores[i];
			output << ' ';
		}
		output << average;
		output << endl;
	}
}
	
int main(){
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt");
	if (input.fail()) {
		cerr << "can't read input file\n";
		exit(1);
	}
	
	processStudents(input, output);

	input.close();
	output.close();
}
