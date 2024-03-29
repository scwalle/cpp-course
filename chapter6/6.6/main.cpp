#include <iostream>
#include <fstream>
using namespace std;

const int NUMBER_OF_CHAPTERS = 18;

void printWisdom(ifstream &wisdom);
void new_line(istream& in_stream = cin);

const string WISDOM_FILE = "wisdom.txt";
int main() {
	ifstream input;
	input.open(WISDOM_FILE);
	if (input.fail()) {
		cerr << "can't read input file\n";
		exit(1);
	}
	
	cout << "What is your question? ";	
	new_line(cin);
	while (!cin.eof()) {
		printWisdom(input);
		cout << endl;
		cout << "What is your question? ";	
		new_line();
	}


	input.close();
}

void printWisdom(ifstream &wisdom){
	static int chapternum = NUMBER_OF_CHAPTERS;
	char c;
	wisdom.get(c);
	while (c != '\n' && !wisdom.eof()) {
		if (c == '#') {
			// matched "#"
			wisdom.get(c);
			if (c == 'N') {
				// matched "#N"
				cout << chapternum;
			} else {
				cout << '#' << c;
			}
		} else {
			cout.put(c);
		}
		wisdom.get(c);
	}

	if (wisdom.eof()) {
		wisdom.close();
		wisdom.open(WISDOM_FILE);

		chapternum--;
		if (chapternum == 0) {
			chapternum = NUMBER_OF_CHAPTERS;
		}

		printWisdom(wisdom);
	}
}

void new_line(istream& in_stream)
{
	char symbol;
	do
	{
		in_stream.get(symbol);
	} while (symbol != '\n' && !in_stream.eof());
}
