#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int PINLEN = 5;
const char pin[] = {1, 2, 3, 4, 5};

void printArr(int pin[], int len) {
	for (int i = 0; i < len; i++) {
		cout << pin[i] << ' ';
	}
	cout << endl;
}

void translate(const char code[], const char input[], const int len, char output[]) {
	for (int i = 0; i < len; i++) {
		output[i] = code[input[i]];
		/* cout << output[i] << endl; */
	}
	output[len] = 0;
}

void doCode(){

	cout << "Digit in pin: ";
	for (int i = 0; i < 10; i++) {
		cout << i << ' ';
	}
	cout << endl;

	char code[10];
	srand(time(0));
	
	cout << "Digit typed:  ";
	for (int i = 0; i < 10; i++) {
		code[i] = (rand() % 3) + '1';
		cout << code[i] << ' ';
	}
	cout << endl;

	char pinStr[10];
	cout << "Enter pin: ";
	cin >> pinStr;

	char translated[10];
	translate(code, pin, 5, translated); 
	/* cout << translated << endl; */
	if (strcmp(pinStr, translated) == 0) {
		cout << "Correct!\n";
	} else {
		cout << "Wrong! >:3\n";
	}
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
