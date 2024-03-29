#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int countWords(istream &in) {
	char c;
	in.get(c);
	bool inword = false;

	int wc = 0;
	while (!in.eof()) {
		if (isspace(c)) {
			inword = false;
		} else {
			if (!inword) {
				wc++;
			}
			inword = true;
		}
		in.get(c);
	}
	return wc;
}

int main(int argc, char *argv[]){
	ifstream input;
	
	if (argc < 2) {
		cout << "Not enough arguments\n";
		cout << "Usage: " << argv[0] << " filenames\n";
		exit(1);
	}
	const int filesnum = argc - 1;

	for (int i = 1; i < argc; i++) {
		char* fname = argv[i];
		input.open(fname);
		if (input.fail()) {
			cerr << "Can't open file: " << fname << endl;
			exit(1);
		}
		int wc = countWords(input);
		input.close();
		cout << fname << ": " << wc << endl;
	}

	return 0;
}
