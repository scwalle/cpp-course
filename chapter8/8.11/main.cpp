#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

char encodeChar (int key, char input) {
	if ((input + key) > 126) {
		return 32 + (input + key) - 127;
	} else {
		return input + key;	
	}
}

/*
 *
	(input + key) > 126 
 * 	out = 32 + input + key - 127
	(32 + input + key - 127) > 126 + 32 - 127
 *
 */

char decodeChar (int key, char input) {
	if (input - 32 + 127 > 126 ) {
		return input - key - 32 + 127;
	} else {
		return input - key;
	}
}

void decodeStr (int key, string & input, string & output) {
	output.clear();
	for (char c : input) {
		output += decodeChar(key, c);
	}
}

int main(){
	string input = ":mmZ\\dxZmx]Zpgy";
	string output;
	
	bool showall = false;

	cout << " key | message\n---------------\n";
	for (int key = 1; key <= 100; key++) {
		decodeStr(key, input, output);	

		bool print = true;
		for (char c : output) {
			if (!isprint(c)) {
				print = false;
				break;	
			}
		}

		if (print || showall) {
			cout << setw(3) << key << ": " << output << endl;
		}
	}
}
