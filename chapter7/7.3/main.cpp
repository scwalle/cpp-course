#include <iostream>
using namespace std;


void shift_array(char array[], int pos, int length) {
	for (int i = pos+1; i < length; i++) {
		array[i-1] = array[i];
	}
	array[length-1] = 0;
}

void delete_repeats(char array[], int &size) {
	const int letter_num = 26;
	int letters[letter_num];
	for (int i = 0; i < letter_num; i++) {
		letters[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		/* cout << (i) << endl; */
		/* cout << (array[i]) << endl; */
		/* cout << "(letters[ array[i] ]): " << (letters[ array[i] - 'a' ]) << endl; */
		if (letters[array[i] - 'a']) {
			/* cout << "seen!\n"; */
			array[i] = '0';
			/* cout << array << endl; */
			shift_array(array, i, size);
			size--;
			i--; // current letter changed, so go back to not miss it
		} else {
			letters[array[i] - 'a'] = 1;
		}
	}
}

void doCode(){
	int size;
	cout << "Enter array size:";
	cin >> size;
	char array[size+1];
	array[size] = 0;
	for (int i = 0; i < size; i++) {
		cout << "Element " << i << ":";
		cin >> array[i];
	}
	cout << endl;
	cout << "array: " << array << "\n";
	delete_repeats(array, size);
	/* shift_array(array, 0, size); */
	cout << "array: " << array << "\n";

}
	
int main(int argc, char *argv[]){
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
