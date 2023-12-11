#include <iostream>
using namespace std;

void run(){
	uint num;

	cout << "Number of terms: ";
	cin >> num;
	double pi = 0;
	bool toggle = true;
	for (int i = 0; i < num; i++) {
		/* cout << "Term: " << (2 * i + 1) << endl; */

		if (toggle) {
			pi += (1.0 / (2 * i + 1));
		} else {
			pi -= (1.0 / (2 * i + 1));
		}
		toggle = !toggle;
	}
	pi *= 4;

	cout << pi;
}

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(20);

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
