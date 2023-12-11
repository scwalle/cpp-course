#include <iostream>
#include <string>
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

const string letters[] = { 
	"M", "CM", "d", "Cd",
	"C", "XC", "L", "XL",
	"X", "iX", "V", "iV",
	"i"
};
const int lookupValues[] = { 
	1000, 900, 500, 400,
	100,  90,  50,  40,
	10,   9,   5,   4,
	1
};

void run(){
	int year;
	cout << "Enter year: ";
	cin >> year;
	int i = 0;
	while(year) {
		while(year >= lookupValues[i]){
			year -= lookupValues[i];
			cout << letters[i];      
		}
		i++;
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
