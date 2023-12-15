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

int calcScore(int cards[], int length){
	int score = 0;
	int aces = 0;
	for (int i = 0; i < length; i++){
		if (cards[i] == 1) {
			//add all aces as 11
			aces += 1;
			score += 11;
		} else {
			score += cards[i];
		}
	}
	//switch aces from 11 to 1 until under 21 or we run out of aces

	while (aces > 0 && score > 21) {
		aces -= 1;
		score -= 10;
	}
	return score;
}

void run(){
	int cardNum;
	cout << "Number of cards: ";
	cin >> cardNum;
	cout << endl;
	int hand[21] = { 0 };
	for (int i = 0; i < cardNum; i++){
		int card;
		while (true) {
			card = getCard();
			if (card == -1) {
				cout << "Invalid card" << endl;
				continue;
			} else {
				hand[i] = card;
				break;
			}
		} 
		int score = calcScore(hand, cardNum);
		cout << "Score: " << score << endl;
		if (score > 21) {
			cout << "Busted!";
			break;
		}
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
