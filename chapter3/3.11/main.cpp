#include <iostream>
using namespace std;

bool doesntWork(char inp[], int len) {
	for(int i = 0; i < len; i++){
		switch (inp[i]) {
			case '1':
			case '4':
			case '7':
				return false;
		}
	}
	return true;
}

bool fixTime(char inp[], int len) {
	for(int i = 0; i < len; i++){
		switch (inp[i]) {
			case '1':
			case '4':
			case '7':
				return false;
		}
	}
	return true;
}
void run(){
	char temp[3];
	cout << "Enter temperature 000-999: ";
	cin >> temp;
	doesntWork(temp);
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
