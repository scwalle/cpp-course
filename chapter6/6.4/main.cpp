#include <iostream>
#include <fstream>

using namespace std;

bool isWordSep (char c) {
	switch (c) {
		case ' ':
		case '.':
		case ',':
		case '\n':
			return true;
			break;
		default:
			return false;
	}
}

double computeAverageWord(istream &input){
	char c;
	int charCount = 0;
	int wordCount = 0;
	int currWord = 0;
	input.get(c);
	while (!input.eof()) {
		if (!isWordSep(c)) {
			currWord++;
		}
		if (isWordSep(c) && currWord != 0) {
			wordCount++;
			charCount += currWord;
			currWord = 0;
		}
		input.get(c);
	}
	return ((double) charCount) / ((double) wordCount);
}

	
int main(int argc, char *argv[]){
	double avglen;
	if (argc > 1) {
		ifstream input;

		input.open(argv[1]);
		if (input.fail()) {
			cerr << "failed to open file '" << argv[1] << "'.\n";
			exit(1);
		}
		avglen = computeAverageWord(input);
		input.close();
	} else {
		avglen = computeAverageWord(cin);
	}
	cout << "Average word length: " << avglen << endl;
}
