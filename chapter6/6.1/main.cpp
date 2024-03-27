#include <iostream>
#include <fstream>

using namespace std;

void processLetter(istream &input, ostream &output){
	char c;
	input.get(c);
	while (!input.eof()) {
		if (c == '#') {
			input.get(c);
			if (c == 'N') {
				input.get(c);
				if (c == '#') {
					cout << "name matched\n";
					cout << "name? ";
					string name;
					/* cin >> name; */
					getline(cin, name);
					output << name;
				} else {
					// doesn't match, put it back
					input.putback(c);
					output << "#N" << c;
				}
			} else {
				// doesn't match, put it back
				input.putback(c);
				output << '#';
			}

		} else {
			output << c;
		}

		input.get(c);
	}
}
	
int main(){
	ifstream input;
	ofstream output;

	input.open("letter_template.txt");
	output.open("letter_out.txt");

	processLetter(input, output);

	input.close();
	output.close();
}
