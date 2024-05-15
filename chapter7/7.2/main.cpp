#include <iostream>
using namespace std;

const int HEX_DIGITS = 10;

#define ds(var) cout << #var ": " << var << endl

int digitToVal(char c) {
	switch (c) {
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'a':
			return 10;
		case 'b':
			return 11;
		case 'c':
			return 12;
		case 'd':
			return 13;
		case 'e':
			return 14;
		case 'f':
			return 15;
	}
	return 0;
}

char valToDigit (int n) {
	switch (n) {
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return 'a';
		case 11:
			return 'b';
		case 12:
			return 'c';
		case 13:
			return 'd';
		case 14:
			return 'e';
		case 15:
			return 'f';
	}
	return '0';
}

bool addHex(char hex1[HEX_DIGITS], char hex2[HEX_DIGITS], char result[HEX_DIGITS]) {
	int carry = 0;
	for (int i = 0; i < HEX_DIGITS; i++) {
		int d1, d2;
		d1 = digitToVal(hex1[i]);

		ds(d1);
		d2 = digitToVal(hex2[i]);
		ds(d2);

		int sum = d1 + d2 + carry;

		if (sum > 15) {
			carry = 1;
			sum -= 16;
		} else {
			carry = 0;
		}

		result[i] = valToDigit(sum);
	}
	if (carry) {
		return true;
	}
	return false;
}

void slideHex(char hex[HEX_DIGITS]) {
	int numlen = 0;
	for (int i = 0; i < HEX_DIGITS; i++) {
		if (hex[i] == 0) {
			hex[i] = '0';
			break;
		}
		numlen += 1;
	}

	for (int i = 0; i < numlen; i++) {
		hex[i + (HEX_DIGITS - numlen)] = hex[i];
		hex[i] = '0';
	}
}

void doCode(){
	char hex1[HEX_DIGITS + 1] = {'0'};
	hex1[HEX_DIGITS] = 0;
	char hex2[HEX_DIGITS] = {'0'};
	char result[HEX_DIGITS];
	for (int i = 0; i < HEX_DIGITS; i++) {
		hex1[i] = '0';
		hex2[i] = '0';
		result[i] = '0';
	}
	char buf[HEX_DIGITS] = {'0'};

	int len = 0;
	cout << "Enter first hex number:\n";
	cin >> hex1;
	ds(hex1);
	slideHex(hex1);
	ds(hex1);
	cout << "Enter second hex number:\n";
	cin >> hex2;
	ds(hex1);

	int carry = addHex(hex1, hex2, result);
	if (carry) {
		cout << "Addition Overflow\n";
		return;
	}

	cout << "Result: " << result;
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
