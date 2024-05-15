#include <iostream>
using namespace std;

const int boardLen = 9;

enum gameStates {NOWIN=0, XWIN, OWIN, DRAW};

int gameState(int board[]) {
	char win = 0;
	// horizontal
	if (board[0] == board [1] && board[1] == board[2]) win = board[0];
	if (board[3] == board [4] && board[4] == board[5]) win = board[3];
	if (board[6] == board [7] && board[7] == board[8]) win = board[6];

	// vertical
	if (board[0] == board [3] && board[3] == board[6]) win = board[0];
	if (board[1] == board [4] && board[4] == board[7]) win = board[1];
	if (board[2] == board [5] && board[5] == board[8]) win = board[2];

	// diagonal
	if (board[0] == board [4] && board[4] == board[8]) win = board[4];
	if (board[6] == board [4] && board[4] == board[2]) win = board[4];
/* 0 1 2 */
/* 3 4 5 */
/* 6 7 8 */

	return win;
}

void printBoard(int board[]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			switch (board[i*3 + j]) {
				case 'X':
					cout << 'X';
					break;
				case 'O':
					cout << 'O';
					break;
				default:
					cout << (i*3 + j + 1);
					break;
			}
			cout << " ";
		}
		cout << endl;
	}
}

void doCode(){
	int board[boardLen] = {  0, 0, 0,  	
							 0, 0, 0,  	
							 0, 0, 0 };	
	char turn = 'X';
	int turncount = 0;
	while (!gameState(board) && !cin.fail() && turncount < 9) {
		printBoard(board);

promptTurn:
		cout << turn << "'s turn: ";
		int move;
		cin >> move;
		move--;
		/* cout << "move: " << move << endl; */

		if (board[move] != 0) {
			cout << "You can't play there!\n";
			goto promptTurn;
		}

		board[move] = turn;

		turn = (turn == 'X') ? 'O' : 'X';
		turncount++;
	}
	switch (gameState(board)) {
		case 'X':
			cout << "X won!\n";
			break;
		case 'O':
			cout << "O won!\n";
			break;
		default:
			cout << "It's a tie!\n";
	}
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
