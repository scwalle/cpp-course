
#include <iostream>
using namespace std;

/* void num (int &year, int thresh, char *text[]) { */
/* 	if (year <= thresh) { */
/* 		year -= thresh; */
/* 		cout << text; */
/* 	} */
/* } */

#define num(thresh, text) { \
	if (year <= thresh) { \
		year -= thresh; \
		cout << text; \
		continue; \
	} \
} 

void run(){
	int year;
	cout << "Enter year: ";
	cin >> year;
	while (year) {
		num(5, "V")
		num(10, "X")
		num(50, "L")
		num(100, "C")
		num(500, "d")
		num(1000, "M")
	}
}

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	do {
		cout << endl;
		run();

		cout << endl << endl;
		cout << "Run again? (y/n): ";
		char loop;
		cin >> loop;
		if (loop == 'n' || loop == 'N') break;
	} while (true);

	return 0;
}
