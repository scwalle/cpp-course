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

int countWordsAndLetters(istream &input, int lettercounts[26]){
	char c;
	int wordCount = 0;
	int currWord = 0;
	input.get(c);
	while (!input.eof()) {
		if (isalpha(c)) {
			lettercounts[tolower(c) - 'a']++;
		}

		if (!isWordSep(c)) {
			currWord++;
		}
		if (isWordSep(c) && currWord != 0) {
			wordCount++;
			currWord = 0;
		}
		input.get(c);
	}

	return wordCount;
}

	
int main(int argc, char *argv[]){
	int wordcount = 0;
	int lettercounts[26] = {0};

	if (argc > 1) {
		ifstream input;

		input.open(argv[1]);
		if (input.fail()) {
			cerr << "failed to open file '" << argv[1] << "'.\n";
			exit(1);
		}
		wordcount = countWordsAndLetters(input, lettercounts);
		input.close();
	} else {
		wordcount = countWordsAndLetters(cin, lettercounts);
	}
	cout << wordcount << " words" << endl;
	for (int i = 0; i < 26; i++) {
		if (lettercounts[i] == 0) {
			continue;
		}
		cout << lettercounts[i] << " " << (char)(i + 'a') <<  endl;
	}
}
