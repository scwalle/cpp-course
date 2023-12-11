#include <iostream>
using namespace std;

void run(){
	cout << "Hello World!";
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
