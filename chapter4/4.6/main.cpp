#include <iostream>
using namespace std;

#define DEBUG 0

const float COST = 3.50;

double getCoin(){
	do {
		int input;
		cout << "Select a coin: \n";
		cout << "	1) Dollar\n";
		cout << "	2) Quarter\n";
		cout << "	3) Dime\n";
		cout << "	4) Nickel\n";
		cout << endl << "Selection: ";
		cin >> input;
		switch (input) {
			case 1:
				return 1.00;
			break;
			case 2:
				return 0.25;
			break;
			case 3:
				return 0.10;
			break;
			case 4:
				return 0.05;
			break;
			default:
				cout << "Invalid coin\n";
			break;
		}
	} while (true);
}

void run(){
	cout << "Cost of a Deep Fried Twinkie: " << COST << endl;

	float total = 0;
	while (total < COST) {
		cout << "Total: " << total << endl
			 << "Need: " << COST - total << endl;
		total += getCoin();
	}

	float change = 0;
	if ( total > COST ) {
		change = total - COST;
	}

	cout << endl;
	cout << "Total: " << total << endl;
	cout << "Change: " << change << endl;
	cout << "Enjoy your deep-fried twinkie\n";
}

int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

#if DEBUG

	float coin = getCoin();
	cout << "result: " << coin << endl;	

#else
	do {
		cout << endl;
		run();

		cout << endl << endl;
		cout << "Run again? (y/n): ";
		char loop;
		cin >> loop;
		if (loop == 'n' || loop == 'N') break;
	} while (true);
#endif
	return 0;
}
