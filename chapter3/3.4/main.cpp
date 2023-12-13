#include <iostream>
using namespace std;
//TODO make 'a' dynamic, ie it can change later
int getCard() {
	char card;
	cout << "Card: ";
	cin >> card;
	switch (card) {
		case 't':
			return 10; break;
		case 'j':
			return 11; break;
		case 'q':
			return 12; break;
		case 'k':
			return 13; break;
		case 'a':
			return 1; break;
		default:
			if (card >= '2' && card <= '9') {
				return card - '0';
			} else {
				return -1;
			}
		break;
	}
}

void run(){
	int cardNum;
	cout << "Number of cards: ";
	cin >> cardNum;
	cout << endl;
	int score = 0;
	int hand[21] = { 0 };
	for (int i = 0; i < cardNum; i++){
		int card;
		while (true) {
			hand[i] = getCard();
			if (card == -1) {
				cout << "Invalid card" << endl;
				continue;
			} else {
				break;
			}
		} 
		if (card == 1) {
			if (score + 11 <= 21){
				score += 11;
			} else {
				score += 1;
			}
		} else {
			score += card;
		}
	}
	if (score > 21) {
		cout << "Busted!";
	} else {
		cout << score;
	}
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
