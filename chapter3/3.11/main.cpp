#include <iostream>
using namespace std;

bool doesntWork(char inp[], int len) {
	for(int i = 0; i < len; i++){
		switch (inp[i]) {
			case '1':
			case '4':
			case '7':
				return true;
		}
	}
	return false;
}

/* char[] fixTime(char inp[], int len, int delta) { */
/* 	char out[len]; */
/* 	for(int i = 0; i < len; i++){ */
/* 		switch (inp[i]) { */
/* 			case '1': */
/* 			case '4': */
/* 			case '7': */
/* 				out[i] = inp[i] + delta; */
/* 		} */
/* 	} */
/* 	return out; */
/* } */
void run(){
	const int len = 3;
	char temp[len];
	cout << "Enter temperature 000-999: ";
	cin >> temp;
	if (doesntWork(temp, 3)) {
		// sets all elements to number
		// + 1 to null terminate string
		char nextHighest[len + 1] = { 0 };	
		char nextLowest[len + 1] = { 0 };	
		bool flag = false;
		for(int i = 0; i < len; i++){
			if (flag) {
				nextHighest[i] = '0';
				nextLowest[i] = '9';
				continue;
			}
			switch (temp[i]) {
				case '1':
				case '4':
				case '7':
					flag = true;
					nextHighest[i] = temp[i] + 1;
					nextLowest[i] = temp[i] - 1;
				break;
				default:
					nextHighest[i] = nextLowest[i] = temp[i];
				break;
			}
		}
		cout << "Next highest: " << nextHighest << endl;
		cout << "Next lowest: " << nextLowest << endl;
	} else {
		cout << "Temperature is valid!\nTemperature: " << temp;
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
